/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:24:04 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 18:55:24 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	call_set(t_data *img)
{
	if (img->button_on_off[CLEAR] == true)
		clear_box(img);
	else if (img->button_on_off[MANDELBROT] == true)
		mandelbrot(img);
	else if (img->button_on_off[JULIA] == true)
		julia(img);
	else if (img->button_on_off[BURNINGSHIP] == true)
		burningship(img);
	else if (img->button_on_off[TRICORN] == true)
		tricorn(img);
	else if (img->button_on_off[LOGISTIC] == true)
		logistic_map(img);
}

void	call_set_3d(t_data *img)
{
	if (img->button_on_off[THDMANDELBROT] == true)
		mandelbrot3d(img);
	else if (img->button_on_off[THDJULIA] == true)
		julia3d(img);
	else if (img->button_on_off[THDBURNINGSHIP] == true)
		burningship3d(img);
}

void	choose_set(t_data *img)
{
	call_set(img);
	if (img->button_on_off[THDJULIA] == true)
		call_set_3d(img);
}

int	terminate_program(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	exit(0);
}

void	execute_button(t_data *img, int button, void (*f)(t_data *))
{
	turn_on_button(img, button);
	(*f)(img);
}
