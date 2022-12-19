/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:36:54 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 09:28:48 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	screen_collect_fearbis(t_game *game)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_collectfear, game->data->pos_col_colone * 64, \
	game->data->pos_line_colone * 64);
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_collectfear, game->data->pos_col_colzero * 64, \
	game->data->pos_line_colzero * 64);
}

void	screen_coin(t_game *game, int line, int col)
{
	if (col == game->map->columns - 2 && line == 0)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_avpg, col * 64, line * 64);
	else if (col == game->map->columns - 1 && line == 0)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_avpd, col * 64, line * 64);
	else if (col == game->map->columns - 2 && line == game->map->lines - 1)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_coinhg, col * 64, line * 64);
	else if (col == game->map->columns - 1 && line == game->map->lines - 1)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_coinhd, col * 64, line * 64);
	else
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_wall, col * 64, line * 64);
}

void	screen_imaging(t_game *game, int x, int y)
{
	if (game->map->mapping[y][x] == '1' || game->map->mapping[y][x] == '0')
		screen_map(game, y, x);
	else if (game->map->mapping[y][x] == 'T')
		screen_collectdeath(game, y, x);
	else if (game->map->mapping[y][x] == 'E')
		screen_exit(game, y, x);
	else if (game->map->mapping[y][x] == 'Y' || game->map->mapping[y][x] == 'D')
		screen_ennemy(game, y, x, game->map->mapping[y][x]);
	else if (game->map->mapping[y][x] == 'P')
		screen_player(game, y, x);
}

void	screen_collectdeath(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectdeath, x * 64, y * 64);
}

void	data_ennemy(t_game *game, int key)
{
	if (key == 97)
	{
		game->map->mapping[game->data->pos_linennemy - 1] \
		[game->data->pos_colennemy] = 'Y';
		game->map->mapping[game->data->pos_linennemy] \
		[game->data->pos_colennemy] = '0';
		game->data->pos_linennemy--;
	}
	else if (key == 119)
	{
		game->map->mapping[game->data->pos_linennemy + 1] \
		[game->data->pos_colennemy] = 'Y';
		game->map->mapping[game->data->pos_linennemy] \
		[game->data->pos_colennemy] = '0';
		game->data->pos_linennemy++;
	}
	game->data->going_ennemy = key;
	ft_imaging(game);
}
