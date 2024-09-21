/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:30:26 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/21 16:58:56 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

// void ft_print_striteri(unsigned int index, char *c)
// {
// 	printf("index: %d, char: %c\n", index, *c);
// }

// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	ft_striteri(str, ft_print_striteri);
// 	return (0);
// }
