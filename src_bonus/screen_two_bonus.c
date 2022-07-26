/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 07:05:32 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/26 10:31:08 by ezielins         ###   ########.fr       */
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
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_haut, col * 64, line * 64);
		screen_movennemy(game , line, col);
	}
}

void	screen_collectdeath(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_collectdeath, x * 64, y * 64);
}

void	screen_movennemy(t_game *game, int y, int x)
{
	if (game->data->going_ennemy == A)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_gauche, x * 64, y * 64);
	if (game->data->going_ennemy == W)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_haut, x * 64, y * 64);
	if (game->data->going_ennemy == D)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_droite, x * 64, y * 64);
	if (game->data->going_ennemy == S)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_ennemy_haut, x * 64, y * 64);
}

void	screen_collec_guit(t_game *game)
{
	void	*imageguit;
	
	imageguit = NULL;
	if (game->data->anim % 29 == 0)
		imageguit = game->img->img_guitone;
	else if (game->data->anim % 49 == 0)
		imageguit = game->img->img_guittwo;
	else
		imageguit = game->img->img_guitzero;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	imageguit, game->data->pos_col_colone * 64, game->data->pos_line_colone * 64);
}

void	screen_collec_pipi(t_game *game)
{
	void	*imagepipi;
	
	imagepipi = NULL;
	if (game->data->anim % 29 == 0 || game->data->anim % 2 == 0 \
	|| game->data->anim % 5 == 0)
		imagepipi = game->img->img_pipione;
	else if (game->data->anim % 49 == 0)
		imagepipi = game->img->img_pipitwo;
	else
		imagepipi = game->img->img_pipizero;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	imagepipi, game->data->pos_col_coltwo * 64, game->data->pos_line_coltwo * 64);
}

void	screen_collec_sold(t_game *game)
{
	void	*imagesold;
	
	imagesold = NULL;
	if (game->data->anim % 29 == 0)
		imagesold = game->img->img_soldone;
	else if (game->data->anim % 49 == 0)
		imagesold = game->img->img_soldtwo;
	else
		imagesold = game->img->img_soldzero;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	imagesold, game->data->pos_col_colzero * 64, game->data->pos_line_colzero * 64);
}
