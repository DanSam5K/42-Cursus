/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:49:25 by dsamuel           #+#    #+#             */
/*   Updated: 2024/10/17 21:47:39 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

// for testing purposes only
// implementation of ft_strlen
// int main(void)
// {
// 	t_list *head = ft_lstnew(ft_strdup("Hello"));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("World")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("42")));
// 	printf("head->content: %s\n", (char *)head->content);
// 	ft_lstclear(&head, free);
// 	return (0);
// }
