/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:55:17 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/18 08:55:24 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	ft_len(const char *str, char c)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != c)
		{
			size++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (size);
}

static char	*ft_word(char const *s, char c)
{
	char		*result;
	const char	*ptr;
	size_t		len;

	ptr = s;
	len = 0;
	while (*ptr && *ptr++ != c)
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, len + 1);
	return (result);
}

char	**free_split(char **str)
{
	size_t	index;

	index = 0;
	while (str[index])
		free(str[index++]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		index;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (ft_len(s, c) + 1));
	if (!result)
		exit(1);
	index = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			result[index] = ft_word(s, c);
			if (!result[index++])
				return (free_split(result));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[index] = 0;
	return (result);
}
