/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 06:40:08 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/15 15:51:24 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map) * 1);
	if (!game->map)
		close_window_and_exit(game);
	game->data = malloc(sizeof(t_data) * 1);
	if (!game->data)
		close_window_and_exit(game);
	game->img = malloc(sizeof(t_img) * 1);
	if (!game->img)
		close_window_and_exit(game);
	game->map->collectables = 0;
	game->map->players = 0;
	game->map->out = 0;
	game->data->end_game = 0;
	game->map->moves = 0;
	game->map->mapping = 0;
}

static void	init_image(t_game *game)
{
	load_image(game);
	load_player_image(game);
}

static void init_screen(t_game *game)
{
	game->data->mlx_ptr = mlx_init();
	if (game->data->mlx_ptr == NULL)
	{
		if (game->map->mapping)
			free_mapping(game);
		if (game->map)
			free(game->map);
		if (game->data)
			free(game->data);
		if (game->img)
			free(game->img);
		exit(EXIT_FAILURE);
	}
	game->data->mlx_win = mlx_new_window(game->data->mlx_ptr, \
		game->map->columns * 64, \
		game->map->lines * 64, "So_long");
	if (game->data->mlx_win == NULL)
	{
		free(game->data->mlx_win);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc != 2)
		print_error(ARG, &game);
	if (!ft_strnstr(argv[1], ".ber", 40))
		print_error(BER, &game);
	gnl_map(&game, argv[1]);
	init_screen(&game);
	init_image(&game);
	mlx_hook(game.data->mlx_win, 2, 1L << 0, key_actions, &game);
	mlx_hook(game.data->mlx_win, 17, 0, close_window_and_exit, &game);
	mlx_loop_hook(game.data->mlx_ptr, ft_imaging, &game);
	mlx_loop(game.data->mlx_ptr);
	return (0);
}
