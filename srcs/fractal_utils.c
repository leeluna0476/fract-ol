/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:55:26 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/04 12:13:12 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_complex(t_complex *c, double r, double i)
{
	c->real = r;
	c->imag = i;
}

double	c_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

void	mandelbrot_julia_next(t_complex *z, t_complex c)
{
	double	r;
	double	i;

	r = z->real;
	i = z->imag;
	z->real = r * r - i * i + c.real;
	z->imag = 2 * r * i + c.imag;
}

void	burningship_next(t_complex *z, t_complex c)
{
	double	r;
	double	i;

	r = z->real;
	i = z->imag;
	if (r < 0)
		r *= -1;
	if (i < 0)
		r *= -1;
	z->real = r * r - i * i + c.real;
	z->imag = 2 * r * i + c.imag;
}

void	tricorn_next(t_complex *z, t_complex c)
{
	double	r;
	double	i;

	r = z->real;
	i = z->imag;
	z->real = r * r - i * i + c.real;
	z->imag = -1 * 2 * r * i + c.imag;
}

void	iter_complex(t_complex *z, t_complex c, int iter, int flag)
{
	int	k;

	k = 0;
	while (k < iter && c_abs(*z) < 2)
	{
		if (flag == MANDELBROT || flag == JULIA)
			mandelbrot_julia_next(z, c);
		else if (flag == BURNINGSHIP)
			burningship_next(z, c);
		else if (flag == TRICORN)
			tricorn_next(z, c);
		k++;
	}
}

void	draw_mandelbrot(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, BLACK);
	else if (z_abs < DIVERGE2)
		my_mlx_pixel_put(img, i, j, WHITE);
	else
		my_mlx_pixel_put(img, i, j, BLUE);
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
		my_mlx_pixel_put(img, i, j, WHITE);
	else
		my_mlx_pixel_put(img, i, j, BLACK);
}

void	draw_tricorn(double z_abs, t_data *img, int i, int j)
{
	if (z_abs < DIVERGE1)
		my_mlx_pixel_put(img, i, j, WHITE);
	else
		my_mlx_pixel_put(img, i, j, BLACK);
}
