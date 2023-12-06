/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:47:53 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/06 13:13:59 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	call_set(t_data *img)
{
	if (img->button_on_off[MANDELBROT] == true)
		mandelbrot(img);
	else if (img->button_on_off[JULIA] == true)
		julia(img);
	else if (img->button_on_off[BURNINGSHIP] == true)
		burningship(img);
	else if (img->button_on_off[TRICORN] == true)
		tricorn(img);
}

void	wheel(int button, t_data *img)
{
	if (button == WHEEL_UP)
	{
		img->center_x += ((img->mouse_x - BOXLEFT) - BOXWIDTH / 2);
		img->center_y += ((img->mouse_y - BOXTOP) - BOXHEIGHT / 2);
		img->zoom /= 1.5;
		img->center_x *= 1.5;
		img->center_y *= 1.5;
		init_key_xy(img);
		call_set(img);
	}
	if (button == WHEEL_DOWN)
	{
		img->center_x += ((img->mouse_x - BOXLEFT) - BOXWIDTH / 2);
		img->center_y += ((img->mouse_y - BOXTOP) - BOXHEIGHT / 2);
		img->zoom *= 1.5;
		img->center_x /= 1.5;
		img->center_y /= 1.5;
		init_key_xy(img);
		call_set(img);
	}
	if (button == WHEEL_CLICK)
	{
		init_zoom_center(img);
		init_key_xy(img);
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
	img->mouse_x = x;
	img->mouse_y = y;
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
	t_data  	*img;

	img = (t_data *)param;
	wheel(button, img);
	if (button == LEFT_CLICK) {
		if (x >= 30 && x <= 330)
		{
			if (y >= 280 && y <= 310)
				control_key(KEY_0, img);
			if (y >= 330 && y <= 360)
				control_key(KEY_1, img);
			if (y >= 380 && y <= 410)
				control_key(KEY_2, img);
			if (y >= 430 && y <= 460)
				control_key(KEY_3, img);
			if (y >= 480 && y <= 510)
				control_key(KEY_4, img);
			if (y >= 530 && y <= 560)
				control_key(KEY_5, img);
			if (y >= 580 && y <= 610)
				control_key(KEY_6, img);
			if (y >= 630 && y <= 660)
				control_key(KEY_7, img);
			if (y >= 680 && y <= 710)
				control_key(KEY_8, img);
			if (y >= 730 && y <= 760)
				control_key(KEY_9, img);
		}
		else if (x >= BOXLEFT && x <= BOXRIGHT)
		{
			if (y >= BOXTOP && y <= BOXBOT)
			{
				img->center_x += ((img->mouse_x - BOXLEFT) - BOXWIDTH / 2);
				img->center_y += ((img->mouse_y - BOXTOP) - BOXHEIGHT / 2);
				call_set(img);
			}
			write_menu(img);
		}
		else
			return (0);
	}
//	write_menu(img);
	return (0);
}
