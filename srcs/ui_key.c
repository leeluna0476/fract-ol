/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:52:38 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/04 12:16:50 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "fractal.h"
#include <stdio.h>

void	control_key(int key, t_data *img)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_0)
	{
	//	init_axis(img);
		make_all_false(img);
		img->zoom = 0.005;
		img->center_x = 0;
		img->center_y = 0;
		img->button_on_off[CLEAR] = true;
		clear_box(img);
	}
	else if (key == KEY_1)
	{
//		init_coordinate(img);
		make_all_false(img);
		img->zoom = 0.005;
		img->center_x = 0;
		img->center_y = 0;
		img->button_on_off[MANDELBROT] = true;
		mandelbrot(img);
	}
	else if (key == KEY_2) {
//		init_coordinate(img);
		make_all_false(img);
		img->zoom = 0.005;
		img->center_x = 0;
		img->center_y = 0;
		img->button_on_off[JULIA] = true;
		julia(img);
	}
	else if (key == KEY_3) {
//		init_coordinate(img);
		make_all_false(img);
		img->zoom = 0.005;
		img->center_x = 0;
		img->center_y = 0;
		img->button_on_off[BURNINGSHIP] = true;
		burningship(img);
	}
	else if (key == KEY_4) {
//		init_coordinate(img);
		make_all_false(img);
		img->zoom = 0.005;
		img->center_x = 0;
		img->center_y = 0;
		img->button_on_off[TRICORN] = true;
		tricorn(img);
	}
//	else if (key == KEY_5) {
//		init_coordinate(img);
//		make_all_false(img);
//		img->fractals[LOGISTIC] = true;
//		logistic(img);
//	}
//	else if (key == KEY_6) {
//		// z value is real or imaginary value of limit point
//		init_coordinate(img);
//		make_all_false(img);
//		img->fractals[MANDELBROT3D] = true;
//		img->mosaic = true;
//		img->real3d = false;
//		img->real32 = false;
//		img->imag3d = false;
//		img->abs3d = false;
//		
//		img->reall = false;
//		img->imagl = false;
//		
//		mandelbrot3d(img);
//	}
//	else if (key == KEY_7) {
//		// think 3d printer
//		init_coordinate(img);
//		make_all_false(img);
//		img->fractals[JULIA3D] = true;
//		julia3d(img);
//	}
//	else if (key == KEY_8) {
//		// stereographic projection
//		init_coordinate(img);
//		make_all_false(img);
//		img->fractals[BURNINGSHIP3D] = true;
//
//		burningship3d(img);
//	}
//	else if (key == KEY_9) {
//		// ??
//		//tricorn3d
//	}
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
