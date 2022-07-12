/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:59:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/12 14:00:44 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_map(t_global *global, int line, int col);
static void	put_player(t_global *global, int line, int col);
static void	put_collectables(t_global *global, int line, int col);
static void	put_exit(t_global *global, int line, int col);

int	put_images(t_global *global)
{
	int	line;
	int	col;

	line = 0;
	while (global->map->matrix[line])
	{
		col = 0;
		while (global->map->matrix[line][col])
		{
			if (global->map->matrix[line][col] == '1')
				put_map(global, line, col);
			else if (global->map->matrix[line][col] == 'C')
				put_collectables(global, line, col);
			else if (global->map->matrix[line][col] == 'E')
				put_exit(global, line, col);
			else if (global->map->matrix[line][col] == '0')
				put_map(global, line, col);
			else if (global->map->matrix[line][col] == 'P')
				put_player(global, line, col);
			col++;
		}
		line++;
	}
	return (1);
}

static void	put_map(t_global *global, int line, int col)
{
	if (global->map->matrix[line][col] == '1')
	{
		if (global->map->matrix[line][col - 1] == '0' \
		&& global->map->matrix[line - 1][col] == '0' \
		&& global->map->matrix[line + 1][col] == '0' \
		&& global->map->matrix[line][col + 1] == '1')
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_anglet, col * SIZE_IMG, line * SIZE_IMG);
		else if (global->map->matrix[line][col + 1] == '0' \
		&& global->map->matrix[line - 1][col] == '0' \
		&& global->map->matrix[line + 1][col] == '0' \
		&& global->map->matrix[line][col - 1] == '1')
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_anglet, col * SIZE_IMG, line * SIZE_IMG);
		else if (global->map->matrix[line][col + 1] == '0' \
		&& global->map->matrix[line - 1][col] == '0' \
		&& global->map->matrix[line + 1][col] == '1' \
		&& global->map->matrix[line][col - 1] == '0')
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_anglet, col * SIZE_IMG, line * SIZE_IMG);
		else if (global->map->matrix[line][col + 1] == '0' \
		&& global->map->matrix[line - 1][col] == '1' \
		&& global->map->matrix[line + 1][col] == '0' \
		&& global->map->matrix[line][col - 1] == '0')
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_anglet, col * SIZE_IMG, line * SIZE_IMG);
		else if ((col == 0 && line == 0) || (col == 0 && line == global->map->lines - 1) \
		|| (col == global->map->columns - 1 && line == 0) \
		|| (col == global->map->columns - 1 && line == global->map->lines - 1))
		{
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_angle, col * SIZE_IMG, line * SIZE_IMG);
		}
		else
			mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
			global->data->img_wall, col * SIZE_IMG, line * SIZE_IMG);
	}
	else
	{
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_path, col * SIZE_IMG, line * SIZE_IMG);
	}
}

static void	put_player(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_player_front, col * SIZE_IMG, \
	line * SIZE_IMG);
}

static void	put_collectables(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_colect, col * SIZE_IMG, line * SIZE_IMG);
}

static void	put_exit(t_global *global, int line, int col)
{
	if (global->map->collectables == 0)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_open, col * SIZE_IMG, line * SIZE_IMG);
	else
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_block, col * SIZE_IMG, line * SIZE_IMG);
}
