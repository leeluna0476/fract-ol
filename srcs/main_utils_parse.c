/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:10:05 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 14:20:23 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

bool	is_num(char *arg)
{
	t_julia_parse	count;
	size_t	i;

	i = 0;
	count.dot = 0;
	count.sign = 0;
	count.int_num = 0;
	while (i < ft_strlen(arg))
	{
		if (!ft_isdigit(arg[i]))
		{
			if (arg[i] == '.')
				count.dot++;
			else if (arg[i] == '-' || arg[i] == '+')
				count.sign++;
			else
				return (false);
		}
		else
			count.int_num++;
		i++;
	}
	if (count.int_num == 0 || count.dot > 1 || count.sign > 1)
		return (false);
	return (true);
}

double	ft_atof(const char *str)
{
	t_julia_parse	parse;
	size_t			i;
	long long		digit;

	parse.double_num = 0.0;
	parse.dot = 0;
	parse.sign = 1;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) == true)
		{
			parse.double_num *= 10;
			parse.double_num += str[i] - '0';
		}
		else
		{
			if (str[i] == '-')
				parse.sign = -1;
		}
		i++;
	}
	if (str[i] == '.')
		i++;
	digit = 10;
	while (str[i] && (str[i] - '0' != 0) && digit <= 1000000000000000)
	{
		parse.double_num += ((double)(str[i] - '0')) / digit;
		digit *= 10;
		i++;
	}
	return (parse.sign * parse.double_num);
}
