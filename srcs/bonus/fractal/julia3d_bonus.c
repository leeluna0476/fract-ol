/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:40:24 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/14 15:28:29 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	julia3d(t_data *img)
{
	t_julia3d	*dots;
	t_complex	c;
	int			total_dots;
	int			total_slices;
	int			z_value;

	make_box_black(img);
	init_complex(&c, JULIA_DEF_CR, JULIA_DEF_CI);
	total_slices = get_total_slices(c);
	total_dots = DOTS_PER_SLICE * total_slices;
	dots = malloc(total_dots * sizeof(t_julia3d));
	z_value = 0;
	while (z_value < total_slices)
	{
		iter_julia3d(dots, c, z_value);
		c.real += SLICE_GAP;
		z_value++;
	}
	dots->last_layer = z_value;
	draw_julia3d(img, dots, total_dots);
	free(dots);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
