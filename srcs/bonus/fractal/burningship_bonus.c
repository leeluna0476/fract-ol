/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:10:22 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:10:25 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	burningship(t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			j;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			init_complex(&z, 0, 0);
			init_complex(&c, \
					((double)(i - BOX_CENTER_X + img->center.x)) * img->zoom, \
					((double)(j - BOX_CENTER_Y + img->center.y)) * img->zoom);
			img->iter = iter_complex(&z, c, ITER, BURNINGSHIP);
			draw_burningship(c_abs(z), img, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
