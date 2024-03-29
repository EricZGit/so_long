/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 06:07:13 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/13 08:05:03 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_player_image(t_game *game)
{
	game->img->img_player_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_HAUT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_bas = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_BAS, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_droite = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_DROITE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_player_gauche = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, PLAYER_GAUCHE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_image(t_game *game)
{
	game->img->img_wall = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, WALL, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exit_open = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXIT_OPEN, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exit_close = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXIT_CLOSE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_texture = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, TEXTURE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_collectable = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COLLECT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_angle = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, ANGLE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
