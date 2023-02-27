/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:45:31 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/24 22:42:31 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free_buffer(char *copy, char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
	free (copy);
	return (NULL);
}

char	*read_line(int fd)
{
	char		*copy;
	char		*str;
	ssize_t		n;

	str = NULL;
	copy = malloc (sizeof(char) * 2);
	if (!copy)
		return (NULL);
	n = 1337;
	while (n > 0)
	{
		n = read(fd, copy, 1);
		if (n < 0)
			return (ft_free_buffer(copy, &str));
		copy[n] = '\0';
		str = ft_strjoin(str, copy);
		if (!str)
			return (ft_free_buffer(copy, &str));
		if (str[0] == '\0')
			return (ft_free_buffer(copy, &str));
	}
	free (copy);
	return (str);
}
