/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:41:30 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 12:12:03 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	tricorn(t_data *img)
{
	t_box_standards	box_std;
	t_complex		z;
	t_complex		c;
	int				i;
	int				j;

	box_std.box_offset_x = (BOX_STD_X + BOXLEFT) - img->center.x;
	box_std.box_offset_y = (BOX_STD_Y + BOXTOP) - img->center.y;
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, 0, 0);
			init_complex(&c, \
					((double)(i - box_std.box_offset_x)) * img->zoom, \
					((double)(j - box_std.box_offset_y)) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, TRICORN);
			draw_tricorn(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
