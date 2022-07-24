/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:33:04 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/18 06:08:42 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	screen_map(t_game *game, int line, int col)
{
	if (game->map->mapping[line][col] == '1')
	{
		if ((col == 0 && line == 0) \
		|| (col == 0 && line == game->map->lines - 1) \
		|| (col == game->map->columns - 1 && line == 0) \
		|| (col == game->map->columns - 1 && line == game->map->lines - 1))
		{
			mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
			game->img->img_angle, col * 64, line * 64);
		}
		else
			mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
			game->img->img_wall, col * 64, line * 64);
	}
	else
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_texture, col * 64, line * 64);
	}
}

static void	screen_exit(t_game *game, int y, int x)
{
	if (game->map->collectables == 0)
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exit_open, x * 64, y * 64);
	}
	else
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exit_close, x * 64, y * 64);
	}
}

static void	screen_player(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_player_haut, x * 64, y * 64);
}

static void	screen_collectables(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectable, x * 64, y * 64);
}

int	ft_imaging(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->mapping[y])
	{
		x = 0;
		while (game->map->mapping[y][x])
		{
			if (game->map->mapping[y][x] == '1')
				screen_map(game, y, x);
			else if (game->map->mapping[y][x] == 'C')
				screen_collectables(game, y, x);
			else if (game->map->mapping[y][x] == 'E')
				screen_exit(game, y, x);
			else if (game->map->mapping[y][x] == '0')
				screen_map(game, y, x);
			else if (game->map->mapping[y][x] == 'P')
				screen_player(game, y, x);
			x++;
		}
		y++;
	}
	return (1);
}
