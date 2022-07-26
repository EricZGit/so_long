/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:07:52 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/26 09:31:47 by ezielins         ###   ########.fr       */
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
