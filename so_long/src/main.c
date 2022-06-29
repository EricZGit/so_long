/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:18:35 by ezielins          #+#    #+#             */
/*   Updated: 2022/06/29 18:57:32 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "game.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_placing	placing;

	map = ok_params(argc, argv, &placing);
	init_game(map, placing);
	return (0);
}