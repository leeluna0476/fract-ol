/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:53:14 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/20 11:15:28 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// stereographic projection
void	burningship3d(t_data *img)
{
	double			z_abs;
	int				i;
	int				j;

	make_box_black(img);
	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			if (on_sphere(BOX_CENTER_X - i, BOX_CENTER_Y - j) == true)
			{
				z_abs = generate_burningship3d(img, i, j);
				draw_burningship3d(img, z_abs, i, j);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
