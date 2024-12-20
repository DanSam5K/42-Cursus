/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:14:49 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/14 11:37:10 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*dst;
	unsigned char	*ptr;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	total_size = size * count;
	dst = malloc(total_size);
	if (dst == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (dst);
}
