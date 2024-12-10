/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:23:45 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 18:14:55 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <linux/limits.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7
# define HERE_DOC 8

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_CMD 127
# define MAX_HISTORY 100

/*
** Structure for storing a command token (e.g., a command, argument, pipe, etc.).
*/
typedef struct s_cmd_token
{
	char				*content;
	int					type;
	struct s_cmd_token	*prev;
	struct s_cmd_token	*next;
}				t_cmd_token;

/*
** Structure for storing an environment variable.
*/
typedef struct s_env_variable
{
	char					*variable;
	struct s_env_variable	*next;
}				t_env_variable;

/*
** Structure for storing the shell state.
*/
typedef struct s_shell_state
{
	t_cmd_token		*cmd_list;
	t_env_variable	*active_env;
	t_env_variable	*secret_env;
	int				stdin_fd;
	int				stdout_fd;
	int				input_fd;
	int				output_fd;
	int				pipe_input_fd;
	int				pipe_output_fd;
	int				proc_id;
	int				is_foreground;
	int				is_parent_proc;
	int				last_exit_stat;
	int				return_code;
	int				should_exit;
	int				should_skip_exec;
	int				history_count;
	char			*history[MAX_HISTORY];
	char			*tilde;
	int				here_doc_triggered;
}				t_shell_state;

/*
** Structure for storing signal handling data.
*/
typedef struct s_sig_handler
{
	int				sigint_received;
	int				sigquit_received;
	int				last_exit_stat;
	int				print_prompt;
	pid_t			child_proc_id;
}				t_sig_handler;

/*
** Structure for storing data related to command execution.
*/
typedef struct s_expand_data
{
	char			*expanded_str;
	int				src_index;
	int				dest_index;
}				t_expand_data;

/*
** BUILTINS
*/
int			ft_cd(char **args, t_shell_state *shell_state);
char		*ft_get_env_path(t_env_variable *env, const char *var, size_t len);
int			ft_echo(char **args);
int			ft_env(t_env_variable *env);
void		ft_mini_exit(t_shell_state *shell_state, char **cmd_args);
int			ft_add_to_env(const char *args, t_env_variable *env);
char		*ft_get_env_name(char *dest, const char *src);
int			ft_is_in_env(t_env_variable *env, char *args);
int			ft_export(char **args, t_env_variable *env, t_env_variable *secret);
int			ft_pwd(void);
int			ft_unset(char **args, t_shell_state *state);

/*
** PARSING
*/
char		*ft_expansions(char *arg, t_env_variable *env, int ret);
void		ft_handle_delimited_warning(char *delimiter);
char		*ft_expand_variable(const char *input_line,
				int *index, t_shell_state *shell_state);

char		*ft_space_alloc(char *line);
char		*ft_space_line(char *line);
int			ft_quote_check(t_shell_state *shell_state, char **line);
int			ft_parse_input(t_shell_state *shell_state);

void		ft_type_arg(t_cmd_token *token, int separator);
void		ft_squish_args(t_shell_state *shell_state);
int			ft_next_alloc(char *line, int *i);
t_cmd_token	*ft_next_token(char *line, int *i);
t_cmd_token	*ft_get_tokens(char *line);
void		ft_squish_helper(t_shell_state *shell_state,
				t_cmd_token *token, t_cmd_token *prev);
t_cmd_token	*ft_finalize_token_list(t_cmd_token *last_token);

/*
** EXECUTOR
*/
int			ft_is_builtin(char *command);
int			ft_exec_builtin(char **args, t_shell_state *shell_state);

int			ft_error_message(char *path);
int			ft_magic_box(char *path, char **args, t_env_variable *env,
				t_shell_state *shell_state);
char		*ft_path_join(const char *s1, const char *s2);
char		*ft_check_dir(char *bin, char *command);
int			ft_exec_bin(char **args, t_env_variable *env,
				t_shell_state *shell_state);

char		**ft_cmd_tab(t_cmd_token *start);
void		ft_exec_cmd(t_shell_state *shell_state, t_cmd_token *token);

/*
** ENVIRONMENT
*/
size_t		ft_size_env(t_env_variable *lst);
char		*ft_env_to_str(t_env_variable *lst);
int			ft_env_init(t_shell_state *shell_state, char **env_array);
int			ft_secret_env_init(t_shell_state *shell_state, char **env_array);
int			ft_is_env_char(int c);
int			ft_is_valid_env(const char *env);
int			ft_env_value_len(const char *env);
char		*ft_env_value(char *env);
char		*ft_get_env_value(char *arg, t_env_variable *env);
int			ft_str_env_len(char **env);
void		ft_sort_env(char **tab, int env_len);
void		ft_print_sorted_env(t_env_variable *env);
void		ft_increment_shell_level(t_env_variable *env);

/*
** RE_DIRECTIONS
*/
void		ft_redir(t_shell_state *shell_state, t_cmd_token *token, int type);
void		ft_input(t_shell_state *shell_state, t_cmd_token *token);
int			ft_mini_pipe(t_shell_state *shell_state);

/*
** SIGNALS HANDLING
*/
void		ft_sig_integer(int sig_nal);
void		ft_sig_exit(int sig_nal);
void		ft_sig_init(void);

/*
** UTILS FUNCTIONS
*/
int			ft_is_type(t_cmd_token *token, int type);
int			ft_is_types(t_cmd_token *token, char *types);
int			ft_has_pipe(t_cmd_token *token);

t_cmd_token	*ft_next_sep(t_cmd_token *token, int skip);
t_cmd_token	*ft_prev_sep(t_cmd_token *token, int skip);
t_cmd_token	*ft_next_run(t_cmd_token *token, int skip);

int			ft_is_sep(char *line, int i);
int			ft_ignore_sep(char *line, int i);
int			ft_quotes(char *line, int index);
int			ft_is_last_valid_arg(t_cmd_token *token);
int			ft_check_line(t_shell_state *shell_state, t_cmd_token *token);

void		ft_free_token(t_cmd_token *start);
void		ft_free_env(t_env_variable *env);
void		ft_free_tab(char **tab);
int			ft_clear(void);

void		ft_close(int fd);
void		ft_reset_std(t_shell_state *shell_state);
void		ft_close_fds(t_shell_state *shell_state);
void		ft_reset_fds(t_shell_state *shell_state);
char		*ft_expand_character(char c);
char		*ft_handle_expansion(const char *input_line,
				int *i, t_shell_state *shell_state);

int			ft_ret_size(int ret);
int			ft_get_var_len(const char *arg, int pos,
				t_env_variable *env, int ret);
int			ft_arg_alloc_len(const char *arg, t_env_variable *env, int ret);
char		*ft_get_var_value(const char *arg, int pos,
				t_env_variable *env, int ret);
int			ft_execute_command(char *path, char **args, t_env_variable *env, \
			t_shell_state *shell_state);

/*
** HISTORY
*/
void		ft_my_add_history(const char *command, t_shell_state *shell_state);
int			ft_print_history(t_shell_state *shell_state);
void		ft_free_history(t_shell_state shell_state);

/*
** HERE_DOC AND UTILS
*/
void		ft_here_doc(t_shell_state *shell_state, t_cmd_token *token);
void		ft_hd_sig_handler(int sig_nal);
char		*ft_strrstr(const char *haystack, const char *needle);
char		*ft_getenv(const char *var_name, t_env_variable *env);
char		*ft_strjoin_free(char *s1, const char *s2);
int			ft_is_quoted_delimiter(char *delimiter, t_shell_state *shell_state);

/*
** External functions
*/
extern t_sig_handler	g_global_sig;

#endif
