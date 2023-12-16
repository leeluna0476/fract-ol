/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_recurrence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:14:57 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/16 16:24:33 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	next_mandelbrot3d(t_point *p, t_complex c)
{
	double	r;
	double	i;

	r = p->real;
	i = p->imag;
	p->real = r * r - i * i + c.real;
	p->imag = 2 * r * i + c.imag;
}

void	iter_mandelbrot3d(t_point *mandelbrot3d, int idx, t_complex c)
{
	int	k;

	k = 0;
	while (k < ITER)
	{
		next_mandelbrot3d(&(mandelbrot3d[idx]), c);
		if (c_abs_3d(mandelbrot3d[idx]) >= DIVERGE1)
			break ;
		k++;
	}
}

void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value)
{
	t_xy		box_std;
	t_complex	z;
	int			i;
	int			j;
	int			current_idx;

	init_xy(&box_std, BOX_STD_X + BOXLEFT, BOX_STD_Y + BOXTOP);
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, (double)(i - box_std.x) / 300, \
					(double)(j - box_std.y) / 300);
			iter_complex(&z, c, 100, JULIA);
			current_idx = (i - BOXLEFT) + (j - BOXTOP) * \
					BOXWIDTH + z_value * DOTS_PER_SLICE;
			if (c_abs(z) < 2)
				set_dot_values(&dots[current_idx], \
					i - box_std.x, j - box_std.y, z_value);
			i++;
		}
		j++;
	}
}
