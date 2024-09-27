/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:05:25 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/27 15:37:18 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// all commented code is for testing purposes only
// // implementation of ft_strlen
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

// add item to back of list
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

// int main(void)
// {
// 	t_list *head = ft_lstnew(ft_strdup("Hello"));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("World")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("42")));
// 	ft_lstclear(&head, free);
// 	if (!head)
// 		printf("List is empty\n");
// 	else
// 		printf("List is not empty\n");
	
// 	return (0);
// }
