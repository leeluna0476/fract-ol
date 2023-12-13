/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:21:22 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/13 16:38:02 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	draw_julia3d(t_data *img, t_julia3d *dots, \
		int total_dots)
{
	t_xy	dots_xy;
	int		u;

	u = 0;
	if (img->layer == true)
	{
		img->last_layer = find_layer(img, dots, total_dots);
	}
	else
	{
		img->last_layer = dots->last_layer;
	}
	while (u < total_dots)
	{
		dots_xy.x = dots[u].x + BOX_STD_X + BOXLEFT;
		dots_xy.y = dots[u].y + BOX_STD_Y + BOXTOP;
		if (check_inbox(dots_xy) == true)
		{
			if (dots[u].color != 0)
			{
				if (dots[u].z <= img->last_layer)
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
	int			total_slices;
	int			z_value;

	make_box_black(img);
	init_complex(&c, -1.235, 0.1);
//	init_complex(&c, JULIA_DEF_CR, JULIA_DEF_CI);
	total_slices = get_total_slices(c);
	total_dots = DOTS_PER_SLICE * total_slices;
	dots = malloc(total_dots * sizeof(t_julia3d));
	z_value = 0;
	while (z_value < total_slices)
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
