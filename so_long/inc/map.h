/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:29:22 by ezielins          #+#    #+#             */
/*   Updated: 2022/06/29 18:50:43 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/* Struct pour stocker et gerer les dispositions*/
typedef struct s_placing
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_pl;
	int	n_gh;
	int	n_collect;
}				t_placing;

#endif
