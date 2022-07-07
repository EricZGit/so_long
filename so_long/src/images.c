/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 06:07:13 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/07 09:29:35 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_player_image(t_game *game)
{
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_HAUT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_BAS, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_DROITE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_GAUCHE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_image(t_game *game)
{
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, WALL, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXIT_OPEN, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXIT_CLOSE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, TEXTURE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COLLECT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}