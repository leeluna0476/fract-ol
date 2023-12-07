/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:15:28 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 09:24:11 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	if (!s || !n)
		return ;
	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s)
		while (s[count])
			count++;
	return (count);
}

int	check_if_my_fractal(char *fractal, t_data *img)
{
	if (ft_strncmp(fractal, "mandelbrot", ft_strlen(fractal)))
	{
		if (ft_strncmp(fractal, "julia", ft_strlen(fractal)))
		{
			if (ft_strncmp(fractal, "burningship", ft_strlen(fractal)))
			{
				if (ft_strncmp(fractal, "tricorn", ft_strlen(fractal)))
					return (0);
			}
		}
	}
	img->fractal = fractal;
	return (1);
}

void	call_set_argv(t_data *img)
{
	make_all_false(img);
	init_zoom_center(img);
	if (ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)) == 0)
		img->button_on_off[MANDELBROT] = true;
	else if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0)
		img->button_on_off[JULIA] = true;
	else if (ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)) == 0)
		img->button_on_off[BURNINGSHIP] = true;
	else if (ft_strncmp(img->fractal, "tricorn", ft_strlen(img->fractal)) == 0)
		img->button_on_off[TRICORN] = true;
	call_set(img);
}

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
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
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
	return (0);
}
