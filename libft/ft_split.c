/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:20:23 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/24 22:40:22 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_wc(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (k);
}

static void	*ft_free_tab(char	**strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}

char	**ft_alloc(char *s, char c)
{
	char	**strs;

	strs = ft_calloc((ft_wc(s, c) + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	return (strs);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s || !s[0])
		return (NULL);
	strs = ft_alloc(s, c);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[j])
		{
			strs[k] = ft_substr(s, j, i - j);
			if (!strs[k++])
				return (ft_free_tab(strs));
		}
	}
	return (strs);
}
