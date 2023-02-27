/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:53:15 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 01:51:32 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_funcs(char **map, t_elts *elts, t_main *main)
{
	main->init = mlx_init();
	main->win = mlx_new_window(main->init, elts->width * 50,
			elts->height * 50, "so_long");
	elts->mv = 0;
	display_map(map, main, elts);
	elts->map = map;
	elts->main = main;
	mlx_hook(main->win, 2, 0, moves, elts);
	mlx_hook(main->win, 17, 0, cross, elts);
	mlx_loop(main->init);
}
