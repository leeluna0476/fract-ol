/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:44:45 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/06 08:56:45 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	make_button(t_data *img, t_ab start, t_ab button_wh, int color)
{
	int	i;
	int	j;

	if (start.a < img->mouse_x && img->mouse_x < start.a + button_wh.a && \
			start.b < img->mouse_y && img->mouse_y < start.b + button_wh.b)
		color = CHARCOAL;
	j = start.b;
	while (j < start.b + button_wh.b)
	{
		i = start.a;
		while (i < start.a + button_wh.a)
		{
			if (check_menu(i, j) == true)
				my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}
//
//
//
//	for (int j = start.b; j < start.b + button_wh.b; j++) {
//		for (int i = start.a; i < start.a + button_wh.a; i++) {
//			if (check_menu(i, j) == true) {
//				my_mlx_pixel_put(img, i, j, color);
//			}
//		}
//	}
//}

void	_button(t_data *img, int start_x, int start_y)
{
	t_ab	start;
	t_ab	button_wh;

	button_wh.a = 300;
	button_wh.b = 30;
	start.a = start_x;
	start.b = start_y;
	make_button(img, start, button_wh, MENUCOLOR);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

void	make_all_false(t_data *img)
{
	int	u;

	u = 0;
	while (u < BUTTONS)
	{
		img->button_on_off[u] = false;
		u++;
	}
}
