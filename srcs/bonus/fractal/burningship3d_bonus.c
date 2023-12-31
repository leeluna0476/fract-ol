/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship3d_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:10:01 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:10:05 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

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
