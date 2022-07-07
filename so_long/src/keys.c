/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:46:50 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/07 19:32:15 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "../inc/so_long.h"
#include "../inc/ft_printf/ft_printf.h"

int	close_window_and_exit(t_game *game)
{
	free_images(game);
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
		game->map->moves++;
		game->map->mapping[line][col] = '0';
		game->map->mapping[y][x] = 'P';
		game->data->pos_line = y;
		game->data->pos_col = x;
		put_images(game);
		ft_printf("\033[0;40m[Moves : ]\033[0;39m %d\n", \
			YELLOW, game->map->moves, DEFAULT);
	}
}

int	ftmove_is_ok(t_game *game, int x, int y, int key)
{
	if (game->map->mapping[y][x] == '1')
		return (-1);
	if (game->map->mapping[y][x] == 'C')
		game->map->collectables--;
	if (game->map->mapping[y][x] == 'E' && game->map->collectables == 0)
	{
		game->map->mapping[game->data->pos_line] \
		[game->data->pos_col] = '0';
		game->data->end_game = 1;
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