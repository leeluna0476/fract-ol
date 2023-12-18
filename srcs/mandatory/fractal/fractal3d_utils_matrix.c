/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:34:03 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/18 11:11:10 by seojilee         ###   ########.fr       */
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
	maty.mat[0][2] = -sin(angle.vec[1]);
	maty.mat[2][0] = sin(angle.vec[1]);
	maty.mat[2][2] = cos(angle.vec[1]);
	matz.mat[0][0] = cos(angle.vec[2]);
	matz.mat[0][1] = -sin(angle.vec[2]);
	matz.mat[1][0] = sin(angle.vec[2]);
	matz.mat[1][1] = cos(angle.vec[2]);
	matxy = multiply_matrix(matx, maty);
	matxyz = multiply_matrix(matxy, matz);
	return (matxyz);
}

void	init_xyz(t_xyz *xyz, int x, int y, int z)
{
	xyz->x = x;
	xyz->y = y;
	xyz->z = z;
}

// vec[3]는 기존 좌표.
// 기존 좌표에 회전행렬을 곱해서 새로운 좌표를 구하는 부분.
// x축 기준으로 회전할 때는 x좌표는 변하지 않고
	// (x축 기준으로 들어오는 angle.vec[0]은 x좌표에 적용하지 않는다.)
// y축 기준으로 회전할 때는 y좌표는 변하지 않고
	// (y축 기준으로 들어오는 angle.vec[1]은 y좌표에 적용하지 않는다.)
// z축 기준으로 회전할 때는 z좌표는 변하지 않는다.
	// (z축 기준으로 들어오는 angle.vec[2]은 z좌표에 적용하지 않는다.)
	// 그치만 난 z축 기준으로는 회전하지 않는걸
t_xyz	generate_new_xyz(t_matrix rotation_matrix, double vec[3])
{
	t_xyz	new;
	int		u;

	init_xyz(&new, 0, 0, 0);
	u = 0;
	while (u < 3)
	{
		new.x += rotation_matrix.mat[0][u] * vec[u];
		new.y += rotation_matrix.mat[1][u] * vec[u];
		new.z += rotation_matrix.mat[2][u] * vec[u];
		u++;
	}
	return (new);
}

void	matrix_point_multiply(t_point *mandelbrot3d, \
		t_matrix rotation_matrix, int q)
{
	double	vec[3];
	t_xyz	new;

	init_vec3d(vec, mandelbrot3d[q].rx, mandelbrot3d[q].ry, mandelbrot3d[q].rz);
	new = generate_new_xyz(rotation_matrix, vec);
	(&(mandelbrot3d[q]))->rx = new.x;
	(&(mandelbrot3d[q]))->ry = new.y;
	(&(mandelbrot3d[q]))->rz = new.z;
	init_vec3d(vec, mandelbrot3d[q].ix, mandelbrot3d[q].iy, mandelbrot3d[q].iz);
	new = generate_new_xyz(rotation_matrix, vec);
	(&(mandelbrot3d[q]))->ix = new.x;
	(&(mandelbrot3d[q]))->iy = new.y;
	(&(mandelbrot3d[q]))->iz = new.z;
	init_vec3d(vec, mandelbrot3d[q].ax, mandelbrot3d[q].ay, mandelbrot3d[q].az);
	new = generate_new_xyz(rotation_matrix, vec);
	(&(mandelbrot3d[q]))->ax = new.x;
	(&(mandelbrot3d[q]))->ay = new.y;
	(&(mandelbrot3d[q]))->az = new.z;
	for (int i = 0; i < 32; i++)
	{
		init_vec3d(vec, mandelbrot3d[q].x32[i], mandelbrot3d[q].y32[i], mandelbrot3d[q].z32[i]);
		new = generate_new_xyz(rotation_matrix, vec);
		mandelbrot3d[q].x32[i] = new.x;
		mandelbrot3d[q].y32[i] = new.y;
		mandelbrot3d[q].z32[i] = new.z;
	}
}
