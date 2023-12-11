/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:39:56 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:58 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	init_complex(t_complex *c, double r, double i)
{
	c->real = r;
	c->imag = i;
}

void	init_xy(t_xy *xy, int x, int y)
{
	xy->x = x;
	xy->y = y;
}

double	c_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

void	c_default_or_arg(t_data *img, t_complex *c)
{
	if (img->fractal && ft_strncmp(img->fractal, "julia", \
				ft_strlen(img->fractal)) == 0)
		init_complex(c, img->julia_c.real, img->julia_c.imag);
	else
		init_complex(c, -0.7269, 0.1889);
}
