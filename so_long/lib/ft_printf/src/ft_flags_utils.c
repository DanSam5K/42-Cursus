/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:25:50 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/12 16:50:37 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspec(int c)
{
	const char	*specs;
	int			i;

	specs = "-0.*# +";
	i = 0;
	while (specs[i])
	{
		if (c == specs[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_istype(int c)
{
	const char	*types;
	int			i;

	types = "csdiuxXp%";
	i = 0;
	while (types[i])
	{
		if (c == types[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspec(c));
}
