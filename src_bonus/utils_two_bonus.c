/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:06:57 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 10:06:48 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_going_player(t_game *game, int key)
{
	if (key == A || key == ARROW_LEFT)
		game->data->going_player = 97;
	if (key == W || key == ARROW_UP)
		game->data->going_player = 119;
	if (key == S || key == ARROW_DOWN)
		game->data->going_player = 115;
	if (key == D || key == ARROW_RIGHT)
		game->data->going_player = 100;
}

int	anim_collect(t_game *game)
{
	game->data->anim++;
	if (game->map->collectables == 3)
	{	
		screen_collec_sold(game);
		screen_collec_guit(game);
		screen_collec_pipi(game);
	}
	ft_imaging(game);
	return (0);
}

void	position_collect(t_game *game)
{
	if (game->map->collectables == 1)
	{
		game->data->pos_col_colzero = game->map->columns - 1;
		game->data->pos_line_colzero = game->map->lines - 1;
	}
	else if (game->map->collectables == 2)
	{
		game->data->pos_col_colone = game->map->columns - 1;
		game->data->pos_line_colone = game->map->lines - 1;
	}
	else if (game->map->collectables == 3)
	{
		game->data->pos_col_coltwo = game->map->columns - 1;
		game->data->pos_line_coltwo = game->map->lines - 1;
	}
}

int	test_movennemy(t_game *game, int x, int y)
{
	if (game->map->mapping[y][x] != '1' && game->map->mapping[y][x] != 'C' \
	&& game->map->mapping[y][x] != 'E' && game->map->mapping[y][x] != 'T')
		return (1);
	else if (game->map->mapping[y][x] == 'P')
	{
		ft_move_two(game, x, y);
		return (0);
	}
	else
		return (0);
}

void	moving_ennemy(t_game *game, int key)
{
	int	x;
	int	y;
	int	nombre;

	nombre = 0;
	srand(time(NULL));
	x = game->data->pos_colennemy;
	y = game->data->pos_linennemy;
	if (game->data->pos_col == x && game->data->pos_line == y)
		ft_move_two(game, x, y);
	if (key)
		nombre = (rand() % (MAX + 1 - MIN)) + MIN;
	if (nombre == 1 && test_movennemy(game, x, y - 1))
		data_ennemy(game, 97);
	else if (nombre == 2 && test_movennemy(game, x, y + 1))
		data_ennemy(game, 119);
	else if (nombre == 3 && test_movennemy(game, x - 1, y))
		data_ennemybis(game, 115);
	else if (nombre == 4 && test_movennemy(game, x + 1, y))
		data_ennemybis(game, 100);
	ft_imaging(game);
}
