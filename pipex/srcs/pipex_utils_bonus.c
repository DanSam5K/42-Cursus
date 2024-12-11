/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:05:56 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/19 16:25:19 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_usage(void)
{
	ft_putstr_fd("\033[31mError: Invalid arguments\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex file1 cmd1 cmd2 <...> file2\n", 1);
	ft_putstr_fd("./pipex \"here_doc\" TERMINATOR cmd1 cmd2 ... file\n", 2);
	exit(EXIT_SUCCESS);
}

int	ft_open_file(char *file_name, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (mode == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (mode == 2)
		fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
		ft_error();
	return (fd);
}

int	ft_get_next_line(char **output_line)
{
	char	*buffer;
	char	tmp_char;
	int		bytes_read;
	int		buf_index;

	buf_index = 0;
	bytes_read = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	bytes_read = read(0, &tmp_char, 1);
	while (bytes_read && tmp_char != '\n' && tmp_char != '\0')
	{
		if (tmp_char != '\n' && tmp_char != '\0')
			buffer[buf_index] = tmp_char;
		buf_index++;
		bytes_read = read(0, &tmp_char, 1);
	}
	buffer[buf_index] = '\n';
	buffer[++buf_index] = '\0';
	*output_line = buffer;
	free(buffer);
	return (bytes_read);
}
