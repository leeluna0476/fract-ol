/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_theme_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:41:28 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/14 15:41:36 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	init_theme(t_data *img)
{
	img->theme.mandelbrot = RED;
	img->theme.julia = BLUE;
	img->theme.burningship = RED;
	img->theme.tricorn = BLUE;
}

void	key_theme(t_data *img, int key)
{
	if (key == THEME_RED)
	{
		img->theme.mandelbrot = RED;
		img->theme.julia = RED;
		img->theme.burningship = RED;
		img->theme.tricorn = RED;
	}
	else if (key == THEME_BLUE)
	{
		img->theme.mandelbrot = BLUE;
		img->theme.julia = BLUE;
		img->theme.burningship = BLUE;
		img->theme.tricorn = BLUE;
	}
}
