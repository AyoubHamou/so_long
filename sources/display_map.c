/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:24:15 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 20:52:58 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(char **map, t_main *main, t_elts *elts)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	i = 0;
	(void)elts;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			main->img = mlx_xpm_file_to_image(main->init,
					which_path(map[i][j]), &n, &n);
			if (!main->img)
				exit (1);
			mlx_put_image_to_window(main->init, main->win,
				main->img, j * 50, i * 50);
			j++;
		}
		i++;
	}
	str = ft_itoa(elts->mv);
	mlx_string_put(main->init, main->win, 20, 20, 0x0000FF00, str);
	free(str);
}
