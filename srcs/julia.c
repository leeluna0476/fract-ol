/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:25 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/06 07:41:04 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_data *img)
{
	t_box_standards	box_std;
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;

	box_std.box_offset_x = BOXWIDTH / 2 - img->center_x;
	box_std.box_offset_y = BOXHEIGHT / 2 - img->center_y;
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&c, -0.7269, 0.1889);
			init_complex(&z, \
					((double)(i - BOXLEFT) - box_std.box_offset_x) * img->zoom, \
					((double)(j - BOXTOP) - box_std.box_offset_y) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, JULIA);
			draw_julia(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
