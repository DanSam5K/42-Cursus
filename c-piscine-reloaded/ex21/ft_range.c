/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:46:52 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/07 11:41:21 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	range_size;
	int	*range_array;
	int	i;

	if (min >= max)
		return (NULL);
	range_size = max - min;
	range_array = (int *)malloc(range_size * sizeof(int));
	if (range_array == NULL)
		return (NULL);
	i = 0;
	while (i < range_size)
	{
		range_array[i] = min + i;
		i++;
	}
	return (range_array);
}
