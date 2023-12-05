/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:42:45 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/05 18:08:10 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "ui.h"
# include <math.h>
# include <stdlib.h>

# define CONVERGE1	0.2
# define CONVERGE2	0.9
# define DIVERGE1 	2
# define DIVERGE2 	3
# define ITER_SMALL	100
# define ITER	 	500
# define ITER_LARGE	1000

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_box_standards {
	int box_offset_x;
	int box_offset_y;
}		t_box_standards;

// fractal_utils
void	init_complex(t_complex *c, double r, double i);
double	c_abs(t_complex z);
void	mandelbrot_julia_next(t_complex *z, t_complex c);
void	burningship_next(t_complex *z, t_complex c);
void	tricorn_next(t_complex *z, t_complex c);

// fractal_utils_execute
void	draw_mandelbrot(double z_abs, t_data *img, int i, int j);
void	draw_julia(double z_abs, t_data *img, int i, int j);
void	draw_burningship(double z_abs, t_data *img, int i, int j);
int		iter_complex(t_complex *z, t_complex c, int iter, int flag);

// logistic_utils
void	make_box_black(t_data *img);
void logistic_next(double r, double *x);

void	mandelbrot(t_data *img);

void	julia(t_data *img);

void	burningship(t_data *img);

void	tricorn(t_data *img);

void	logistic_map(t_data *img);

#endif
