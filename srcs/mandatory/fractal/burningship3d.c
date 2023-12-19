/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:53:14 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/19 22:25:42 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	on_sphere(double x, double y)
{
	if (sqrt(x * x + y * y) <= RADIUS)
		return (true);
	return (false);
}

void	burningship3d(t_data *img)
{
	t_xy		plane;
	t_xyz		sphere;
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;
	int			k;
	double		phi;
	double		theta;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			if (on_sphere(BOX_CENTER_X - i, BOX_CENTER_Y - j) == true)
			{
				phi = acos((double)(j - BOX_CENTER_Y) / RADIUS);
				theta = acos((double)(i - BOX_CENTER_X) / (RADIUS * sin(phi)));
				sphere.x = RADIUS * sin(phi) * cos(theta);
				sphere.y = RADIUS * sin(phi) * sin(theta);
				sphere.z = RADIUS * cos(phi);
				plane.x = sphere.x / (1 - sphere.z);
				plane.y = sphere.y / (1 - sphere.z);
				init_complex(&c, plane.x - img->rotate.x / 100, plane.y - img->rotate.y / 100);
				init_complex(&z, 0, 0);
				k = 0;
				while (k < 100)
				{
					burningship_next(&z, c);
					k++;
				}
				if (c_abs(z) < DIVERGE1)
					my_mlx_pixel_put(img, i, j, WHITE);
				else
					my_mlx_pixel_put(img, i, j, RED);
			}
			else
				my_mlx_pixel_put(img, i, j, BLACK);
			i++;
		}
		j++;
	}
}
