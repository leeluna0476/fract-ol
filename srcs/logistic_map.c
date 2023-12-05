/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:51:22 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/04 15:54:39 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
 * 1. Draw a ball
 * 2. 
 * */

void	draw_ball(t_data *img, /* 좌표*/)
{

}

void	logistic_next(double *x, double r)
{
	*x = r * (*x) * (1 - (*x));
}

void	logistic_map(t_data *img)
{
	double	r;
	double	x;
	int		i;

	r = 1;
	x = 10;
	i = 0;
	while (i < 100)
	{
		printf("(%f, %f)\n", r, x);
		logistic_next(&x, r);
		i++;
	}
}
