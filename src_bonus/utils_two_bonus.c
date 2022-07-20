/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:06:57 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/20 20:24:52 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	screen_ennemy(t_game *game, int line, int col, int death)
{
	if (death == 68) 
	{
		int	y;
		int	x;

		y = 1;
		while (y < game->map->lines - 1)
		{
			x = 1;
			while (x < game->map->columns - 1)
			{
				mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
				game->img->img_death, x * 64, y * 64);
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