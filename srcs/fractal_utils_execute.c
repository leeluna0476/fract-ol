/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_execute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:41:05 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/06 07:43:44 by seojilee         ###   ########.fr       */
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
		my_mlx_pixel_put(img, i, j, turn_off_trans(RED * img->iter * 20));
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
		my_mlx_pixel_put(img, i, j, BLACK);
}

void	draw_burningship(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, BLACK);
	else
		my_mlx_pixel_put(img, i, j, turn_off_trans(RED * img->iter * 30));
}

void	draw_tricorn(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, WHITE);
	else
		my_mlx_pixel_put(img, i, j, BLACK);
}
