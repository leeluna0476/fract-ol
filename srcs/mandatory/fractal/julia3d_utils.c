/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:36 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 21:02:21 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

bool	all_diverge(t_complex c)
{
	t_xy		box_std;
	t_complex	z;
	int			i;
	int			j;

	init_xy(&box_std, BOX_STD_X + BOXLEFT, BOX_STD_Y + BOXTOP);
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i= BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, (double)(i - box_std.x) / 300, \
					(double)(j - box_std.y) / 300);
			iter_complex(&z, c, 5, JULIA);
			if (c_abs(z) < 2)
				return (false);
			i++;
		}
		j++;
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

void	set_dot_values(t_julia3d *dot, int x_value, int y_value, int z_value)
{
	dot->x = x_value;
	dot->y = y_value;
	dot->z = z_value;
	dot->color = WHITE - z_value * 1000;
}

void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value)
{
	t_xy		box_std;
	t_complex	z;
	int			i;
	int			j;
	int			current_idx;

	init_xy(&box_std, BOX_STD_X + BOXLEFT, BOX_STD_Y + BOXTOP);
	j = BOXTOP;
	while (j <= BOXBOT)
	{
		i = BOXLEFT;
		while (i <= BOXRIGHT)
		{
			init_complex(&z, (double)(i - box_std.x) / 300, \
					(double)(j - box_std.y) / 300);
			iter_complex(&z, c, 5, JULIA);
			if (c_abs(z) < 2)
			{
				current_idx = (i - BOXLEFT) + (j - BOXTOP) * BOXWIDTH + z_value * DOTS_PER_SLICE;
				set_dot_values(&dots[current_idx], i - box_std.x, j - box_std.y, z_value);
			}
			i++;
		}
		j++;
	}
}

int	find_layer(t_data *img, t_julia3d *dots, int total_dots)
{
	int	i;

	(void)total_dots;
	i = dots->last_layer * DOTS_PER_SLICE;
	while (i >= DOTS_PER_SLICE)
	{
		if ((img->mouse.x <= dots[i].x + (BOX_STD_X + BOXLEFT) && img->mouse.y <= dots[i].y + (BOX_STD_Y + BOXTOP)) && \
				(img->mouse.x > dots[i - DOTS_PER_SLICE].x + (BOX_STD_X + BOXLEFT) && img->mouse.y > dots[i - DOTS_PER_SLICE].y) + (BOX_STD_Y + BOXTOP))
			break ;
		i--;
	}
	return (dots[i].z);
}
