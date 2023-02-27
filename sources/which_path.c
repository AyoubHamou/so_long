/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:59:23 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 17:17:00 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*which_path(char c)
{
	if (c == 'P')
		return ("textures/p.xpm");
	if (c == 'E')
		return ("textures/e.xpm");
	if (c == '0')
		return ("textures/0.xpm");
	if (c == '1')
		return ("textures/1.xpm");
	if (c == 'C')
		return ("textures/c.xpm");
	return (NULL);
}
