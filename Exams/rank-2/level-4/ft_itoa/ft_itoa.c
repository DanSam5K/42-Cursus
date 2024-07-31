/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:12:30 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/30 20:32:17 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
    if (nbr == -2147483648)
        return("-2147483648\0");
    int n = nbr;
    int len = 0;
    if (nbr <= 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    result[len] = '\0';
    if (nbr == 0)
    {
        result[0] = '0';
        return (result);
    }
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }
    while (nbr)
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}