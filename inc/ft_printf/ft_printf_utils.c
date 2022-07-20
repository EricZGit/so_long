/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:36:39 by ezielins          #+#    #+#             */
/*   Updated: 2022/05/20 12:02:34 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_countstr(char *s)
{
	int	result;

	result = 0;
	if (!s)
	{
	result += write(1, "(null)", 6);
		return (result);
	}
	while (*s)
	{
		write(1, s, 1);
		result++;
		s++;
	}
	return (result);
}

int	ft_countnbr(long long nbr, int base, int is_maj)
{
	int			result;
	char		*base_maj;
	char		*base_min;

	base_maj = "0123456789ABCDEF";
	base_min = "0123456789abcdef";
	result = 1;
	if (nbr < 0)
	{
		result++;
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr >= base)
		result += ft_countnbr((unsigned long)nbr / base, base, is_maj);
	if (is_maj)
		write(1, &base_maj[(unsigned long)nbr % base], 1);
	else
		write(1, &base_min[(unsigned long)nbr % base], 1);
	return (result);
}

int	ft_countpointer(long long nbr, int base, int is_maj)
{
	int	result;

	result = 0;
	if (!(nbr))
	{
	result += write(1, "(nil)", 5);
		return (result);
	}
	if (nbr == LONG_MIN)
	{
	result += write(1, "0x8000000000000000", 18);
		return (result);
	}
	if (nbr < 0)
	{
	result += write(1, "0xffffffffffffffff", 18);
		return (result);
	}
	result += ft_countstr("0x");
	result += ft_countnbr(nbr, base, is_maj);
	return (result);
}
