/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:31:56 by dsamuel           #+#    #+#             */
/*   Updated: 2024/10/04 20:37:30 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*mapped_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		mapped_lst = f(lst->content);
		new_node = ft_lstnew(mapped_lst);
		if (!new_node)
		{
			del(mapped_lst);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// static t_list	*ft_lst_new(void *content)
// {
// 	t_list	*head;

// 	head = malloc(sizeof(t_list));
// 	if (!head)
// 		return (NULL);
// 	head->content = content;
// 	head->next = NULL;
// 	return (head);
// }

// static void	ft_lst_clear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = temp;
// 	}
// 	*lst = NULL;
// }

// static void	ft_lst_add_back(t_list **lst, t_list *new)
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
// 	t_list *new_head = ft_lstmap(head, &ft_strdup, &free);
// 	ft_lstclear(&head, &free);
// 	ft_lstclear(&new_head, &free);
// 	return (0);
// }