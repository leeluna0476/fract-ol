/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:30:00 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/19 20:25:41 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

// idx는 이런 순서다.
// 0번째 열의 0번째 행, 0번째 열의 1번째 행......
// 그런데 일차원 배열이라서 BOXWIDTH로 오프셋을 준 것이다.
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
					((double)(j - BOX_CENTER_Y)) / 400);
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
			BOX_CENTER_X, mandelbrot3d[u].ay + BOX_CENTER_Y);
	if (check_inbox(print_xy) == true)
		my_mlx_pixel_put(img, print_xy.x, print_xy.y, YELLOW);
	init_xy(&print_xy, mandelbrot3d[u].ix + \
			BOX_CENTER_X, mandelbrot3d[u].iy + BOX_CENTER_Y);
	if (check_inbox(print_xy) == true)
		my_mlx_pixel_put(img, print_xy.x, print_xy.y, RED);
	k = 0;
	while (k < 32)
	{
		init_xy(&print_xy, mandelbrot3d[u].x32[k] + BOX_CENTER_X, \
				mandelbrot3d[u].y32[k] + BOX_CENTER_Y);
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
