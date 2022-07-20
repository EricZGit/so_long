/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:20:50 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/06 10:50:49 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char str, va_list argument)
{
	int	result;

	result = 0;
	if (str == 'c')
		result += ft_countchar(va_arg(argument, int));
	else if (str == 's')
		result += ft_countstr(va_arg(argument, char *));
	else if (str == 'd' || str == 'i')
		result += ft_countnbr(va_arg(argument, int), 10, 0);
	else if (str == 'x')
		result += ft_countnbr(va_arg(argument, unsigned int), 16, 0);
	else if (str == 'X')
		result += ft_countnbr(va_arg(argument, unsigned int), 16, 1);
	else if (str == 'u')
		result += ft_countnbr(va_arg(argument, unsigned int), 10, 0);
	else if (str == 'p')
		result += ft_countpointer(va_arg(argument, unsigned long int), 16, 0);
	else if (str == '%')
		result += ft_countchar('%');
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list		argument;
	int			result;

	result = 0;
	va_start(argument, str);
	while (*str)
	{
		if (*str == '%')
		{
			result += ft_control(*(str + 1), argument);
			str++;
		}
		else
			result += ft_countchar(*str);
		str++;
	}
	va_end(argument);
	return (result);
}
