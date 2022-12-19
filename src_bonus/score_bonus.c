/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:44:06 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/27 06:25:21 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_score(t_game *game)
{
	int	score;
	int	diz;
	int	cent;

	score = game->map->moves;
	if (score != 1000)
	{
		diz = score % 10;
		score /= 10;
		cent = score / 10;
		score %= 10;
		ft_put_score(game, diz, game->map->lines - 1, 2);
		ft_put_score(game, score, game->map->lines - 1, 1);
		ft_put_scorex(game, cent, game->map->lines - 1, 0);
	}
	else
		close_window_and_exit(game);
}

void	ft_put_score(t_game *game, int diz, int line, int col)
{
	void	*image;

	image = NULL;
	if (diz == 0)
		image = game->img->img_scorezero;
	if (diz == 1)
		image = game->img->img_scoreun;
	if (diz == 2)
		image = game->img->img_scoredeux;
	if (diz == 3)
		image = game->img->img_scoretrois;
	if (diz == 4)
		image = game->img->img_scorequatre;
	if (diz == 5)
		image = game->img->img_scorecinque;
	if (diz == 6)
		image = game->img->img_scoresix;
	if (diz == 7)
		image = game->img->img_scoresept;
	if (diz == 8)
		image = game->img->img_scorehuit;
	if (diz == 9)
		image = game->img->img_scoreneuf;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, image, \
	col * 64, line * 64);
}

void	ft_put_scorex(t_game *game, int diz, int line, int col)
{
	void	*image;

	image = NULL;
	if (diz == 0)
		image = game->img->img_scorezzero;
	if (diz == 1)
		image = game->img->img_scoreone;
	if (diz == 2)
		image = game->img->img_scoretwo;
	if (diz == 3)
		image = game->img->img_scorethree;
	if (diz == 4)
		image = game->img->img_scorefour;
	if (diz == 5)
		image = game->img->img_scorefive;
	if (diz == 6)
		image = game->img->img_scoressix;
	if (diz == 7)
		image = game->img->img_scoreseven;
	if (diz == 8)
		image = game->img->img_scoreheight;
	if (diz == 9)
		image = game->img->img_scorenine;
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, image, \
	col * 64, line * 64);
}

void	free_score(t_game *game)
{
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorezero);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorezzero);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoreun);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoreone);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoredeux);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoretwo);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoretrois);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorethree);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorequatre);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorefour);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorecinque);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorefive);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoresix);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoressix);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoresept);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoreseven);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorehuit);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoreheight);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scoreneuf);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_scorenine);
}

void	free_score_two(t_game *game)
{
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_pipizero);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_pipione);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_pipitwo);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_guitzero);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_guitone);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_guittwo);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_soldzero);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_soldone);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_soldtwo);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_collectfear);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exitone);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exittwo);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exitthree);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exitfour);
	mlx_destroy_image(game->data->mlx_ptr, game->img->img_exitfive);
}
