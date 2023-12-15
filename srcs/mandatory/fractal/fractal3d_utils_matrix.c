/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:28:15 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/15 16:33:21 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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
			matrix->mat[i][j] = 0.0;
			i++;
		}
		matrix->mat[j][j] = 1.0;
		j++;
	}
}

void	init_vec3d(t_data *img, t_vec3d *angle)
{
	angle->vec[0] = M_PI * img->rotate.x  180;
	angle->vec[1] = M_PI * img->rotate.y  180;
	angle->vec[2] = 0;
}

t_matrix	matrix_multiply(t_matrix mat1, t_matrix mat2)
{
	t_matrix	mat3;
	int			i;
	int			j;
	int			k;

	ft_bzero(&(mat3.mat));
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			k = 0;
			while (k < 3)
			{
				mat3.mat[i][j] += mat1[i][k] * mat2[k][j];
				k++;
			}
			i++;
		}
		j++;
	}
	return (mat3);
}

t_matrix	generate_rotation_matrix(t_vec3d angle, t_matrix matx, \
		t_matrix maty, t_matrix matz)
{
	t_matrix	mat_xy;
	t_matrix	rotation_matrix;

	matx.mat[1][1] = cos(angle.vec[0]);
	matx.mat[1][2] = -sin(angle.vec[0]);
	matx.mat[2][1] = sin(angle.vec[0]);
	matx.mat[2][2] = cos(angle.vec[0]);
	maty.mat[0][0] = cos(angle.vec[1]);
	maty.mat[0][2] = -sin(angle.vec[1]);
	maty.mat[2][0] = sin(angle.vec[1]);
	maty.mat[2][2] = cos(angle.vec[1]);
	matz.mat[0][0] = cos(angle.vec[2]);
	matz.mat[0][1] = -sin(angle.vec[2]);
	matz.mat[1][0] = sin(angle.vec[2]);
	matz.mat[1][1] = cos(angle.vec[2]);
	mat_xy = matrix_multiply(matx, maty);
	rotation_matrix = matrix_multiply(mat_xy, matz);
	return (rotation_matrix);
}

void	matrix_point_multiply(t_data *img, t_matrix matrix, int q)
{
	double	vec[3];
	double	rx;
	double	ry;
	double	rz;
	int		u;

	vec[0] = img->mandelbrot3d_points[q].x;
	vec[1] = img->mandelbrot3d_points[q].y;
	vec[2] = img->mandelbrot3d_points[q].z;
	rx = 0;
	ry = 0;
	rz = 0;
	u = 0;
	while (u < 3)
	{
		rx += matrix.mat[0][u] * vec[u];
		ry += matrix.mat[1][u] * vec[u];
		rz += matrix.mat[2][u] * vec[u];
		u++;
	}
	img->mandelbrot3d_points[q].x = rx;
	img->mandelbrot3d_points[q].y = ry;
	img->mandelbrot3d_points[q].z = rz;
}
