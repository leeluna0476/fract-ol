/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_execute_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:40:27 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/14 15:40:31 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

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
	if (img->button_on_off[THDJULIA] == true)
		julia3d(img);
}

void	choose_set(t_data *img)
{
	call_set(img);
	call_set_3d(img);
}

int	terminate_program(void)
{
	exit(0);
}

void	execute_button(t_data *img, int button, void (*f)(t_data *))
{
	turn_on_button(img, button);
	(*f)(img);
}
