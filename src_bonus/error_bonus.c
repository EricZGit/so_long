/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:51:24 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/18 11:44:46 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/colors.h"
#include "../inc/so_long_bonus.h"
#include "../inc/ft_printf/ft_printf.h"

void	print_error(char *msg, t_game *game)
{
	ft_printf("Error\n\033[0;40m>>>\033[0;39m %s%s%s\n", WHITE, msg, DEFAULT);
	if (game->map->mapping)
		free_mapping(game);
	if (game->map)
		free(game->map);
	if (game->data)
		free(game->data);
	if (game->img)
		free(game->img);
	exit(0);
}

void	free_mapping(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->lines)
	{
		free(game->map->mapping[i]);
		i++;
	}
	free(game->map->mapping);
}

static void	check_map_first_line(t_game *game)
{
	int	count;
	int	col_size;

	count = 0;
	col_size = ft_strlen(game->map->mapping[0]);
	while (col_size < 0)
	{
		if (game->map->mapping[0][count] != '1')
			print_error(MAP, game);
		count++;
		col_size--;
	}
}

static void	check_map_last_line(t_game *game)
{
	int	count;
	int	col_size;

	count = 0;
	col_size = ft_strlen(game->map->mapping[game->map->lines - 1]);
	while (col_size < 0)
	{
		if (game->map->mapping[game->map->lines - 1][count] != '1')
			print_error(MAP, game);
		count++;
		col_size--;
	}
}

void	check_map_is_ok(t_game *game)
{
	int	count_col;
	int	lines;
	int	columns;

	lines = 1;
	count_col = game->map->columns;
	check_map_first_line(game);
	while (lines < game->map->lines)
	{
		if (game->map->mapping[lines] == NULL)
			print_error(MAP, game);
		columns = 0;
		while (game->map->mapping[lines][columns])
			columns++;
		if (columns != game->map->columns)
			print_error(MAP, game);
		if (game->map->mapping[lines][0] != '1')
			print_error(MAP, game);
		else if (game->map->mapping[lines][count_col - 1] != '1')
			print_error(MAP, game);
		lines++;
	}
	check_map_last_line(game);
}
