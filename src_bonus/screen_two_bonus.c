/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 07:05:32 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/21 13:10:23 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	screen_ennemy(t_game *game, int line, int col, int death)
{
	int	y;
	int	x;

	if (death == 68) 
	{
		y = 1;
		while (y < game->map->lines - 1)
		{
			x = 1;
			while (x < game->map->columns - 1)
			{
				mlx_put_image_to_window(game->data->mlx_ptr, \
				game->data->mlx_win, game->img->img_death, x * 64, y * 64);
				x++;
			}
			y++;
		}
	}
	else if (death == 89)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_haut, col * 64, line * 64);
}

void	screen_collectdeath(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectdeath, x * 64, y * 64);
}

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
}
