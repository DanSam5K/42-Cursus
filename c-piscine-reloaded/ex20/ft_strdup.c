/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:38:52 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/07 11:41:37 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*duplicate;
	size_t	i;

	len = ft_strlen(src);
	duplicate = (char *)malloc(len + 1);
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		duplicate[i] = src[i];
		i++;
	}
	return (duplicate);
}
