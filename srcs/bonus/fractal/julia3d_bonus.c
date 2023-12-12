/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:40:24 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 12:12:36 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"
#include <string.h>

bool	all_diverge(t_complex c)
{
	t_complex	z;
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			z.real = (double)(i - (BOX_STD_X + BOXLEFT)) / 300;
			z.imag = (double)(j - (BOX_STD_Y + BOXTOP)) / 300;
			k = -1;
			while (c_abs(z) < 2 && ++k < 400)
				mandelbrot_julia_next(&z, c);
			if (c_abs(z) < 2)
				return (false);
		}
	}
	return (true);
}

int	get_total_slices(t_complex c)
{
	int		slice_num;
	slice_num = 0;
	while (all_diverge(c) == false)
	{
		c.real += SLICE_GAP;
		slice_num++;
	}
	return (slice_num);
}

void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value)
{
	t_complex	z;
	int	i;
	int	j;

	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, (double)(i - (BOX_STD_X + BOXLEFT)) / 300, (double)(j - (BOX_STD_Y + BOXTOP)) / 300);
			iter_complex(&z, c, 10, JULIA);
			if (c_abs(z) < 2)
			{
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + z_value * DOTS_PER_SLICE].x = i - (BOX_STD_X + BOXLEFT);
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + z_value * DOTS_PER_SLICE].y = j - (BOX_STD_Y + BOXTOP);
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + z_value * DOTS_PER_SLICE].z = z_value;
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + z_value * DOTS_PER_SLICE].color = WHITE - z_value * 1000;
			}
			i++;
		}
		j++;
	}
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

void	rotation_per_axis(t_matrix *matx, t_matrix *maty, t_matrix *matz, t_vec3d angle)
{
	matx->mat[1][1] = cos(angle.vec[0]);
	matx->mat[1][2] = -sin(angle.vec[0]);
	matx->mat[2][1] = sin(angle.vec[0]);
	matx->mat[2][2] = cos(angle.vec[0]);
	maty->mat[0][0] = cos(angle.vec[1]);
	maty->mat[0][2] = -sin(angle.vec[1]);
	maty->mat[2][0] = sin(angle.vec[1]);
	maty->mat[2][2] = cos(angle.vec[1]);
	matz->mat[0][0] = cos(angle.vec[2]);
	matz->mat[0][1] = -sin(angle.vec[2]);
	matz->mat[1][0] = sin(angle.vec[2]);
	matz->mat[1][1] = cos(angle.vec[2]);
}

t_matrix	matrix_multiply(t_matrix mat1, t_matrix mat2)
{
	t_matrix	mat3;
	int	i;
	int	j;
	int	k;

	memset(&mat3, 0, sizeof(t_matrix));
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			k = 0;
			while (k < 3)
			{
				mat3.mat[i][j] += mat1.mat[j][i] * mat2.mat[j][k];
				k++;
			}
			i++;
		}
		j++;
	}
	return (mat3);
}

t_matrix	generate_rotation_matrix(t_data *img)
{
	t_matrix	matx;
	t_matrix	maty;
	t_matrix	matz;
	t_matrix	mat_temp;
	t_matrix	mat_rot;
	t_vec3d		angle;

	angle.vec[0] = M_PI * img->rotate.x / 180;
	angle.vec[1] = M_PI * img->rotate.y / 180;
	angle.vec[2] = 0;
	init_matrix(&matx);
	init_matrix(&maty);
	init_matrix(&matz);
	rotation_per_axis(&matx, &maty, &matz, angle);
	mat_temp = matrix_multiply(matx, maty);
	mat_rot = matrix_multiply(mat_temp, matz);
	return (mat_rot);
}

void	matrix_point_multiply(t_matrix mat, t_julia3d *dots, int u)
{
	double vec[3];

	vec[0] = dots[u].x;
	vec[1] = dots[u].y;
	vec[2] = dots[u].z;

	double _rx = 0;
	double _ry = 0;
	double _rz = 0;

	int i = 0;
	while (i < 3)
	{
		_rx += mat.mat[0][i] * vec[i];
		_ry += mat.mat[1][i] * vec[i];
		_rz += mat.mat[2][i] * vec[i];
		i++;
	}
	dots[u].x = _rx;
	dots[u].y = _ry;
	dots[u].z = _rz;
}

void	draw_julia3d(t_data *img, t_julia3d *dots, t_matrix mat_rot, int total_dots)
{
	t_xy	dots_xy;

	int	u = 0;
	while (u < total_dots)
	{
		dots_xy.x = dots[u].x + BOX_STD_X + BOXLEFT;
		dots_xy.y = dots[u].y + BOX_STD_Y + BOXTOP;
		if (check_inbox(dots_xy) == true)
		{
			if (dots[u].color != 0)
			{
				matrix_point_multiply(mat_rot, dots, u);
				my_mlx_pixel_put(img, dots[u].x + BOX_STD_X + BOXLEFT, dots[u].y + BOX_STD_Y + BOXTOP, dots[u].color);
			}
			else
				my_mlx_pixel_put(img, dots[u].x + BOX_STD_X + BOXLEFT, dots[u].y + BOX_STD_Y + BOXTOP, BLACK);
		}
		u++;
	}
}

void	julia3d(t_data *img)
{
	t_julia3d	*dots;
	t_complex	c;
	t_matrix	rotation_matrix;
	int			slices;
	int			total_dots;
	int			z_value;

	init_complex(&c, JULIA_DEF_CR, JULIA_DEF_CI);
	slices = get_total_slices(c);
	total_dots = DOTS_PER_SLICE * slices;
	dots = malloc(total_dots * sizeof(t_julia3d));
	z_value = 0;
	while (all_diverge(c) == false)
	{
		iter_julia3d(dots, c, z_value);
		c.real += SLICE_GAP;
		z_value++;
	}
	rotation_matrix = generate_rotation_matrix(img);
	draw_julia3d(img, dots, rotation_matrix, total_dots);
	free(dots);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
