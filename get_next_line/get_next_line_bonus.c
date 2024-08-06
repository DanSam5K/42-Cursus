/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:34:21 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/19 15:31:53 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * Polish linked list for next call
*/
void	ft_polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	if (NULL == *list)
		return ;
	last_node = ft_find_last_node(*list);
	if (last_node == NULL)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node, buf);
}

/*
 * Get my (line\n]
*/
char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = ft_len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	ft_copy_str(list, next_str);
	return (next_str);
}

/*
 * append one node
 * to the end of list
*/
void	ft_append(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_find_last_node(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	ft_create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_found_newline(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			if (char_read < 0)
				ft_dealloc(&list[fd], NULL, NULL);
			return ;
		}
		buf[char_read] = '\0';
		ft_append(list, buf, fd);
	}
}

/*
 * Main function
 * 	~Takes a file descriptor
 * 	~Gives back the next_string
*/
char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || fd >= 4095 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		if (fd >= 0 && fd < 4095)
			ft_dealloc(&list[fd], NULL, NULL);
		return (NULL);
	}
	ft_create_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = ft_get_line(list[fd]);
	ft_polish_list(&list[fd]);
	return (next_line);
}
