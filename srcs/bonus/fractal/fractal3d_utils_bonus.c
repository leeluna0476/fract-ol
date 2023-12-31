/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:10:31 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:10:33 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

double	c_abs_3d(t_point point)
{
	double	r;
	double	i;

	r = point.real;
	i = point.imag;
	return (sqrt(r * r + i * i));
}

void	set_values_mandelbrot3d(t_point *mandelbrot3d, int idx, int i, int j)
{
	t_xy	box_xy;
	int		k;

	init_xy(&box_xy, i - BOX_CENTER_X, BOX_CENTER_Y - j);
	mandelbrot3d[idx].real = 0;
	mandelbrot3d[idx].rx = box_xy.x;
	mandelbrot3d[idx].ry = box_xy.y;
	mandelbrot3d[idx].rz = 0;
	mandelbrot3d[idx].imag = 0;
	mandelbrot3d[idx].ix = box_xy.x;
	mandelbrot3d[idx].iy = box_xy.y;
	mandelbrot3d[idx].iz = 0;
	mandelbrot3d[idx].abs = 0;
	mandelbrot3d[idx].ax = box_xy.x;
	mandelbrot3d[idx].ay = box_xy.y;
	mandelbrot3d[idx].az = 0;
	k = 0;
	while (k < 32)
	{
		mandelbrot3d[idx].x32[k] = box_xy.x;
		mandelbrot3d[idx].y32[k] = box_xy.y;
		mandelbrot3d[idx].z32[k] = 0;
		k++;
	}
}

void	generate_new_real32xyz(t_point *mandelbrot3d, t_matrix rotation_matrix)
{
	double	vec[3];
	t_xyz	new;
	int		k;

	k = 0;
	while (k < 32)
	{
		init_vec3d(vec, mandelbrot3d->x32[k], mandelbrot3d->y32[k], \
				mandelbrot3d->z32[k]);
		new = generate_new_xyz(rotation_matrix, vec);
		mandelbrot3d->x32[k] = new.x;
		mandelbrot3d->y32[k] = new.y;
		mandelbrot3d->z32[k] = new.z;
		k++;
	}
}
