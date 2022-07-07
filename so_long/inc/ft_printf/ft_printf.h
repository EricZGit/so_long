/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:22:19 by ezielins          #+#    #+#             */
/*   Updated: 2022/05/20 12:02:25 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *input, ...);
int		ft_countchar(int c);
int		ft_countstr(char *s);
int		ft_countnbr(long long nbr, int base, int is_maj);
int		ft_countpointer(long long nbr, int base, int is_maj);

#endif
