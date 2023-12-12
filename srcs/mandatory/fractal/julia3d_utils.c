/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:36 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 15:30:18 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	all_diverge(t_complex c)
{
	t_complex	z;
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			z.real = (double)(i - WIDTH / 2) / 300;
			z.imag = (double)(j - HEIGHT / 2) / 300;
			k = -1;
			while (c_abs(z) < 2 && ++k < 400)
				mandelbrot_julia_next(&z, c);
			if (c_abs(z) < 2)
				return (false);
		}
	}
	return (true);
}

int	get_total_slices(t_complex c)
{
	int	slice_num;

	slice_num = 0;
	while (all_diverge(c) == false)
	{
		c.real += SLICE_GAP;
		slice_num++;
	}
	return (slice_num);
}

void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value)
{
	t_complex	z;
	int			i;
	int			j;

	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, (double)(i - (BOX_STD_X + BOXLEFT)) / 300, \
					(double)(j - (BOX_STD_Y + BOXTOP)) / 300);
			iter_complex(&z, c, 10, JULIA);
			if (c_abs(z) < 2)
			{
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + \
					z_value * DOTS_PER_SLICE].x = i - (BOX_STD_X + BOXLEFT);
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + \
					z_value * DOTS_PER_SLICE].y = j - (BOX_STD_Y + BOXTOP);
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + \
					z_value * DOTS_PER_SLICE].z = z_value;
				dots[(i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + \
					z_value * DOTS_PER_SLICE].color = WHITE - z_value * 1000;
			}
			i++;
		}
		j++;
	}
}
