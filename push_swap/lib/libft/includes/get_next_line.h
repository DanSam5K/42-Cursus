/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:46:12 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/09 20:19:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

int		ft_found_newline(t_list *list);
char	*ft_get_line(t_list *list);
t_list	*ft_find_last_node(t_list *list);
void	ft_copy_str(t_list *list, char *str);
int		ft_len_to_newline(t_list *list);
void	ft_polish_list(t_list **list);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf);
void	ft_create_list(t_list **list, int fd);

char	*get_next_line(int fd);

#endif
