/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:33:26 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/07 18:59:36 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((s1[i] || s2[j]) && (s1[i] == s2[j]))
	{
		i++;
		j++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}
