/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:01:52 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/26 23:01:57 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_msg(char *arg, char *str, int er_code)
{
	ft_putstr_fd(RED "cub3D: Error", 2);
	if (arg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (er_code);
}

int	ft_error_val(int arg, char *str, int er_code)
{
	ft_putstr_fd(RED "cub3D: Error: ", 2);
	ft_putnbr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" RESET, 2);
	return (er_code);
}

char	*ft_strtrim_whitespace(const char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] && ft_isspace(str[start]))
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && ft_isspace(str[end]))
		end--;
	trimmed = ft_substr(str, start, end - start + 1);
	return (trimmed);
}

int	ft_validate_map_row(t_game_data *game_data, const char *row)
{
	int	col;

	col = 0;
	while (row[col])
	{
		if (ft_validate_map_char(game_data, row[col]) == STATUS_FAIL
			|| ft_handle_player_direction(game_data, row[col]) == STATUS_FAIL)
			return (STATUS_FAIL);
		col++;
	}
	return (STATUS_OK);
}
