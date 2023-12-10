/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_recurrence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:25:53 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/08 09:23:55 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

int	iter_complex(t_complex *z, t_complex c, int iter, int flag)
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
	return (k);
}
