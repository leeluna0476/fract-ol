/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:12:26 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:12:31 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	logistic_map(t_data *img)
{
	double	r;
	double	x;
	t_xy	scaled;
	int		iter;

	r = 0.0;
	while (r <= 4)
	{
		x = 0.5;
		iter = 0;
		while (iter < 1000)
		{
			logistic_next(r, &x);
			if (iter >= 950)
			{
				init_xy(&scaled, (int)(r * BOXWIDTH / 4) + BOXLEFT, \
						(BOXWIDTH - 441) - (int)(x * BOXWIDTH / 2));
				if (check_inbox(scaled) == true)
					my_mlx_pixel_put(img, scaled.x, scaled.y, WHITE);
			}
			iter++;
		}
		r += 0.001;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
