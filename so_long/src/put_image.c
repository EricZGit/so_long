/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:36:53 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/07 18:41:05 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_map(t_game *game, int line, int col)
{
	if (game->map->mapping[line][col] == '1')
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_wall, col * 64, line * 64);
	}
	else
	{
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_texture, col * 64, line * 64);
	}
}

static void	put_player(t_game *game, int line, int col)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_player_haut, col * 64, \
	line * 64);
}

static void	put_collectables(t_game *game, int line, int col)
{
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
	game->img->img_collectable, col * 64, line * 64);
}

static void	put_exit(t_game *game, int line, int col)
{
	if (game->map->collectables == 0)
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exit_open, col * 64, line * 64);
	else
		mlx_put_image_to_window(game->data->mlx_ptr, game->data->mlx_win, \
		game->img->img_exit_close, col * 64, line * 64);
}


int	put_images(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map->mapping[line])
	{
		col = 0;
		while (game->map->mapping[line][col])
		{
			if (game->map->mapping[line][col] == '1')
				put_map(game, line, col);
			else if (game->map->mapping[line][col] == 'C')
				put_collectables(game, line, col);
			else if (game->map->mapping[line][col] == 'E')
				put_exit(game, line, col);
			else if (game->map->mapping[line][col] == '0')
				put_map(game, line, col);
			else if (game->map->mapping[line][col] == 'P')
				put_player(game, line, col);
			col++;
		}
		line++;
	}
	return (1);
}
