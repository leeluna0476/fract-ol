/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:51:22 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/05 18:02:38 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	check_inbox(int x, int y)
{
	if (x >= BOXLEFT && x <= BOXRIGHT)
	{
		if (y >= BOXTOP && y <= BOXBOT)
			return (true);
	}
	return (false);
}

void	logistic_map(t_data *img)
{
    double  r;
    double  x;
	int		scaled_x;
	int		scaled_y;
    int     iter;

	make_box_black(img);
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
				scaled_x = (int)(r * BOXWIDTH / 4) + BOXLEFT;
				scaled_y = (BOXWIDTH - 440) - (int)(x * BOXWIDTH / 2);
				if (check_inbox(scaled_x, scaled_y) == true)
					my_mlx_pixel_put(img, scaled_x, scaled_y, WHITE);
			}
			iter++;
		}
		r += 0.001;
	}
    mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
