/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 06:40:08 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/08 10:40:50 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map) * 1);
	game->data = malloc(sizeof(t_data) * 1);
	game->img = malloc(sizeof(t_img) * 1);
	game->map->collectables = 0;
	game->map->players = 0;
	game->map->out = 0;
	game->data->end_game = 0;
	game->map->moves = 0;
	game->map->mapping = 0;

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
	game.data->mlx_ptr = mlx_init();
	if (game.data->mlx_ptr == NULL)
		return (EXIT_FAILURE);
	game.data->mlx_win = mlx_new_window(game.data->mlx_ptr, \
		game.map->columns * 64, \
		game.map->lines * 64, "So_long");
	if (game.data->mlx_win == NULL)
	{
		free(game.data->mlx_win);
		return (EXIT_FAILURE);
	}
	load_image(&game);
	load_player_image(&game);
	mlx_hook(game.data->mlx_win, 2, 1L << 0, key_actions, &game);
	mlx_hook(game.data->mlx_win, 17, 0, close_window_and_exit, &game);
	mlx_loop_hook(game.data->mlx_ptr, put_images, &game);
	mlx_loop(game.data->mlx_ptr);
	return (0);
}
