/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:11 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/07 11:23:19 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	num;
	int	i;

	num = nb;
	i = 1;
	if (nb < 0)
		return (0);
	while (num > i)
	{
		num = (num + i) / 2;
		i = nb / num;
	}
	if (num * num == nb)
		return (num);
	else
		return (0);
}
