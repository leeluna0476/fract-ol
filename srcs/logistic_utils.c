/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:33 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 16:19:54 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	check_inbox(t_xy xy)
{
	if (xy.x >= BOXLEFT && xy.x <= BOXRIGHT)
	{
		if (xy.y >= BOXTOP && xy.y <= BOXBOT)
			return (true);
	}
	return (false);
}

void	make_box_black(t_data *img)
{
	int	i;
	int	j;

	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			my_mlx_pixel_put(img, i, j, BLACK);
			i++;
		}
		j++;
	}
}

void	logistic_next(double r, double *x)
{
	double	_x;

	_x = *x;
	*x = r * _x * (1 - _x);
}
