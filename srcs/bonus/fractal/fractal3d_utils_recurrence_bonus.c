/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal3d_utils_recurrence_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:30:04 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/14 15:30:12 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

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
			iter_complex(&z, c, 100, JULIA);
			current_idx = (i - BOXLEFT) + (j - BOXTOP) * \
					BOXWIDTH + z_value * DOTS_PER_SLICE;
			if (c_abs(z) < 2)
				set_dot_values(&dots[current_idx], \
					i - box_std.x, j - box_std.y, z_value);
			i++;
		}
		j++;
	}
}
