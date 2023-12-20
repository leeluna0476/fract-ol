/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_recurrence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:14:57 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/20 09:21:22 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	next_mandelbrot3d(t_point *p, t_complex c, int k)
{
	double	r;
	double	i;

	r = p->real;
	i = p->imag;
	p->real = r * r - i * i + c.real;
	p->imag = 2 * r * i + c.imag;
	p->z32[k % 32] = p->real * 200;
}

void	iter_mandelbrot3d(t_point *mandelbrot3d, int idx, t_complex c)
{
	int	k;

	k = 0;
	while (k < ITER)
	{
		next_mandelbrot3d(&(mandelbrot3d[idx]), c, k);
		if (c_abs_3d(mandelbrot3d[idx]) >= DIVERGE1)
			break ;
		k++;
	}
}

void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value)
{
	t_complex	z;
	int			i;
	int			j;
	int			current_idx;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			init_complex(&z, (double)(i - BOX_CENTER_X) / 300, \
					(double)(j - BOX_CENTER_Y) / 300);
			iter_complex(&z, c, ITER_SMALL, JULIA);
			current_idx = (i - BOXLEFT) + (j - BOXTOP) * \
					BOXWIDTH + z_value * DOTS_PER_SLICE;
			if (c_abs(z) < 2)
				set_dot_values(&dots[current_idx], \
					i - BOX_CENTER_X, j - BOX_CENTER_Y, z_value);
			i++;
		}
		j++;
	}
}
