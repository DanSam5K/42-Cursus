/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:52:17 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/26 12:56:45 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_comfirm_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

bool	ft_confirm_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

static bool	ft_comfirm_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

int	ft_file_and_dir_checker(char *arg, bool cub_file)
{
	int	fd;

	if (ft_comfirm_dir(arg))
		return (ft_error_msg(arg, ERR_FILE_IS_DIR, STATUS_FAIL));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (ft_error_msg(arg, strerror(errno), STATUS_FAIL));
	close(fd);
	if (cub_file && !ft_confirm_cub_file(arg))
		return (ft_error_msg(arg, ERR_FILE_NOT_CUB, STATUS_FAIL));
	if (!cub_file && !ft_comfirm_xpm_file(arg))
		return (ft_error_msg(arg, ERR_FILE_NOT_XPM, STATUS_FAIL));
	return (STATUS_OK);
}
