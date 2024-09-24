/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:57:50 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/24 11:25:11 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	if (ft_strlen(s) < start)
// 		return (ft_strdup(""));
// 	substr = (char *)malloc(len + 1);
// 	if (!substr)
// 		return (0);
// 	i = 0;
// 	while (s[start] && i < len)
// 		substr[i++] = s[start++];
// 	substr[i] = '\0';
// 	return (substr);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*s == (char)c)
// 		return ((char *)s);
// 	return (0);
// }


char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

// int main(void)
// {
// 	char *s1 = "  Hello, World!  ";
// 	char *set = " ";
// 	char *s2 = ft_strtrim(s1, set);
// 	printf("%s\n", s2);
// 	return (0);
// }
