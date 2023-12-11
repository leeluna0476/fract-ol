/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:39:25 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:32 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

bool	is_num(char *arg)
{
	t_julia_parse	count;
	size_t			i;

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

size_t	parse_integer_part(const char *str, t_julia_parse *parse)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) == true)
		{
			parse->double_num *= 10;
			parse->double_num += str[i] - '0';
		}
		else
		{
			if (str[i] == '-')
				parse->sign = -1;
		}
		i++;
	}
	return (i);
}

void	parse_decimal_part(const char *str, t_julia_parse *parse)
{
	long long	digit;
	size_t		i;

	digit = 10;
	i = 0;
	while (str[i] && (str[i] - '0' != 0) && digit <= 1000000000000000)
	{
		parse->double_num += ((double)(str[i] - '0')) / digit;
		digit *= 10;
		i++;
	}
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
