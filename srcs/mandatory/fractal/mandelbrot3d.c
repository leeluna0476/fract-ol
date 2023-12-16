/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:23:02 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/16 14:34:45 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot3d(t_data *img)
{
	t_xy		print_xy;
	t_point		*mandelbrot3d;
	t_vec3d		angle;
	t_matrix	rotation_matrix;
	t_complex	c;
	double		rz;
	double		iz;
	int			i;
	int			j;
	int			k;
	int			u;
	int			idx;

	mandelbrot3d = malloc(TOTAL_DOTS * sizeof(t_point));
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			idx = (i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH;
			mandelbrot3d[idx].real = 0;
			mandelbrot3d[idx].rx = i - BOX_CENTER_X;
			mandelbrot3d[idx].ry = j - BOX_CENTER_Y;
			mandelbrot3d[idx].rz = 0;
			mandelbrot3d[idx].imag = 0;
			mandelbrot3d[idx].ix = i - BOX_CENTER_X;
			mandelbrot3d[idx].iy = j - BOX_CENTER_Y;
			mandelbrot3d[idx].iz = 0;
			mandelbrot3d[idx].abs = 0;
			mandelbrot3d[idx].ax = i - BOX_CENTER_X;
			mandelbrot3d[idx].ay = j - BOX_CENTER_Y;
			mandelbrot3d[idx].az = 0;
			init_complex(&c, ((double)(i - BOX_CENTER_X)) / 400, ((double)(j - BOX_CENTER_Y)) / 400);
			k = 0;
			while (k < ITER)
			{
				next_mandelbrot3d(&(mandelbrot3d[idx]), c);
				if (c_abs_3d(mandelbrot3d[idx]) >= DIVERGE1)
					break ;
				k++;
			}
			rz = mandelbrot3d[idx].real * 200;
			iz = mandelbrot3d[idx].imag * 200;
			mandelbrot3d[idx].rz = rz;
			mandelbrot3d[idx].iz = iz;
			mandelbrot3d[idx].az = sqrt(rz * rz + iz * iz);
			if (c_abs_3d(mandelbrot3d[idx]) < DIVERGE1)
			{
				mandelbrot3d[idx].rcolor = BLUE;
				mandelbrot3d[idx].icolor = RED;
				mandelbrot3d[idx].acolor = GREEN;
			}
			else
				mandelbrot3d[idx].rcolor = BLACK;
			i++;
		}
		j++;
	}
	init_angle(&angle, img);
	rotation_matrix = generate_rotation_matrix(angle);

	make_box_black(img);

	u = 0;
	while (u < TOTAL_DOTS)
	{
		// 수렴한다면
		if (mandelbrot3d[u].rcolor == BLUE)
		{
			matrix_point_multiply(mandelbrot3d, rotation_matrix, u);
			init_xy(&print_xy, mandelbrot3d[u].ix + BOX_CENTER_X, mandelbrot3d[u].iy + BOX_CENTER_Y);
			if (check_inbox(print_xy) == true)
				my_mlx_pixel_put(img, mandelbrot3d[u].ix + BOX_CENTER_X, mandelbrot3d[u].iy + BOX_CENTER_Y, RED);
			init_xy(&print_xy, mandelbrot3d[u].ax + BOX_CENTER_X, mandelbrot3d[u].ay + BOX_CENTER_Y);
			if (check_inbox(print_xy) == true)
				my_mlx_pixel_put(img, mandelbrot3d[u].ax + BOX_CENTER_X, mandelbrot3d[u].ay + BOX_CENTER_Y, YELLOW);
			init_xy(&print_xy, mandelbrot3d[u].rx + BOX_CENTER_X, mandelbrot3d[u].ry + BOX_CENTER_Y);
			if (check_inbox(print_xy) == true)
				my_mlx_pixel_put(img, mandelbrot3d[u].rx + BOX_CENTER_X, mandelbrot3d[u].ry + BOX_CENTER_Y, BLUE);
		}
		u++;
	}
	free(mandelbrot3d);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
