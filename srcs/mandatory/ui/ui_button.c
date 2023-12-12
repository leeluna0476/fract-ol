/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:44:45 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 19:21:20 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	make_button(t_data *img, t_xy start, t_xy button_wh, int color)
{
	int	i;
	int	j;

	if (start.x < img->mouse.x && img->mouse.x < start.x + button_wh.x && \
			start.y < img->mouse.y && img->mouse.y < start.y + button_wh.y)
		color = CHARCOAL;
	j = start.y;
	while (j < start.y + button_wh.y)
	{
		i = start.x;
		while (i < start.x + button_wh.x)
		{
			if (check_menu(i, j) == true)
				my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	_button(t_data *img, int start_x, int start_y)
{
	t_xy	start;
	t_xy	button_wh;

	button_wh.x = 300;
	button_wh.y = 30;
	start.x = start_x;
	start.y = start_y;
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

void	turn_on_button(t_data *img, int button)
{
	make_all_false(img);
	init_theme(img);
	img->layer = false;
	img->button_on_off[button] = true;
}
