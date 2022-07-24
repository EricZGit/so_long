/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:06:57 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/22 22:57:28 by ezielins         ###   ########.fr       */
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
	else
		screen_collec_fear(game); 
	ft_imaging(game);
	return (0);
}

int	anim_collectone(t_game *game)
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

int	anim_collecttwo(t_game *game)
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
