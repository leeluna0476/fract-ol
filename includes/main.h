/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:29:55 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 16:51:32 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "ui.h"

typedef struct s_julia_parse {
	int		int_num;
	double	double_num;
	int		sign;
	int		dot;
}		t_julia_parse;

// main_utils
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		check_if_my_fractal(char *fractal, t_data *img);
void	call_set_argv(t_data *img);

// main_utils_parse
bool	ft_isdigit(int c);
bool	is_num(char *arg);
size_t	parse_integer_part(const char *str, t_julia_parse *parse);
void	parse_decimal_part(const char *str, t_julia_parse *parse);
double	ft_atof(const char *str);

// main
void	parse_main_args(t_data *img, int argc, char *argv[]);

#endif
