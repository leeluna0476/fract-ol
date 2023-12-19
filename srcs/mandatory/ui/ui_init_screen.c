/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:15:16 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/19 20:28:31 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_screen(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (i < MENU)
				my_mlx_pixel_put(img, i, j, MENUCOLOR);
			else
				my_mlx_pixel_put(img, i, j, BACKCOLOR);
			i++;
		}
		j++;
	}
}

void	init_axis(t_data *img)
{
	int	i;
	int	j;

	j = LINETOP;
	while (j <= LINEBOT)
	{
		i = LINELEFT;
		while (i <= LINERIGHT)
		{
			if (i == LINELEFT || j == LINEBOT)
				my_mlx_pixel_put(img, i, j, WHITE);
			i++;
		}
		j++;
	}
}

void	init_box(t_data *img)
{
	int	i;
	int	j;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			my_mlx_pixel_put(img, i, j, BLACK);
			i++;
		}
		j++;
	}
}

void	clear_box(t_data *img)
{
	int	i;
	int	j;

	j = BOXTOP;
	while (j < BOXBOT)
	{
		i = BOXLEFT;
		while (i < BOXRIGHT)
		{
			my_mlx_pixel_put(img, i, j, BACKCOLOR);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
