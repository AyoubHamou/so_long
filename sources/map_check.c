/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:08:57 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 21:02:54 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if ((!ft_strrchr(s, '/') && ft_strlen(s) == 4)
		|| ft_strlen(ft_strrchr(s, '/')) == 5)
		error_message("Error : invalid name");
	if (ft_strncmp(".ber", &s[len - 4], 4))
		error_message("Error : use the \".ber\" extension");
}

char	**read_map(char *av, int i)
{
	char	*str;
	char	**map;
	int		fd;

	i = 0;
	check_ber(av);
	fd = open (av, O_RDONLY);
	if (fd == -1)
		error_message("Error : Can't open the file");
	str = read_line(fd);
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] == '\n' && str[i + 1] == '\0'))
			error_message("wrong map");
		i++;
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

size_t	map_lenght(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			error_message("shape is not ok");
		i++;
	}
	return (len);
}

void	map_characters(char **map, int i, t_elts *elts)
{
	int	j;
	int	p;

	elts->c = 0;
	elts->e = 0;
	p = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				elts->c++;
			else if (map[i][j] == 'E')
				elts->e++;
			else if (map[i][j] == 'P')
			{
				elts->x = j;
				elts->y = i;
				p++;
			}
		}
	}
	if (elts->e != 1 || p != 1 || elts->c < 1)
		error_message("Error : more than 1 P or 1 E / less than 1 C");
}

void	map_borders(char **map, size_t len, t_elts *elts)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][len] != '1' )
			error_message("wall problem");
	elts->height = i;
	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			error_message("wall problem");
	elts->width = j;
	j = -1;
	while (map[i - 1][++j])
		if (map[i - 1][j] != '1')
			error_message("wall problem");
}
