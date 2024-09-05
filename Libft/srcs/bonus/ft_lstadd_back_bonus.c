/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:34:44 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/05 22:53:16 by dansam           ###   ########.fr       */
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

int main(void)
{
	t_list *lst = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("third")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("fourth")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("fifth")));
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}