/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:29:55 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/07 13:02:42 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "ui.h"

typedef struct s_julia_parse {
	int	num;
	int	neg;
	int	dot;
}		t_julia_parse;

// main_utils
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		check_if_my_fractal(char *fractal, t_data *img);
void	call_set_argv(t_data *img);

#endif
