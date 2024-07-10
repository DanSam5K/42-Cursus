/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:25:43 by dansam            #+#    #+#             */
/*   Updated: 2024/07/10 23:35:16 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void *ft_calloc(size_t count, size_t size)
{
    size_t total_size;
    void *dst;
    unsigned char *ptr;
    size_t i;

    if (count == 0 || size == 0)
        return (malloc(0));
    if (count > SIZE_MAX / size)
        return (NULL);
    total_size = count * size;
    ptr = malloc(total_size);
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

int main(void)
{
    size_t count = 5;
    size_t size = 4;
    size_t total_size = count * size;
    void *ptr = ft_calloc(count, size);
    unsigned char *ptr_c = (unsigned char *)ptr;
    size_t i = 0;

    printf("calloc: ");
    while (i < total_size)
    {
        printf("%d ", ptr_c[i]);
        i++;
    }
    printf("\n");
    free(ptr);
    return (0);
}