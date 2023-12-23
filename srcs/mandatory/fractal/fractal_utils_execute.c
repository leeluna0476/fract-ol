/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_execute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:41:05 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/22 18:53:33 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	turn_off_trans(int color)
{
	int	bit;

	bit = 31;
	while (bit > 23)
	{
		if (((color >> bit) & 1) == 1)
			color &= ~(1 << bit);
		bit--;
	}
	return (color);
}

void	draw_mandelbrot(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, BLACK);
	else
	{
		if (img->theme.mandelbrot == RED)
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.mandelbrot * img->iter * 20));
		else
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.mandelbrot * img->iter / 20));
	}
}

void	draw_julia(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < CONVERGE1)
		my_mlx_pixel_put(img, i, j, RED);
	else if (z_abs < CONVERGE2)
		my_mlx_pixel_put(img, i, j, BLUE);
	else if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, GREEN);
	else
	{
		if (img->theme.julia == RED)
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.julia * img->iter * 20));
		else
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.julia * img->iter / 5));
	}
}

void	draw_burningship(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, BLACK);
	else
	{
		if (img->theme.burningship == RED)
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.burningship * img->iter * 30));
		else
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.burningship * img->iter / 20));
	}
}

void	draw_tricorn(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, BLACK);
	else
	{
		if (img->theme.tricorn == RED)
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.tricorn * img->iter * 20));
		else
			my_mlx_pixel_put(img, i, j, \
					turn_off_trans(img->theme.tricorn * img->iter / 5));
	}
}
