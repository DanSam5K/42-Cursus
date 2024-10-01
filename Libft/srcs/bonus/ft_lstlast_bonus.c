/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:25:59 by dsamuel           #+#    #+#             */
/*   Updated: 2024/10/02 00:02:45 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

// // for testing purposes only
// implementation of ft_strlen
// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// // implementation of ft_strdup
// char	*ft_strdup(const char *src)
// {
// 	char	*dest;
// 	size_t	i;

// 	dest = (char *)malloc(ft_strlen(src) + 1);
// 	if (!dest)
// 		return (0);
// 	i = 0;
// 	while (src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*head;

// 	head = malloc(sizeof(t_list));
// 	if (!head)
// 		return (NULL);
// 	head->content = content;
// 	head->next = NULL;
// 	return (head);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp;

// 	if (!lst || !new)
// 		return ;
// 	if (!(*lst))
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	temp = *lst;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new;
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = temp;
// 	}
// }

// // putstr_fd
// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	write(fd, s, ft_strlen(s));
// }

// int main()
// {
// 	t_list	*head;
// 	t_list	*new;

// 	head = ft_lstnew(ft_strdup("Hello, "));
// 	new = ft_lstnew(ft_strdup("World!"));
// 	ft_lstadd_front(&head, new);
// 	while (head)
// 	{
// 		ft_putstr_fd(head->content, 1);
// 		head = head->next;
// 	}
// 	ft_lstclear(&head, free);
// 	return (0);
// }
