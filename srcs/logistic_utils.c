/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:33 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/05 14:24:39 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	make_box_black(t_data *img)
{
	for (int j = BOXTOP; j <= BOXBOT; j++)
	{
		for (int i = BOXLEFT; i <= BOXRIGHT; i++)
		{
			my_mlx_pixel_put(img, i, j, BLACK);
		}
	}
}

void logistic_next(double r, double *x)
{
    double    _x;

    _x = *x;
    *x = r * _x * (1 - _x);
}

