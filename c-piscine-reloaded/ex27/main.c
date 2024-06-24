/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:12:25 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/07 19:51:47 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10000

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_buffer(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write (1, &buffer[i], 1);
		i++;
	}
}

int	ft_close_file(int file_display)
{
	if (close(file_display) == -1)
	{
		ft_putstr("Error closing file.\n");
		return (-1);
	}
	return (0);
}

int	ft_display_file(char **av)
{
	int		file_display;
	int		read_ret;
	char	buffer[BUFFER_SIZE];

	file_display = open(av[1], O_RDONLY);
	if (file_display == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	read_ret = read(file_display, buffer, sizeof(buffer));
	while (read_ret > 0)
	{
		ft_print_buffer(buffer, read_ret);
		read_ret = read(file_display, buffer, sizeof(buffer));
	}
	if (read_ret == -1)
	{
		ft_putstr("Cannot read file.\n");
		close(file_display);
		return (0);
	}
	if (ft_close_file(file_display) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc == 1)
		ft_putstr("File name missing.\n");
	else
		ft_display_file(argv);
	return (0);
}
