/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:52:38 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 10:58:37 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_zoom_center(t_data *img)
{
	img->zoom = 0.0035;
	img->center.x = 0;
	img->center.y = 0;
}

void	control_key(int key, t_data *img)
{
	if (key == KEY_ESC)
	{
//		system("leaks fractol");
		exit(0);
	}
	else if (key == KEY_0)
	{
	//	init_axis(img);
		make_all_false(img);
		img->button_on_off[CLEAR] = true;
		clear_box(img);
	}
	else if (key == KEY_1)
	{
//		init_coordinate(img);
		make_all_false(img);
		init_zoom_center(img);
		img->button_on_off[MANDELBROT] = true;
		mandelbrot(img);
	}
	else if (key == KEY_2) {
//		init_coordinate(img);
		make_all_false(img);
		init_zoom_center(img);
		img->button_on_off[JULIA] = true;
		julia(img);
	}
	else if (key == KEY_3) {
//		init_coordinate(img);
		make_all_false(img);
		init_zoom_center(img);
		img->button_on_off[BURNINGSHIP] = true;
		burningship(img);
	}
	else if (key == KEY_4) {
//		init_coordinate(img);
		make_all_false(img);
		init_zoom_center(img);
		img->button_on_off[TRICORN] = true;
		tricorn(img);
	}
	else if (key == KEY_5) {
//		init_coordinate(img);
		make_all_false(img);
		img->button_on_off[LOGISTIC] = true;
		logistic_map(img);
	}
	else if (key == KEY_LEFT) {
		img->center.x -= 80;
		call_set(img);
	}
	else if (key == KEY_RIGHT) {
		img->center.x += 80;
		call_set(img);
	}
	else if (key == KEY_DOWN) {
		img->center.y += 80;
		call_set(img);
	}
	else if (key == KEY_UP) {
		img->center.y -= 80;
		call_set(img);
	}
	write_menu(img);
}

int	key_press(int key, void *param) {
	t_data	*img;

	img = (t_data *)param;
	control_key(key, img);
	return (0);
}

void	hook(t_data *img)
{
	mlx_hook(img->win_ptr, 6, 0, mouse_move, img);
	mlx_hook(img->win_ptr, 2, 0, key_press, img);
	mlx_hook(img->win_ptr, 4, 0, mouse_press, img);
//	mlx_hook(img->win_ptr, 5, 0, mouse_release, img);
//	mlx_hook(img->win_ptr, 17, 0, terminate_program, img);
}
