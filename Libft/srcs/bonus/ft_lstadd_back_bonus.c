/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:34:44 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/24 11:49:30 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

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

// int main(void)
// {
// 	t_list *lst = ft_lstnew(ft_strdup("first"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("third")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("fourth")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("fifth")));
// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }