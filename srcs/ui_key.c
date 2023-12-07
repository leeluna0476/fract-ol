/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:52:38 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 17:56:23 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	key_fractals(t_data *img, int key)
{
	if (key == KEY_0)
		execute_button(img, CLEAR, clear_box);
	else if (key == KEY_1)
		execute_button(img, MANDELBROT, init_zoom_center);
	else if (key == KEY_2)
		execute_button(img, JULIA, init_zoom_center);
	else if (key == KEY_3)
		execute_button(img, BURNINGSHIP, init_zoom_center);
	else if (key == KEY_4)
		execute_button(img, TRICORN, init_zoom_center);
	else if (key == KEY_5)
		execute_button(img, LOGISTIC, make_box_black);
}

void	key_offset(t_data *img, int key)
{
	if (key == KEY_LEFT)
		img->center.x -= 80;
	else if (key == KEY_RIGHT)
		img->center.x += 80;
	else if (key == KEY_DOWN)
		img->center.y += 80;
	else if (key == KEY_UP)
		img->center.y -= 80;
}

void	control_key(int key, t_data *img)
{
	if (key == KEY_ESC)
		terminate_program();
	else if (key >= KEY_1 && key <= KEY_0)
		key_fractals(img, key);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		key_offset(img, key);
	else if (key == THEME_RED || key == THEME_BLUE)
		key_theme(img, key);
	call_set(img);
	write_menu(img);
}

int	key_press(int key, void *param)
{
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
	mlx_hook(img->win_ptr, 17, 0, terminate_program, img);
}
