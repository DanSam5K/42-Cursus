/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:14 by dsamuel           #+#    #+#             */
/*   Updated: 2025/02/20 14:40:48 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memset fills the first len bytes of the memory area
	pointed	to by b with the byte c. Both b and c are interpreted as 
	unsigned char.

	RETURN VALUE :
	A pointer to memory area s.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)b;
	ch = c;
	while (len--)
	{
		*p = ch;
		p++;
	}
	return (b);
}
