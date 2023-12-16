/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:34:03 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/16 14:59:18 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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
	double	nx;
	double	ny;
	double	nz;
	int		u;

	init_vec3d(vec, mandelbrot3d[q].rx, mandelbrot3d[q].ry, mandelbrot3d[q].rz);
	nx = 0;
	ny = 0;
	nz = 0;
	u = 0;
	while (u < 3)
	{
		nx += rotation_matrix.mat[0][u] * vec[u];
		ny += rotation_matrix.mat[1][u] * vec[u];
		nz += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->rx = nx;
	(&(mandelbrot3d[q]))->ry = ny;
	(&(mandelbrot3d[q]))->rz = nz;
	init_vec3d(vec, mandelbrot3d[q].ix, mandelbrot3d[q].iy, mandelbrot3d[q].iz);
	nx = 0;
	ny = 0;
	nz = 0;
	u = 0;
	while (u < 3)
	{
		nx += rotation_matrix.mat[0][u] * vec[u];
		ny += rotation_matrix.mat[1][u] * vec[u];
		nz += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->ix = nx;
	(&(mandelbrot3d[q]))->iy = ny;
	(&(mandelbrot3d[q]))->iz = nz;
	init_vec3d(vec, mandelbrot3d[q].ax, mandelbrot3d[q].ay, mandelbrot3d[q].az);
	nx = 0;
	ny = 0;
	nz = 0;
	u = 0;
	while (u < 3)
	{
		nx += rotation_matrix.mat[0][u] * vec[u];
		ny += rotation_matrix.mat[1][u] * vec[u];
		nz += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	(&(mandelbrot3d[q]))->ax = nx;
	(&(mandelbrot3d[q]))->ay = ny;
	(&(mandelbrot3d[q]))->az = nz;
}
