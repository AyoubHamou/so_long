/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:48:06 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 17:34:37 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	main(int ac, char **av)
{
	char	**map;
	size_t	len;
	int		i;
	t_elts	*elts;
	t_main	*main;

	elts = malloc(sizeof(t_elts));
	main = malloc (sizeof(t_main));
	i = 0;
	if (ac != 2)
		error_message("Error : ./so_long maps/map.ber");
	map = read_map(av[1], i);
	if (!map)
		error_message("invalid map");
	i = -1;
	len = map_lenght(map) - 1;
	map_characters(map, i, elts);
	map_borders(map, len, elts);
	valid_path(map, elts);
	ft_free(map);
	map = read_map(av[1], i);
	mlx_funcs(map, elts, main);
}
