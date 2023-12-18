/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:27:28 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/18 10:57:59 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	c_abs_3d(t_point point)
{
	double	r;
	double	i;

	r = point.real;
	i = point.imag;
	return (sqrt(r * r + i * i));
}

void	init_angle(t_vec3d *angle, t_data *img)
{
	angle->vec[0] = M_PI * img->rotate.x / 180;
	angle->vec[1] = M_PI * img->rotate.y / 180;
	angle->vec[2] = 0;
}

void	init_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			matrix->mat[i][j] = 0;
			i++;
		}
		matrix->mat[j][j] = 1;
		j++;
	}
}

void	init_vec3d(double *vector, double x, double y, double z)
{
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

void	set_values_mandelbrot3d(t_point *mandelbrot3d, int idx, int i, int j)
{
	int	x;
	int	y;
	int	k;

	x = i - BOX_CENTER_X;
	y = j - BOX_CENTER_Y;
	mandelbrot3d[idx].real = 0;
	mandelbrot3d[idx].rx = x;
	mandelbrot3d[idx].ry = y;
	mandelbrot3d[idx].rz = 0;
	mandelbrot3d[idx].imag = 0;
	mandelbrot3d[idx].ix = x;
	mandelbrot3d[idx].iy = y;
	mandelbrot3d[idx].iz = 0;
	mandelbrot3d[idx].abs = 0;
	mandelbrot3d[idx].ax = x;
	mandelbrot3d[idx].ay = y;
	mandelbrot3d[idx].az = 0;
	k = 0;
	while (k < 32)
	{
		mandelbrot3d[idx].x32[k] = x;
		mandelbrot3d[idx].y32[k] = y;
		mandelbrot3d[idx].z32[k] = 0;
		k++;
	}
}
