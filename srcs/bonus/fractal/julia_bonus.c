/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:40:50 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:10 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	julia(t_data *img)
{
	t_xy		box_std;
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;

	box_std.x = (BOX_STD_X + BOXLEFT) - img->center.x;
	box_std.y = (BOX_STD_Y + BOXTOP) - img->center.y;
	c_default_or_arg(img, &c);
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, \
					((double)(i - box_std.x)) * img->zoom, \
					((double)(j - box_std.y)) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, JULIA);
			draw_julia(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
