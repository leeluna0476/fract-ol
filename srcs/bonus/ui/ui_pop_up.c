/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pop_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:55:31 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 09:19:26 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	zoom_warning(t_data *img)
{
	int	i;
	int	j;

	j = POP_TOP;
	while (j <= POP_BOT)
	{
		i = POP_LEFT;
		while (i <= POP_RIGHT)
		{
			my_mlx_pixel_put(img, i, j, BLACK);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}
