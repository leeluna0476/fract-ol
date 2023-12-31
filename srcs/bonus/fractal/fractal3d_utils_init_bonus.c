/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_init_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:10:39 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:10:43 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

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
