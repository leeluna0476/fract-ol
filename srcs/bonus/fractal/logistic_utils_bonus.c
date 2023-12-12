/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:41:09 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:41:13 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

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
