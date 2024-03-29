/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:53:41 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 06:21:17 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/colors.h"
#include "../inc/so_long_bonus.h"

int	close_window_and_exit(t_game *game)
{
	free_images(game);
	free_score(game);
	free_score_two(game);
	mlx_clear_window(game->data->mlx_ptr, game->data->mlx_win);
	mlx_destroy_window(game->data->mlx_ptr, game->data->mlx_win);
	mlx_destroy_display(game->data->mlx_ptr);
	mlx_loop_end(game->data->mlx_ptr);
	free(game->data->mlx_ptr);
	free_mapping(game);
	free(game->data);
	free(game->map);
	free(game->img);
	exit(0);
	return (0);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_player_haut);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_player_bas);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_player_gauche);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_player_droite);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_texture);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_wall);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_collectable);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exit_close);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exit_open);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_angle);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_ennemy_haut);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_ennemy_gauche);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_ennemy_droite);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_death);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_collectdeath);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_coinhd);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_coinhg);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_coinbd);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_coinbg);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_avpd);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_avpg);
}

int	key_actions(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->data->pos_col;
	y = game->data->pos_line;
	if (key == ESC || key == QUIT)
		close_window_and_exit(game);
	else if (key == A || key == ARROW_LEFT)
		x--;
	else if (key == W || key == ARROW_UP)
		y--;
	else if (key == S || key == ARROW_DOWN)
		y++;
	else if (key == D || key == ARROW_RIGHT)
		x++;
	if (game->data->end_game == 0)
		ft_move_player(game, x, y, key);
	return (0);
}

void	ft_move_player(t_game *game, int x, int y, int key)
{
	int	move_is_ok;
	int	col;
	int	line;

	col = game->data->pos_col;
	line = game->data->pos_line;
	move_is_ok = ftmove_is_ok(game, x, y, key);
	if (move_is_ok == 1)
	{
		ft_going_player(game, key);
		moving_ennemy(game, key);
		ft_move_one(game, x, y);
	}
	else if (move_is_ok == 2)
	{
		ft_going_player(game, key);
		ft_move_two(game, col, line);
	}
	else if (move_is_ok == 3)
	{
		ft_going_player(game, key);
		moving_ennemy(game, key);
		ft_move_three(game, x, y);
	}
}

int	ftmove_is_ok(t_game *game, int x, int y, int key)
{
	if (game->map->mapping[y][x] == '1' || game->map->mapping[y][x] == 'T')
		return (-1);
	if (game->map->mapping[y][x] == 'C')
		return (3);
	if (game->map->mapping[y][x] == 'Y')
		return (2);
	if (game->map->mapping[y][x] == 'E' && game->map->collectables == 0)
	{
		game->map->mapping[game->data->pos_line][game->data->pos_col] = '0';
		game->data->end_game = 1;
		close_window_and_exit(game);
		return (-1);
	}
	else if (game->map->mapping[y][x] == 'E')
		return (-1);
	if (key != A && key != W && key != S && key != D && key != ARROW_UP
		&& key != ARROW_DOWN && key != ARROW_LEFT && key != ARROW_RIGHT)
		return (-1);
	else
		return (1);
}
