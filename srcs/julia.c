/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:25 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 11:00:20 by seojilee         ###   ########.fr       */
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

	box_std.box_offset_x = BOXWIDTH / 2 - img->center.x;
	box_std.box_offset_y = BOXHEIGHT / 2 - img->center.y;
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			if (img->fractal && ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0)
				init_complex(&c, img->julia_c.real, img->julia_c.imag);
			else
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
