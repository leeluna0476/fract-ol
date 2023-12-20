/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_stereographic_projection.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:11:53 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/20 11:15:19 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	on_sphere(double x, double y)
{
	if (sqrt(x * x + y * y) <= RADIUS)
		return (true);
	return (false);
}

void	stereographic_projection(t_burningship3d *burn, int i, int j)
{
	burn->phi = acos((double)(j - BOX_CENTER_Y) / RADIUS);
	burn->theta = acos((double)(i - BOX_CENTER_X) / (RADIUS * sin(burn->phi)));
	init_xyz(&(burn->sphere), sin(burn->phi) * cos(burn->theta), \
			sin(burn->phi) * sin(burn->theta), cos(burn->phi));
	init_xy(&(burn->plane), burn->sphere.x / (1 - burn->sphere.z), \
			burn->sphere.y / (1 - burn->sphere.z));
}

void	draw_burningship3d(t_data *img, double z_abs, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, WHITE);
	else
		my_mlx_pixel_put(img, i, j, RED);
}

double	generate_burningship3d(t_data *img, int i, int j)
{
	t_burningship3d	burn;
	t_complex		z;
	t_complex		c;

	stereographic_projection(&burn, i, j);
	init_complex(&c, burn.plane.x - img->rotate.x / 100, \
			burn.plane.y - img->rotate.y / 100);
	init_complex(&z, 0, 0);
	iter_complex(&z, c, ITER, BURNINGSHIP);
	return (c_abs(z));
}
