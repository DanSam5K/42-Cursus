/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:33:01 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/24 11:30:02 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*allocate_and_copy(const char *s, size_t start, size_t max_len)
{
	char	*new_str;
	size_t	i;

	new_str = (char *)malloc(max_len + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (i < max_len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[max_len] = '\0';
	return (new_str);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	max_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (allocate_and_copy("", 0, 0));
	if (s_len - start < len)
		max_len = s_len - start;
	else
		max_len = len;
	return (allocate_and_copy(s, start, max_len));
}

// int main(void)
// {
// 	char *s = "Hello, World!";
// 	char *s1 = ft_substr(s, 0, 5);
// 	char *s2 = ft_substr(s, 7, 5);
// 	char *s3 = ft_substr(s, 7, 0);
// 	printf("%s\n", s1);
// 	printf("%s\n", s2);
// 	printf("%s\n", s3);
// 	return (0);
// }