/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:42:45 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/16 19:10:35 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "main.h"
# include "ui.h"
# include <math.h>

# define CONVERGE1		0.2
# define CONVERGE2		0.9
# define DIVERGE1		2
# define DIVERGE2		3
# define JULIA_DEF_CR	-0.7269
# define JULIA_DEF_CI	0.1889
# define SLICE_GAP		0.01
# define DOTS_PER_SLICE	2073600
# define TOTAL_DOTS		2073600
# define ITER_SMALL		100
# define ITER			500
# define ITER_LARGE		1000

typedef struct s_point {
	double	real;
	double	rx;
	double	ry;
	double	rz;
	int		rcolor;
	double	imag;
	double	ix;
	double	iy;
	double	iz;
	int		icolor;
	double	abs;
	double	ax;
	double	ay;
	double	az;
	int		acolor;
}			t_point;

typedef struct s_vec3d {
	double	vec[3];
}	t_vec3d;

typedef struct s_matrix {
	double	mat[3][3];
}	t_matrix;

typedef struct s_xyz {
	double	x;
	double	y;
	double	z;
}			t_xyz;

typedef struct s_julia3d {
	int	x;
	int	y;
	int	z;
	int	color;
	int	last_layer;
}		t_julia3d;

// fractal_utils
void		init_complex(t_complex *c, double r, double i);
void		init_xy(t_xy *xy, int x, int y);
double		c_abs(t_complex z);
void		c_default_or_arg(t_data *img, t_complex *c);

// fractal_recurrence
void		mandelbrot_julia_next(t_complex *z, t_complex c);
void		burningship_next(t_complex *z, t_complex c);
void		tricorn_next(t_complex *z, t_complex c);
int			iter_complex(t_complex *z, t_complex c, int iter, int flag);

// fractal_utils_execute
int			turn_off_trans(int color);
void		draw_mandelbrot(double z_abs, t_data *img, int i, int j);
void		draw_julia(double z_abs, t_data *img, int i, int j);
void		draw_burningship(double z_abs, t_data *img, int i, int j);
void		draw_tricorn(double z_abs, t_data *img, int i, int j);

// fractal3d_utils
double		c_abs_3d(t_point point);
void		init_angle(t_vec3d *angle, t_data *img);
void		init_matrix(t_matrix *matrix);
void		init_vec3d(double *vector, double x, double y, double z);
void		set_values_mandelbrot3d(t_point *mandelbrot3d, \
				int idx, int i, int j);

// fractal3d_recurrence
void		next_mandelbrot3d(t_point *p, t_complex c);
void		iter_mandelbrot3d(t_point *mandelbrot3d, int idx, t_complex c);
void		iter_julia3d(t_julia3d *dots, t_complex c, int z_value);

//fractal3d_utils_matrix
t_matrix	multiply_matrix(t_matrix mat1, t_matrix mat2);
t_matrix	generate_rotation_matrix(t_vec3d angle);
void		init_xyz(t_xyz *xyz, int x, int y, int z);
t_xyz		generate_new_xyz(t_matrix rotation_matrix, double vec[3]);
void		matrix_point_multiply(t_point *mandelbrot3d, \
				t_matrix rotation_matrix, int q);

// logistic_utils
bool		check_inbox(t_xy xy);
void		make_box_black(t_data *img);
void		logistic_next(double r, double *x);

// mandelbrot3d_utils
void		set_mandelbrot3d_height(t_point *mandelbrot3d, t_complex z_value);
void		if_converge(t_point *mandelbrot4d, int idx, double abs);
void		generate_mandelbrot3d(t_point *mandelbrot3d);
void		draw_mandelbrot3d(t_data *img, t_point *mandelbrot3d, \
				t_matrix rotation_matrix);

// julia3d_utils
bool		all_diverge(t_complex c);
int			get_total_slices(t_complex c);
void		set_dot_values(t_julia3d *dot, int x_value, \
				int y_value, int z_value);
int			find_layer(t_data *img, t_julia3d *dots);
void		draw_julia3d(t_data *img, t_julia3d *dots, \
				int total_dots);

void		mandelbrot(t_data *img);

void		julia(t_data *img);

void		burningship(t_data *img);

void		tricorn(t_data *img);

void		logistic_map(t_data *img);

void		mandelbrot3d(t_data *img);

void		julia3d(t_data *img);

#endif
