/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:03:30 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/19 16:48:37 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

/***** Libft Functions *****/
# include "../libft/includes/libft.h"

/***** Mandatory Functions *****/
void	ft_error(void);
char	*ft_find_path(char *cmd, char **envp);
void	ft_execute(char *argv, char **envp);

/***** Bonus Functions *****/
void	ft_usage(void);
int		ft_open_file(char *file, int mode);
int		ft_get_next_line(char **output_line);

#endif
