/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:54:48 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 06:44:44 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	screen_map(t_game *game, int line, int col)
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
		else
			screen_coin(game, line, col);
	}
	else
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_texture, col * 64, line * 64);
	}
}

void	screen_exit(t_game *game, int y, int x)
{
	if (game->map->collectables == 0)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exitfive, x * 64, y * 64);
	else if (game->map->moves == 1)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exittwo, x * 64, y * 64);
	else if (game->map->moves == 2)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exitthree, x * 64, y * 64);
	else if (game->map->moves >= 3)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exitfour, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exitone, x * 64, y * 64);
}

void	screen_player(t_game *game, int y, int x)
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

void	screen_collec_fear(t_game *game)
{
	if (game->data->pos_col == game->data->pos_col_colzero)
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectfear, game->data->pos_col_colone * 64, \
		game->data->pos_line_colone * 64);
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectfear, game->data->pos_col_coltwo * 64, \
		game->data->pos_line_coltwo * 64);
	}
	else if (game->data->pos_col == game->data->pos_col_colone)
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectfear, game->data->pos_col_colzero * 64, \
		game->data->pos_line_colzero * 64);
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectfear, game->data->pos_col_coltwo * 64, \
		game->data->pos_line_coltwo * 64);
	}
	else if (game->data->pos_col == game->data->pos_col_coltwo)
		screen_collect_fearbis(game);
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
			screen_imaging(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
