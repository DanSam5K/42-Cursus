/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:53:26 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/30 19:42:14 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

// // implementation of ft_strlen
// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// // // implementation of ft_strdup
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

// // t list add back
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
// 	t_list	*head;
// 	t_list	*new;

// 	head = ft_lstnew(ft_strdup("Hello"));
// 	new = ft_lstnew(ft_strdup("World"));
// 	ft_lstadd_back(&head, new);
// 	ft_lstdelone(new, free);
// 	while (head)
// 	{
// 		printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }
