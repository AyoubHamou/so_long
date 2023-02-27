/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:38:28 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 01:49:40 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int x, int y, t_elts *elts)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		elts->e++;
		map[y][x] = '1';
		return ;
	}
	if (map[y][x] == 'C')
		elts->c++;
	map[y][x] = '1';
	flood_fill(map, x - 1, y, elts);
	flood_fill(map, x, y - 1, elts);
	flood_fill(map, x + 1, y, elts);
	flood_fill(map, x, y + 1, elts);
}

void	valid_path(char **map, t_elts	*elts)
{
	t_elts	*rec_elts;

	rec_elts = malloc(sizeof(t_elts));
	rec_elts->c = 0;
	rec_elts->e = 0;
	flood_fill(map, elts->x, elts->y, rec_elts);
	if (rec_elts->c != elts->c || rec_elts->e != 1)
	{
		free(rec_elts);
		error_message("not a valid path");
	}
	free(rec_elts);
}
