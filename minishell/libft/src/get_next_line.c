/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:55 by dsamuel           #+#    #+#             */
/*   Updated: 2024/10/30 15:44:39 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	initialize_line_check(int fd, char **line, char *buf)
{
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	return (1);
}

static int	process_newline_check(char **line, char **stock, int read_len)
{
	if (newline_check(*stock, read_len) == 2)
	{
		*line = *stock;
		return (-2);
	}
	*line = get_line(*stock);
	if (*line == NULL)
		return (-1);
	*stock = stock_trim(*stock);
	if (*stock == NULL)
	{
		ft_memdel(*stock);
		return (-1);
	}
	if (read_len != 0)
		return (1);
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_len;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;

	if (initialize_line_check(fd, line, buf) == -1)
		return (-1);
	read_len = 1;
	while (!newline_check(stock, read_len))
	{
		read_len = handle_read(fd, &stock, buf);
		if (read_len == -1)
			return (-1);
	}
	return (process_newline_check(line, &stock, read_len));
}
