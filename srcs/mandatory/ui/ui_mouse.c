/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:47:53 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 18:36:38 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_zoom_center(t_data *img)
{
	img->zoom = 0.0035;
	img->center.x = 0;
	img->center.y = 0;
}

void	send_click_to_key(t_data *img, int y)
{
	if (y >= 130 && y <= 160)
		control_key(THEME_RED, img);
	else if (y >= 180 && y <= 210)
		control_key(THEME_BLUE, img);
	else if (y >= 280 && y <= 310)
		control_key(KEY_0, img);
	else if (y >= 330 && y <= 360)
		control_key(KEY_1, img);
	else if (y >= 380 && y <= 410)
		control_key(KEY_2, img);
	else if (y >= 430 && y <= 460)
		control_key(KEY_3, img);
	else if (y >= 480 && y <= 510)
		control_key(KEY_4, img);
	else if (y >= 530 && y <= 560)
		control_key(KEY_5, img);
	else if (y >= 580 && y <= 610)
		control_key(KEY_6, img);
	else if (y >= 630 && y <= 660)
		control_key(KEY_7, img);
	else if (y >= 680 && y <= 710)
		control_key(KEY_8, img);
	else if (y >= 730 && y <= 760)
		control_key(KEY_9, img);
}

void	wheel(int button, t_data *img)
{
	if (button == WHEEL_UP)
	{
		img->center.x += ((img->mouse.x - BOXLEFT) - BOXWIDTH / 2);
		img->center.y += ((img->mouse.y - BOXTOP) - BOXHEIGHT / 2);
		img->zoom /= 1.5;
		img->center.x *= 1.5;
		img->center.y *= 1.5;
		call_set(img);
	}
	if (button == WHEEL_DOWN)
	{
		img->center.x += ((img->mouse.x - BOXLEFT) - BOXWIDTH / 2);
		img->center.y += ((img->mouse.y - BOXTOP) - BOXHEIGHT / 2);
		img->zoom *= 1.5;
		img->center.x /= 1.5;
		img->center.y /= 1.5;
		call_set(img);
	}
	if (button == WHEEL_CLICK)
	{
		init_zoom_center(img);
		call_set(img);
	}
	write_menu(img);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*img;
	int		start_y;

	img = (t_data *)param;
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return (1);
	img->mouse.x = x;
	img->mouse.y = y;
	start_y = 130;
	while (start_y <= 180)
	{
		_button(img, 30, start_y);
		start_y += 50;
	}
	start_y = 280;
	while (start_y <= 730)
	{
		_button(img, 30, start_y);
		start_y += 50;
	}
	write_menu(img);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	wheel(button, img);
	if (button == LEFT_CLICK)
	{
		if (x >= 30 && x <= 330)
			send_click_to_key(img, y);
		else if (x >= BOXLEFT && x <= BOXRIGHT)
		{
			if (y >= BOXTOP && y <= BOXBOT)
			{
				init_xy(&(img->center), img->center.x + \
						((img->mouse.x - BOXLEFT) - BOXWIDTH / 2), \
						img->center.y + \
						((img->mouse.y - BOXTOP) - BOXHEIGHT / 2));
				call_set(img);
			}
			write_menu(img);
		}
		else
			return (0);
	}
	return (0);
}
