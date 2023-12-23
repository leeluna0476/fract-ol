/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:25 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/22 19:16:45 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;

	c_default_or_arg(img, &c);
	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			init_complex(&z, \
					((double)(i - BOX_CENTER_X + img->center.x)) * img->zoom, \
					((double)(j - BOX_CENTER_Y + img->center.y)) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, JULIA);
			draw_julia(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
