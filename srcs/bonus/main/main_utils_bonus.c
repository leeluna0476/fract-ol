/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:39:14 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:19 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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
	if (ft_strlen(fractal) != ft_strlen("mandelbrot") || \
			ft_strncmp(fractal, "mandelbrot", ft_strlen(fractal)))
	{
		if (ft_strlen(fractal) != ft_strlen("julia") || \
			ft_strncmp(fractal, "julia", ft_strlen(fractal)))
		{
			if (ft_strlen(fractal) != ft_strlen("burningship") || \
				ft_strncmp(fractal, "burningship", ft_strlen(fractal)))
			{
				if (ft_strlen(fractal) != ft_strlen("tricorn") || \
						ft_strncmp(fractal, "tricorn", ft_strlen(fractal)))
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
	{
		img->button_on_off[MANDELBROT] = true;
		img->key = KEY_1;
	}
	else if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0)
	{
		img->button_on_off[JULIA] = true;
		img->key = KEY_2;
	}
	else if (ft_strncmp(img->fractal, "burningship", \
				ft_strlen(img->fractal)) == 0)
	{
		img->button_on_off[BURNINGSHIP] = true;
		img->key = KEY_3;
	}
	else if (ft_strncmp(img->fractal, "tricorn", ft_strlen(img->fractal)) == 0)
	{
		img->button_on_off[TRICORN] = true;
		img->key = KEY_4;
	}
	call_set(img);
}
