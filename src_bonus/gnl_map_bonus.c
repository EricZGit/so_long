/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:52:23 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/18 09:07:22 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	check_buffer(char *buffer, int fd, t_game *game)
{
	if (!buffer)
		print_error(MAL, game);
	else if (fd == -1)
		print_error(FD, game);
}

static int	check_items(char c, t_game *game)
{
	if (c == 'C')
		game->map->collectables++;
	else if (c == 'E')
		game->map->out++;
	else if (c == 'P')
	{
		game->data->pos_col = game->map->columns - 1;
		game->data->pos_line = game->map->lines - 1;
		game->map->players++;
	}
	else if (c == '0' || c == '1' || c == '\n' || c == 'Y')
		return (1);
	else
		print_error(MAP, game);
	return (1);
}

static int	ft_sizemap(char	*argv, t_game *game)
{
	int		fd;
	int		bytes_read;
	char	*buffer;

	game->map->lines = 1;
	game->map->columns = 0;
	bytes_read = 1;
	fd = open(argv, O_RDONLY);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	check_buffer(buffer, fd, game);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		game->map->columns++;
		check_items(*buffer, game);
		if (*buffer == '\n')
		{
			game->map->lines++;
			game->map->columns = 0;
		}
	}
	game->map->columns--;
	free(buffer);
	close(fd);
	return (1);
}

static void	ft_mallocmap(t_game *game, int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*str;

	bytes_read = 1;
	str = ft_strdup("");
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	*(buffer + 1) = '\0';
	check_buffer(buffer, fd, game);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		str = ft_strjoin(str, buffer);
	}
	game->map->mapping = ft_split(str, '\n');
	free(str);
	free(buffer);
	check_map_is_ok(game);
}

int	gnl_map(t_game *game, char *argv)
{
	int	fd;

	ft_sizemap(argv, game);
	if (game->map->collectables < 1 || game->map->players < 1)
		print_error(ITEMS, game);
	else if (game->map->out < 1)
		print_error(ITEMS, game);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error(FD, game);
	ft_mallocmap(game, fd);
	if (game->map->lines == game->map->columns)
		print_error(MAP, game);
	close(fd);
	return (game->map->lines);
}
