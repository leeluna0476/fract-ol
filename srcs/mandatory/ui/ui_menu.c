/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:30:57 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 19:27:32 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	write_header(t_data *img, int *line, int *gap)
{
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "/////  THEME  /////");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "[: RED");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "]: BLUE");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "/////   MENU   /////");
}

void	write_2ds(t_data *img, int *line, int *gap)
{
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "0: Reset Box");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "1: Mandelsbrot");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "2: Julia");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "3: Burning Ship");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "4: Tricorn");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "5: bifurcation diagram of logistic map");
}

void	write_3ds(t_data *img, int *line, int *gap)
{
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "6: 3D Mandelbrot");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "7: 3D Julia");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "8: 3D Burning Ship");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "9: 3D Tricorn");
}

void	write_guides(t_data *img, int *line, int *gap)
{
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "-------------- GUIDE --------------");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "/// MOVE: Direction Keys");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "/// ZOOM: Wheels");
	*line += *gap;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "/// ROTATE:");
	*line += 30;
	mlx_string_put(img->mlx_ptr, img->win_ptr, 50, \
			*line, WHITE, "    h(left) l(right) j(down) k(up)");
}

// reset button:
// 	가로: 30 ~ 330
// 	세로: 480 ~ 550
void	write_menu(t_data *img)
{
	int	line;
	int	gap;

	line = 50;
	gap = 50;
	write_header(img, &line, &gap);
	write_2ds(img, &line, &gap);
	write_3ds(img, &line, &gap);
	write_guides(img, &line, &gap);
}
