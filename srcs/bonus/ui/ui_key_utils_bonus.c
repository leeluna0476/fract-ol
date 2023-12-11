/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_key_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:42:58 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:43:03 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	control_fractals(int key, t_data *img)
{
	key_fractals(img, key);
	call_set(img);
	write_menu(img);
}

void	control_3ds(int key, t_data *img)
{
	key_fractals(img, key);
	call_set_3d(img);
	write_menu(img);
}

void	control_directions(int key, t_data *img)
{
	key_offset(img, key);
	if (key >= KEY_LEFT && key <= KEY_UP)
	{
		call_set(img);
		write_menu(img);
	}
	else
	{
		call_set_3d(img);
		write_menu(img);
	}
}

void	control_theme(int key, t_data *img)
{
	key_theme(img, key);
	call_set(img);
	write_menu(img);
}

void	control_key(int key, t_data *img)
{
	if (key == KEY_ESC)
		terminate_program();
	else if ((key != KEY_6 && (key >= KEY_1 && key <= KEY_5)) || key == KEY_0)
		control_fractals(key, img);
	else if (key >= KEY_6 && key <= KEY_8)
		control_3ds(key, img);
	else if ((key >= KEY_LEFT && key <= KEY_UP) || \
			(key == KEY_H || key == KEY_J || key == KEY_K || key == KEY_L))
		control_directions(key, img);
	else if (key == THEME_RED || key == THEME_BLUE)
		control_theme(key, img);
}
