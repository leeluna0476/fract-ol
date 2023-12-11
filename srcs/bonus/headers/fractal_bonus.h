/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:42:45 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 07:47:34 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "main_bonus.h"
# include "ui_bonus.h"
# include <math.h>

# define CONVERGE1	0.2
# define CONVERGE2	0.9
# define DIVERGE1 	2
# define DIVERGE2 	3
# define ITER_SMALL	100
# define ITER	 	500
# define ITER_LARGE	2000

typedef struct s_box_standards {
	int	box_offset_x;
	int	box_offset_y;
}		t_box_standards;

// fractal_utils
void	init_complex(t_complex *c, double r, double i);
void	init_xy(t_xy *xy, int x, int y);
double	c_abs(t_complex z);
void	c_default_or_arg(t_data *img, t_complex *c);

// fractal_recurrence
void	mandelbrot_julia_next(t_complex *z, t_complex c);
void	burningship_next(t_complex *z, t_complex c);
void	tricorn_next(t_complex *z, t_complex c);
int		iter_complex(t_complex *z, t_complex c, int iter, int flag);

// fractal_utils_execute
int		turn_off_trans(int color);
void	draw_mandelbrot(double z_abs, t_data *img, int i, int j);
void	draw_julia(double z_abs, t_data *img, int i, int j);
void	draw_burningship(double z_abs, t_data *img, int i, int j);
void	draw_tricorn(double z_abs, t_data *img, int i, int j);

// logistic_utils
bool	check_inbox(t_xy xy);
void	make_box_black(t_data *img);
void	logistic_next(double r, double *x);

void	mandelbrot(t_data *img);

void	julia(t_data *img);

void	burningship(t_data *img);

void	tricorn(t_data *img);

void	logistic_map(t_data *img);

#endif
