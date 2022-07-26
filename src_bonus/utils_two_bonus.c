/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:06:57 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/25 13:56:29 by ezielins         ###   ########.fr       */
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

static int	test_movennemy(t_game *game, int x, int y)
{
	if (game->map->mapping[y][x] != '1' && game->map->mapping[y][x] != 'C' \
	&& game->map->mapping[y][x] != 'E')
		
	int nombre = 0;
    const int MIN = 1, MAX = 4;
    srand(time(NULL)); 
    if (game->map->mapping[y][x] != '1' && game->map->mapping[y][x] != 'C' \
	&& game->map->mapping[y][x] != 'E')
	{
		nombre = (rand() % (MAX + 1 - MIN)) + MIN;
	}
	nombre = (rand() % (MAX + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
    printf("%d", nombre); // rand  renvoie un nombre calculé à partir de la donnée seed

    return 0;
		
		
		return (1);
	else
		return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void	moving_ennemy(t_game *game, int key)
{
	int	x;
	int	y;
	int nombre = 0;
	const int MIN = 1;
	const int MAX = 4;
	srand(time(NULL)); 
	
	x = game->data->pos_colennemy;
	y = game->data->pos_linennemy;
	printf("xxxxx yyyyy %d %d\n", y, x);
	if (key)
	{
		nombre = (rand() % (MAX + 1 - MIN)) + MIN;
	}

	if ((key == A || key == ARROW_LEFT))
	{
		nombre = (rand() % (MAX + 1 - MIN)) + MIN;
		game->data->going_ennemy = 97;
		game->data->pos_colennemy--;
	}
	else if ((key == W || key == ARROW_UP) \
	&& test_movennemy(game, x, y - 1))
	{
		game->data->going_ennemy = 119;
		game->data->pos_linennemy--;
	}
	else if ((key == S || key == ARROW_DOWN) \
	&& test_movennemy(game, x,	y + 1))
	{
		game->data->going_ennemy = 115;
		y = game->data->pos_linennemy;
	}
	else if ((key == D || key == ARROW_RIGHT) \
	&& test_movennemy(game, x + 1, y))
	{
		game->data->going_ennemy = 100;
		x = game->data->pos_colennemy;
	}
}
