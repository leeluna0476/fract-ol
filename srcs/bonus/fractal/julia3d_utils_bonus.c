/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:12:08 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:12:15 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

bool	all_diverge(t_complex c)
{
	t_complex	z;
	int			i;
	int			j;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			init_complex(&z, (double)(i - BOX_CENTER_X) / 300, \
					(double)(BOX_CENTER_Y - j) / 300);
			iter_complex(&z, c, ITER_SMALL, JULIA);
			if (c_abs(z) < 2)
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

int	get_total_slices(t_complex c)
{
	int	slice_num;

	slice_num = 0;
	while (all_diverge(c) == false)
	{
		c.real += SLICE_GAP;
		slice_num++;
	}
	return (slice_num);
}

void	set_dot_values(t_julia3d *dot, int x_value, int y_value, int z_value)
{
	dot->x = x_value;
	dot->y = y_value;
	dot->z = z_value;
	dot->color = WHITE - z_value * 1000;
}

int	find_layer(t_data *img, t_julia3d *dots)
{
	int	i;

	i = img->last_layer * DOTS_PER_SLICE;
	while (i >= 0)
	{
		if (img->mouse.x == dots[i].x + (BOX_CENTER_X) && \
				img->mouse.y == (BOX_CENTER_Y) - dots[i].y)
			break ;
		i--;
	}
	if (i < 0)
		return (dots->last_layer);
	return (dots[i].z);
}

void	draw_julia3d(t_data *img, t_julia3d *dots, \
		int total_dots)
{
	t_xy	dots_xy;
	int		u;

	u = 0;
	if (img->layer == true)
		img->last_layer = find_layer(img, dots);
	else
		img->last_layer = dots->last_layer;
	while (u < total_dots)
	{
		dots_xy.x = dots[u].x + BOX_CENTER_X;
		dots_xy.y = BOX_CENTER_Y - dots[u].y;
		if (check_inbox(dots_xy) == true)
		{
			if (dots[u].color != 0)
			{
				if (dots[u].z <= img->last_layer)
					my_mlx_pixel_put(img, dots_xy.x, dots_xy.y, dots[u].color);
			}
			else
				my_mlx_pixel_put(img, dots_xy.x, dots_xy.y, BLACK);
		}
		u++;
	}
}
