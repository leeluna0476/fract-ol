/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:21:22 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 20:45:18 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	draw_julia3d(t_data *img, t_julia3d *dots, \
		int total_dots)
{
	t_xy	dots_xy;
	int		u;
	int		layer;

	u = 0;
	if (img->layer == true)
	{
		layer = find_layer(img, dots, total_dots);
	}
	else
	{
		layer = dots->last_layer;
	}
	while (u < total_dots)
	{
		dots_xy.x = dots[u].x + BOX_STD_X + BOXLEFT;
		dots_xy.y = dots[u].y + BOX_STD_Y + BOXTOP;
		if (check_inbox(dots_xy) == true)
		{
			if (dots[u].color != 0)
			{
				if (dots[u].z <= layer)
					my_mlx_pixel_put(img, dots[u].x + BOX_STD_X + BOXLEFT, \
							dots[u].y + BOX_STD_Y + BOXTOP, dots[u].color);
			}
			else
				my_mlx_pixel_put(img, dots[u].x + BOX_STD_X + BOXLEFT, \
						dots[u].y + BOX_STD_Y + BOXTOP, BLACK);
		}
		u++;
	}
}

void	julia3d(t_data *img)
{
	t_julia3d	*dots;
	t_complex	c;
	int			total_dots;
	int			z_value;

	make_box_black(img);
	init_complex(&c, JULIA_DEF_CR, JULIA_DEF_CI);
	total_dots = DOTS_PER_SLICE * get_total_slices(c);
	dots = malloc(total_dots * sizeof(t_julia3d));
	dots->last_layer = 0;
	z_value = 0;
	while (all_diverge(c) == false)
	{
		iter_julia3d(dots, c, z_value);
		c.real += SLICE_GAP;
		z_value++;
	}
	dots->last_layer = z_value;
	draw_julia3d(img, dots, total_dots);
	free(dots);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
