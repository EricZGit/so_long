/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:54:48 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/21 10:23:08 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	screen_map(t_game *game, int line, int col)
{
	if (game->map->mapping[line][col] == '1')
	{
		if (col == 0 && line == game->map->lines - 1)
			ft_score(game);
		else if ((col == 1 && line == game->map->lines - 1) \
		|| (col == 2 && line == game->map->lines - 1))
			ft_score(game);
		else if (col == 0 && line == 0)
			mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
			game->img->img_coinbg, col * 64, line * 64);
		else if (col == 1 && line == 0)
			mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
			game->img->img_coinbd, col * 64, line * 64);
		else if (col == game->map->columns - 2 && line == 0)
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
	if (game->data->going_player == A)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_player_gauche, x * 64, y * 64);
	if (game->data->going_player == W)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_player_bas, x * 64, y * 64);
	if (game->data->going_player == D)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_player_droite, x * 64, y * 64);
	if (game->data->going_player == S)
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
			if (game->map->mapping[y][x] == '1' \
			|| game->map->mapping[y][x] == '0')
				screen_map(game, y, x);
			else if (game->map->mapping[y][x] == 'C')
				screen_collectables(game, y, x);
			else if (game->map->mapping[y][x] == 'T')
				screen_collectdeath(game, y, x);
			else if (game->map->mapping[y][x] == 'E')
				screen_exit(game, y, x);
			else if (game->map->mapping[y][x] == 'Y' \
			|| game->map->mapping[y][x] == 'D')
				screen_ennemy(game, y, x, game->map->mapping[y][x]);
			else if (game->map->mapping[y][x] == 'P')
				screen_player(game, y, x);
			x++;
		}
		y++;
	}
	return (1);
}
