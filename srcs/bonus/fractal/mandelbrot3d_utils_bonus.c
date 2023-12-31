/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:12:49 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:12:53 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	set_mandelbrot3d_height(t_point *mandelbrot3d, t_complex z_value)
{
	mandelbrot3d->rz = z_value.real;
	mandelbrot3d->iz = z_value.imag;
	mandelbrot3d->az = sqrt(z_value.real * z_value.real + \
			z_value.imag * z_value.imag);
}

void	if_converge(t_point *mandelbrot3d, int idx, double abs)
{
	if (abs < DIVERGE1)
	{
		mandelbrot3d[idx].rcolor = BLUE;
		mandelbrot3d[idx].icolor = RED;
		mandelbrot3d[idx].acolor = YELLOW;
	}
	else
		mandelbrot3d[idx].rcolor = BLACK;
}

void	generate_mandelbrot3d(t_point *mandelbrot3d)
{
	t_complex	c;
	t_complex	z_value;
	int			idx;
	int			i;
	int			j;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			idx = (i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH;
			set_values_mandelbrot3d(mandelbrot3d, idx, i, j);
			init_complex(&c, ((double)(i - BOX_CENTER_X)) / 400, \
					((double)(BOX_CENTER_Y - j)) / 400);
			iter_mandelbrot3d(mandelbrot3d, idx, c);
			init_complex(&z_value, mandelbrot3d[idx].real * 200, \
					mandelbrot3d[idx].imag * 200);
			set_mandelbrot3d_height(&(mandelbrot3d[idx]), z_value);
			if_converge(mandelbrot3d, idx, c_abs_3d(mandelbrot3d[idx]));
			i++;
		}
		j++;
	}
}

void	check_and_draw(t_data *img, t_point *mandelbrot3d, int u)
{
	t_xy	print_xy;
	int		k;

	init_xy(&print_xy, mandelbrot3d[u].ax + \
			BOX_CENTER_X, BOX_CENTER_Y - mandelbrot3d[u].ay);
	if (check_inbox(print_xy) == true)
		my_mlx_pixel_put(img, print_xy.x, print_xy.y, YELLOW);
	init_xy(&print_xy, mandelbrot3d[u].ix + \
			BOX_CENTER_X, BOX_CENTER_Y - mandelbrot3d[u].iy);
	if (check_inbox(print_xy) == true)
		my_mlx_pixel_put(img, print_xy.x, print_xy.y, RED);
	k = 0;
	while (k < 32)
	{
		init_xy(&print_xy, mandelbrot3d[u].x32[k] + BOX_CENTER_X, \
				BOX_CENTER_Y - mandelbrot3d[u].y32[k]);
		if (check_inbox(print_xy) == true)
		{
			my_mlx_pixel_put(img, print_xy.x, print_xy.y, BLUE);
			if (mandelbrot3d[u].imag == 0)
				my_mlx_pixel_put(img, print_xy.x, print_xy.y, WHITE);
		}
		k++;
	}
}

void	draw_mandelbrot3d(t_data *img, t_point *mandelbrot3d, \
		t_matrix rotation_matrix)
{
	int		u;

	u = 0;
	while (u < TOTAL_DOTS)
	{
		if (mandelbrot3d[u].rcolor == BLUE)
		{
			matrix_point_multiply(mandelbrot3d, rotation_matrix, u);
			check_and_draw(img, mandelbrot3d, u);
		}
		u++;
	}
}
