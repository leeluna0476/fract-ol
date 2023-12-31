/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:14:02 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:17:20 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

void	init_parser(t_julia_parse *count)
{
	count->dot = 0;
	count->sign = 0;
	count->int_num = 0;
}

bool	is_num(char *arg)
{
	t_julia_parse	count;
	size_t			i;

	init_parser(&count);
	i = 0;
	while (arg[i] && (arg[i] == '+' || arg[i] == '-'))
	{
		count.sign++;
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if (count.int_num > 0 && arg[i] == '.')
				count.dot++;
			else
				return (false);
		}
		else
			count.int_num++;
		i++;
	}
	return (count.int_num != 0 && count.dot <= 1 && \
			count.sign <= 1 && ft_isdigit(arg[--i]));
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
	while (str[i] && digit <= 1000000000000000)
	{
		parse->double_num += ((double)(str[i] - '0')) / digit;
		digit *= 10;
		i++;
	}
}
