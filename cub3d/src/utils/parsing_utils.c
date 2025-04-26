/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:57 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:49:00 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_empty_char(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (STATUS_FAIL);
	else
		return (STATUS_OK);
}

size_t	ft_max_width(t_map_data *map_data, int i)
{
	size_t	max_len;

	max_len = ft_strlen(map_data->file[i]);
	while (map_data->file[i])
	{
		if (ft_strlen(map_data->file[i]) > max_len)
			max_len = ft_strlen(map_data->file[i]);
		i++;
	}
	return (max_len);
}

bool	ft_comfirm_digit_absence(char *str)
{
	int		i;
	bool	found_no_digit;

	i = 0;
	found_no_digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			found_no_digit = false;
		i++;
	}
	return (found_no_digit);
}

int	ft_skip_whitespace(char *line, int *index)
{
	while (line[*index] == ' ' || line[*index] == '\t'
		|| line[*index] == '\r' || line[*index] == '\v'
		|| line[*index] == '\f')
		(*index)++;
	return (1);
}

int	ft_validate_map_char(t_game_data *game_data, char current_char)
{
	if (!(ft_strchr("10NSEW", current_char)))
		return (ft_error_msg(game_data->map_data.path,
				ERR_INV_LETTER, STATUS_FAIL));
	return (STATUS_OK);
}
