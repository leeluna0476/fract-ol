/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:23:02 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/16 13:22:29 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

double	c_abs_3d(t_point pt) {
	double	r;
	double	i;

	r = pt.real;
	i = pt.imag;
	return sqrt(r * r + i * i);
}

double	pt_abs(t_point *p)
{
	double	r;
	double	i;

	r = p->real;
	i = p->imag;
	return (sqrt(r * r + i * i));
}

void	next_mandelbrot3d(t_point *p, t_complex c)
{
	double	r;
	double	i;

	r = p->real;
	i = p->imag;
	p->real = r * r - i * i + c.real;
	p->imag = 2 * r * i + c.imag;
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

t_matrix	multiply_matrix(t_matrix mat1, t_matrix mat2)
{
	t_matrix	mat3;
	int			i;
	int			j;
	int			k;

	ft_bzero(&(mat3.mat), sizeof(t_matrix));
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			k = 0;
			while (k < 3)
			{
				mat3.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
				k++;
			}
			i++;
		}
		j++;
	}
	return (mat3);
}

t_matrix	generate_rotation_matrix(t_vec3d angle)
{
	t_matrix	matx;
	t_matrix	maty;
	t_matrix	matz;
	t_matrix	matxy;
	t_matrix	matxyz;

	init_matrix(&matx);
	init_matrix(&maty);
	init_matrix(&matz);
	matx.mat[1][1] = cos(angle.vec[0]);
	matx.mat[1][2] = -sin(angle.vec[0]);
	matx.mat[2][1] = sin(angle.vec[0]);
	matx.mat[2][2] = cos(angle.vec[0]);
	maty.mat[0][0] = cos(angle.vec[1]);
	maty.mat[0][2] = sin(angle.vec[1]);
	maty.mat[2][0] = -sin(angle.vec[1]);
	maty.mat[2][2] = cos(angle.vec[1]);
	matz.mat[0][0] = cos(angle.vec[2]);
	matz.mat[0][1] = -sin(angle.vec[2]);
	matz.mat[1][0] = sin(angle.vec[2]);
	matz.mat[1][1] = cos(angle.vec[2]);
	matxy = multiply_matrix(matx, maty);
	matxyz = multiply_matrix(matxy, matz);
	return (matxyz);
}

void	matrix_point_multiply(t_point *mandelbrot3d, t_matrix rotation_matrix, int q)
{
	double	vec[3];
	double	rx;
	double	ry;
	double	rz;
	double	ix;
	double	iy;
	double	iz;
	double	ax;
	double	ay;
	double	az;
	int		u;

	vec[0] = mandelbrot3d[q].rx;
	vec[1] = mandelbrot3d[q].ry;
	vec[2] = mandelbrot3d[q].rz;
	rx = 0;
	ry = 0;
	rz = 0;
	u = 0;
	while (u < 3)
	{
		rx += rotation_matrix.mat[0][u] * vec[u];
		ry += rotation_matrix.mat[1][u] * vec[u];
		rz += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->rx = rx;
	(&(mandelbrot3d[q]))->ry = ry;
	(&(mandelbrot3d[q]))->rz = rz;
	vec[0] = mandelbrot3d[q].ix;
	vec[1] = mandelbrot3d[q].iy;
	vec[2] = mandelbrot3d[q].iz;
	ix = 0;
	iy = 0;
	iz = 0;
	u = 0;
	while (u < 3)
	{
		ix += rotation_matrix.mat[0][u] * vec[u];
		iy += rotation_matrix.mat[1][u] * vec[u];
		iz += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->ix = ix;
	(&(mandelbrot3d[q]))->iy = iy;
	(&(mandelbrot3d[q]))->iz = iz;
	vec[0] = mandelbrot3d[q].ax;
	vec[1] = mandelbrot3d[q].ay;
	vec[2] = mandelbrot3d[q].az;
	ax = 0;
	ay = 0;
	az = 0;
	u = 0;
	while (u < 3)
	{
		ax += rotation_matrix.mat[0][u] * vec[u];
		ay += rotation_matrix.mat[1][u] * vec[u];
		az += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->ax = ax;
	(&(mandelbrot3d[q]))->ay = ay;
	(&(mandelbrot3d[q]))->az = az;
}

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
				if (pt_abs(&(mandelbrot3d[idx])) >= DIVERGE1)
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
