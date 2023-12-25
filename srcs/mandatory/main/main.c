/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:48:57 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/25 14:24:53 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_errmsg(void)
{
	write(1, "### Enter 1 or 3 parameters:\n", 29);
	write(1, "    ./fractol [fractal] [c.real] [c.imag]\n", 42);
	write(1, "[fractal]:\n", 11);
	write(1, "    1. mandelbrot\n    2. julia\n", 30);
	write(1, "       - [c.real] [c.imag]:\n", 28);
	write(1, "         - must enter a proper complex number\n", 46);
	write(1, "    3. burningship\n    4. tricorn\n", 34);
}

double	ft_atof(const char *str)
{
	t_julia_parse	parse;
	size_t			i;

	parse.double_num = 0.0;
	parse.dot = 0;
	parse.sign = 1;
	i = 0;
	i = parse_integer_part(str, &parse);
	if (str[i] == '.')
		i++;
	parse_decimal_part(&str[i], &parse);
	return (parse.sign * parse.double_num);
}

void	parse_main_args(t_data *img, int argc, char *argv[])
{
	if (argc >= 2 && argc <= 4)
	{
		if (check_if_my_fractal(argv[1], img))
		{
			if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0)
			{
				if (argc == 2)
					init_complex(&(img->julia_c), -0.7269, 0.1889);
				else
				{
					if (argc < 4 || !is_num(argv[2]) || !is_num(argv[3]))
						img->fractal = NULL;
					else
						init_complex(&(img->julia_c), \
								ft_atof(argv[2]), ft_atof(argv[3]));
				}
			}
			else
			{
				if (argc > 2)
					img->fractal = NULL;
			}
		}
	}
}

// if julia, but no c arguments, then default julia
// if julia, and correct c arguments, then atof
// if julia, but incorrect c arguments, then errmsg
// if julia, but too many arguments(more than 4), then errmsg
// if not julia, but too many arguments(more than 2), then errmsg
int	main(int argc, char *argv[])
{
	t_data	img;

	ft_bzero(&img, sizeof(t_data));
	parse_main_args(&img, argc, argv);
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mlx_clear_window(img.mlx_ptr, img.win_ptr);
	init_screen(&img);
	init_axis(&img);
	init_theme(&img);
	if (img.fractal)
		call_set_argv(&img);
	else
	{
		print_errmsg();
		return (0);
	}
	hook(&img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	write_menu(&img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
