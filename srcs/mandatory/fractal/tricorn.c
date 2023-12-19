/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:11:35 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/19 20:26:16 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	tricorn(t_data *img)
{
	t_xy		box_std;
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;

	init_xy(&box_std, (BOX_STD_X + BOXLEFT) - img->center.x, \
			(BOX_STD_Y + BOXTOP) - img->center.y);
	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			init_complex(&z, 0, 0);
			init_complex(&c, \
					((double)(i - box_std.x)) * img->zoom, \
					((double)(j - box_std.y)) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, TRICORN);
			draw_tricorn(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
