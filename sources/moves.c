/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:41:45 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 21:51:35 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int key, t_elts *elts)
{
	if (key == 53)
	{
		write(1, "===YOU LOSE===\n", 15);
		exit(0);
	}
	if (key == 126)
		ft_up(elts);
	if (key == 125)
		ft_down(elts);
	if (key == 124)
		ft_right(elts);
	if (key == 123)
		ft_left(elts);
	mlx_clear_window(elts->main->init, elts->main->win);
	display_map(elts->map, elts->main, elts);
	return (0);
}

int	cross(void *b)
{
	(void)b;
	write(1, "===YOU LOSE===\n", 15);
	exit(0);
}
