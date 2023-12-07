/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:15:28 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 11:47:04 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	img;

	ft_bzero(&img, sizeof(t_data));
	if (argc >= 2 && argc <= 4)
	{
		if (check_if_my_fractal(argv[1], &img))
		{
			if (ft_strncmp(img.fractal, "julia", ft_strlen(img.fractal)) == 0)
			{
				// julia인데 argument가 충분히 들어오지 않았다면 줄리아를 디폴트로 띄우도록.
				if (argc != 4)
				{
					img.julia_c.real = -0.7269;
					img.julia_c.imag = 0.1889;
				}
				else
				{
					img.julia_c.real = atof(argv[2]);
					img.julia_c.imag = atof(argv[3]);
				}
			}
			else
			{
				// julia가 아닌데 argument가 2개보다 많다면 화면 디폴트로 띄우도록.
				if (argc > 2)
					img.fractal = NULL;
			}
		}
	}
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mlx_clear_window(img.mlx_ptr, img.win_ptr);
	init_screen(&img);
	init_axis(&img);
	if (img.fractal)
		call_set_argv(&img);
	hook(&img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	write_menu(&img);
	mlx_loop(img.mlx_ptr);
	printf("%p\n", img.win_ptr);
	return (0);
}
