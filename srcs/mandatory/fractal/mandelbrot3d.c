/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:23:02 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/19 20:26:01 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot3d(t_data *img)
{
	t_point		*mandelbrot3d;
	t_vec3d		angle;
	t_matrix	rotation_matrix;

	mandelbrot3d = malloc(TOTAL_DOTS * sizeof(t_point));
	generate_mandelbrot3d(mandelbrot3d);
	init_angle(&angle, img);
	rotation_matrix = generate_rotation_matrix(angle);
	make_box_black(img);
	draw_mandelbrot3d(img, mandelbrot3d, rotation_matrix);
	free(mandelbrot3d);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
