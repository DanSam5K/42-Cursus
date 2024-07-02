/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:07:39 by dansam            #+#    #+#             */
/*   Updated: 2024/07/02 15:20:03 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
    int c_index;
    int sign;
    int res;

    c_index = 0;
    sign = 1;
    res = 0;
    while (str[c_index] == ' ' || (str[c_index] >= 9 && str[c_index] <= 13))
        c_index++;
    if (str[c_index] == '-' || str[c_index] == '+')
    {
        if (str[c_index] == '-')
            sign = -1;
        c_index++;
    }
    while (str[c_index] >= '0' && str[c_index] <= '9')
    {
        res = res * 10 + str[c_index] - '0';
        c_index++;
    }
    return (res * sign);
}

// int main(void)
// {
//     char str[] = "  -42";
//     printf("atoi: %d\n", atoi(str));
//     printf("ft_atoi: %d\n", ft_atoi(str));
//     return (0);
// }
