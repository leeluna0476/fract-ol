/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:39:43 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 12:11:10 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	burningship(t_data *img)
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
			img->iter = iter_complex(&z, c, ITER_SMALL, BURNINGSHIP);
			draw_burningship(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
