/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_utils_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:16:33 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 15:28:46 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <string.h>

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

void	rotation_per_axis(t_matrix *matx, t_matrix *maty, \
		t_matrix *matz, t_vec3d angle)
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
	int			i;
	int			j;
	int			k;

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
	double	vec[3];
	double	_rx;
	double	_ry;
	double	_rz;
	int		i;

	vec[0] = dots[u].x;
	vec[1] = dots[u].y;
	vec[2] = dots[u].z;
	_rx = 0;
	_ry = 0;
	_rz = 0;
	i = 0;
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
