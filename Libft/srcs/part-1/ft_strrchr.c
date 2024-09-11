/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:01:32 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/06 22:38:27 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last_occurrence;
	unsigned char	uc;

	last_occurrence = NULL;
	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
		{
			last_occurrence = s;
		}
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
