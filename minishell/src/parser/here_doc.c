/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:45:39 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:04:19 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_input_line(char *input_line, t_shell_state *shell_state)
{
	char	*expanded_line;
	char	*expanded_segment;
	int		i;

	expanded_line = ft_strdup("");
	i = 0;
	while (input_line[i])
	{
		expanded_segment = ft_handle_expansion(input_line, &i, shell_state);
		expanded_line = ft_strjoin_free(expanded_line, expanded_segment);
		free(expanded_segment);
		i++;
	}
	return (expanded_line);
}

static char	*ft_process_input_line(char *input_line,
	char *delimiter, t_shell_state *shell_state)
{
	if (ft_is_quoted_delimiter(delimiter, shell_state))
		return (ft_strdup(input_line));
	return (ft_expand_input_line(input_line, shell_state));
}

static void	ft_here_doc_routine(char *delimiter, int temp_fd,
	t_shell_state *shell_state)
{
	char	*input_line;
	char	*expanded_line;

	signal(SIGINT, ft_hd_sig_handler);
	while (1)
	{
		input_line = readline("> ");
		if (!input_line)
		{
			ft_handle_delimited_warning(delimiter);
			break ;
		}
		if (ft_strcmp(input_line, delimiter) == 0)
		{
			free(input_line);
			break ;
		}
		expanded_line = ft_process_input_line(input_line,
				delimiter, shell_state);
		ft_putendl_fd(expanded_line, temp_fd);
		free(input_line);
		free(expanded_line);
	}
	signal(SIGINT, SIG_DFL);
}

static void	ft_here_doc_parent(t_shell_state *shell_state, pid_t child_pid)
{
	int	signal_code;
	int	status;

	waitpid(child_pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		signal_code = WTERMSIG(status);
		if (signal_code == SIGINT)
		{
			shell_state->return_code = 130;
			shell_state->should_skip_exec = 1;
			return ;
		}
	}
	else if (WIFEXITED(status))
		shell_state->return_code = WEXITSTATUS(status);
	shell_state->input_fd = open("libft/o", O_RDONLY);
	if (shell_state->input_fd == -1)
	{
		perror("Error opening temporary file for here-doc");
		return ;
	}
	dup2(shell_state->input_fd, STDIN_FILENO);
	ft_close(shell_state->input_fd);
}

void	ft_here_doc(t_shell_state *shell_state, t_cmd_token *token)
{
	char	*delimiter;
	int		temp_fd;
	pid_t	child_pid;

	g_global_sig.print_prompt = 1;
	delimiter = token->content;
	child_pid = fork();
	if (child_pid == 0)
	{
		temp_fd = open("libft/o", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (temp_fd == -1)
		{
			perror("Error creating temporary file for here-doc");
			exit(1);
		}
		ft_here_doc_routine(delimiter, temp_fd, shell_state);
		close(temp_fd);
		exit(0);
	}
	else if (child_pid > 0)
		ft_here_doc_parent(shell_state, child_pid);
	else
		perror("Error forking here-doc process");
}
