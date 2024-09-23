/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:57:10 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/23 22:38:18 by dansam           ###   ########.fr       */
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

static char	*ft_str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = ft_str_new(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}

// char	ft_print_strmapi(unsigned int index, char c)
// {
// 	printf("index: %d, char: %c\n", index, c);
// 	return (c);
// }

// int main(void)
// {
// 	char *s = "Hello, World!";
// 	char *new_s = ft_strmapi(s, ft_print_strmapi);
// 	printf("%s\n", new_s);
// 	return (0);
// }
