/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:14:45 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/25 17:30:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_read;
	static int	buffer_index;
	int			line_index;
	
	line_index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_index >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_index] == '\n')
			break ;
		line[line_index++] = buffer[buffer_index++];
		line_index++;
	}
	line[line_index] = '\0';
	if (line_index == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main()
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
