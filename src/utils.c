/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:11:53 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/11 09:11:38 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t	n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (!s2_len)
		return ((char *)s1);
	if (n != 0)
	{
		while (s1[i] && i <= n - s2_len)
		{
			j = 0;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (j == s2_len)
				return ((char *)&s1[i]);
			i++;
		}
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*dup;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*tab;
	size_t		cpt;
	size_t		taille;

	if (!count || !size)
	{
		tab = malloc(0);
		if (!tab)
			return (0);
		return (tab);
	}
	taille = size * count;
	if (taille / count != size)
		return (0);
	cpt = 0;
	tab = malloc(taille);
	if (!tab)
		return (0);
	while (cpt < taille)
	{
		((char *)tab)[cpt] = 0;
		cpt++;
	}
	return (tab);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (!dest || !src)
		return (0);
	index = 0;
	if (size != 0)
	{
		while (index < size - 1 && *src)
		{
			*dest = *src;
			dest++;
			src++;
			index++;
		}
		*dest = '\0';
	}
	while (*src++)
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*s3;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = ft_calloc(s1_len + s2_len + 1, 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s3);
}
