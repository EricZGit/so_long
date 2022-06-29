/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:20:07 by ezielins          #+#    #+#             */
/*   Updated: 2022/06/29 18:57:17 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "map.h"

/* Basic checks pour voir si le bon fichier est ouvert*/
char	**ok_params(int argc, char **argv, t_placing *placing);

/* Lance le map_checker et construit la map comme une matrice*/
char	**check_map(int fd, t_placing *placing);

#endif
