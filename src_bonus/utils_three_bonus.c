/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:36:54 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/26 20:43:04 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	screen_collect_fearbis(t_game *game)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_collectfear, game->data->pos_col_colone * 64, \
	game->data->pos_line_colone * 64);
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_collectfear, game->data->pos_col_colzero * 64, \
	game->data->pos_line_colzero * 64);
}