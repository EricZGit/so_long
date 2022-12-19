/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:07:52 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 06:25:59 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	load_image_two(t_game *game)
{
	game->img->img_avpd = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, AVPD, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_avpg = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, AVPG, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_pipizero = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PIPIZERO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_pipione = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PIPIONE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_pipitwo = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PIPITWO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_soldzero = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SOLDZERO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_soldone = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SOLDONE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_soldtwo = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SOLDTWO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_image_three(t_game *game)
{
	game->img->img_guittwo = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, GUITTWO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_guitzero = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, GUITZERO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_guitone = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, GUITONE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_collectfear = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COLLECTFEAR, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exitone = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXITONE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exittwo = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXITTWO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exitthree = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXITTHREE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exitfour = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXITFOUR, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	ft_move_one(t_game *game, int x, int y)
{
	game->map->moves++;
	game->map->mapping[game->data->pos_line][game->data->pos_col] = '0';
	game->map->mapping[y][x] = 'P';
	game->data->pos_line = y;
	game->data->pos_col = x;
	ft_imaging(game);
	ft_score(game);
}

void	ft_move_two(t_game *game, int col, int line)
{
	game->map->moves++;
	line = 1;
	while (line < game->map->lines - 1)
	{
		col = 1;
		while (col < game->map->columns - 1)
		{
			game->map->mapping[line][col] = 'D';
			col++;
		}
		line++;
	}
	game->map->mapping[game->map->lines - 1][game->map->columns - 1] = 'D';
	game->data->end_game = 1;
	ft_imaging(game);
	ft_score(game);
}

void	ft_move_three(t_game *game, int x, int y)
{
	game->map->moves++;
	game->map->collectables--;
	game->map->mapping[game->data->pos_line][game->data->pos_col] = '0';
	game->map->mapping[y][x] = 'P';
	if (game->data->going_player == 97 \
	&& game->map->mapping[y][x - 1] != '0')
		game->map->mapping[y][x - 1] = 'T';
	else if (game->data->going_player == 100 \
	&& game->map->mapping[y][x + 1] != '0')
		game->map->mapping[y][x + 1] = 'T';
	else if (game->data->going_player == 119 \
	&& game->map->mapping[y - 1][x] != '0')
		game->map->mapping[y - 1][x] = 'T';
	else if (game->data->going_player == 115 \
	&& game->map->mapping[y + 1][x] != '0')
		game->map->mapping[y + 1][x] = 'T';
	game->data->pos_line = y;
	game->data->pos_col = x;
	screen_collec_fear(game);
	ft_imaging(game);
	ft_score(game);
}
