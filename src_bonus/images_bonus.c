/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:53:08 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/26 09:32:46 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	game->img->img_coinhd = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COINHD, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_coinhg = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COINHG, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_coinbd = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COINBD, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_coinbg = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COINBG, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_image_ennemy(t_game *game)
{
	game->img->img_ennemy_haut = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, ENNEMY_HAUT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_exitfive = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, EXITFIVE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_ennemy_droite = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, ENNEMY_DROITE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_ennemy_gauche = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, ENNEMY_GAUCHE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_death = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, DEATH, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoreneuf = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCONEUF, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoreheight = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOHEIGHT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorenine = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCONINE, &(game->data->img_largeur), \
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
	game->img->img_collectdeath = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, COLDEATH, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorezero = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOZERO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_score(t_game *game)
{
	game->img->img_scoreun = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOUN, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoredeux = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCODEUX, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoretrois = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOTROIS, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorequatre = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOQUATRE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorecinque = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOCINQUE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoresix = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOSIX, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoresept = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOSEPT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorehuit = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOHUIT, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}

void	load_score_two(t_game *game)
{
	game->img->img_scorezzero = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOZZERO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoreone = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOONE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoretwo = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOTWO, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorethree = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOTHREE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorefour = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOFOUR, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scorefive = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOFIVE, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoressix = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOSSIX, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
	game->img->img_scoreseven = mlx_xpm_file_to_image(\
		game->data->mlx_ptr, SCOSEVEN, &(game->data->img_largeur), \
		&(game->data->img_hauteur));
}
