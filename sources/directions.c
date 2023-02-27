/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:34:12 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 21:50:41 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(char *str, int n)
{
	write(1, str, ft_strlen(str));
	ft_putnbr(n);
	write(1, "\n", 1);
}

int	ft_up(t_elts *elts)
{
	if (elts->map[elts->y - 1][elts->x] == '1')
		return (0);
	else if (elts->map[elts->y - 1][elts->x] == 'C')
	{
		elts->map[elts->y - 1][elts->x] = '0';
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y - 1][elts->x]);
		elts->c--;
		elts->y--;
		elts->mv++;
		ft_print("UP : ", elts->mv);
	}
	else if (elts->map[elts->y - 1][elts->x] == 'E' && elts->c == 0)
	{
		write(1, "===CONGRATS YOU WIN===\n", 23);
		exit (0);
	}
	else if (elts->map[elts->y - 1][elts->x] == '0')
	{
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y - 1][elts->x]);
		elts->y--;
		elts->mv++;
		ft_print("UP : ", elts->mv);
	}
	return (0);
}

int	ft_down(t_elts *elts)
{
	if (elts->map[elts->y + 1][elts->x] == '1')
		return (0);
	else if (elts->map[elts->y + 1][elts->x] == 'C')
	{
		elts->map[elts->y + 1][elts->x] = '0';
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y + 1][elts->x]);
		elts->c--;
		elts->y++;
		elts->mv++;
		ft_print("DOWN : ", elts->mv);
	}
	else if (elts->map[elts->y + 1][elts->x] == 'E' && elts->c == 0)
	{
		write(1, "===CONGRATS YOU WIN===\n", 23);
		exit (0);
	}
	else if (elts->map[elts->y + 1][elts->x] == '0')
	{
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y + 1][elts->x]);
		elts->y++;
		elts->mv++;
		ft_print("DOWN : ", elts->mv);
	}
	return (0);
}

int	ft_right(t_elts *elts)
{
	if (elts->map[elts->y][elts->x + 1] == '1')
		return (0);
	else if (elts->map[elts->y][elts->x + 1] == 'C')
	{
		elts->map[elts->y][elts->x + 1] = '0';
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y][elts->x + 1]);
		elts->c--;
		elts->x++;
		elts->mv++;
		ft_print("RIGHT : ", elts->mv);
	}
	else if (elts->map[elts->y][elts->x + 1] == 'E' && elts->c == 0)
	{
		write(1, "===CONGRATS YOU WIN===\n", 23);
		exit (0);
	}
	else if (elts->map[elts->y][elts->x + 1] == '0')
	{
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y][elts->x + 1]);
		elts->x++;
		elts->mv++;
		ft_print("RIGHT : ", elts->mv);
	}
	return (0);
}

int	ft_left(t_elts *elts)
{
	if (elts->map[elts->y][elts->x - 1] == '1')
		return (0);
	else if (elts->map[elts->y][elts->x - 1] == 'C')
	{
		elts->map[elts->y][elts->x - 1] = '0';
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y][elts->x - 1]);
		elts->c--;
		elts->x--;
		elts->mv++;
		ft_print("LEFT : ", elts->mv);
	}
	else if (elts->map[elts->y][elts->x - 1] == 'E' && elts->c == 0)
	{
		write(1, "===CONGRATS YOU WIN===\n", 23);
		exit (0);
	}
	else if (elts->map[elts->y][elts->x - 1] == '0')
	{
		ft_swap(&elts->map[elts->y][elts->x], &elts->map[elts->y][elts->x - 1]);
		elts->x--;
		elts->mv++;
		ft_print("LEFT : ", elts->mv);
	}
	return (0);
}
