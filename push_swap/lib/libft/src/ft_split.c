/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:20:11 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/22 18:17:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_delim(const char *str, char delim)
{
	size_t	count;
	size_t	delim_result;
	int		delim_word;

	count = 0;
	delim_result = 0;
	delim_word = 0;
	while (str[count])
	{
		if (str[count] == delim && delim_word == 1)
		{
			delim_result++;
			delim_word = 0;
		}
		else if (str[count] != delim && delim_word == 0)
			delim_word = 1;
		count++;
	}
	if (delim_word == 1)
		delim_result++;
	return (delim_result);
}

static char	*ft_alloc_copyword(const char *str, size_t len)
{
	char	*mem_size;

	if (!str)
		return (NULL);
	mem_size = (char *)malloc(len + 1);
	if (!mem_size)
		return (NULL);
	if (mem_size)
		ft_memcpy(mem_size, str, len);
	mem_size[len] = '\0';
	return (mem_size);
}

static char	**ft_free_split(char **split_result, int count)
{
	int	index;

	index = 0;
	while (index < count)
		free(split_result[index++]);
	return (NULL);
}

static char	**ft_fill_split(char const *str, char delim,
							char **dest, size_t max_len)
{
	size_t		i;
	char const	*start;
	int			delim_word;

	i = 0;
	delim_word = 0;
	while (i < max_len)
	{
		if ((*str == delim || !(*str)) && delim_word == 1)
		{
			dest[i++] = ft_alloc_copyword(start, str - start);
			if (!dest[i - 1])
				break ;
			delim_word = 0;
		}
		if (*str != delim && delim_word == 0)
		{
			start = str;
			delim_word = 1;
		}
		str++;
	}
	if (!dest[i - 1])
		return (ft_free_split(dest, i - 1));
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**split_result;
	size_t	split_len;

	split_len = ft_count_delim(s, c);
	split_result = (char **)malloc(sizeof(char *) * (split_len + 1));
	if (!split_result)
		return (NULL);
	split_result[split_len] = NULL;
	if (split_len && !ft_fill_split(s, c, split_result, split_len))
	{
		free(split_result);
		return (NULL);
	}
	return (split_result);
}
