/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +# +  +:+       +# +      */
/*                                                +# +# +# +# +# +   +# +     */
/*   Created: 2023/12/02 12:59:13 by seojilee          # +#     # +#          */
/*   Updated: 2023/12/14 14:35:59 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <mlx.h>
# include <stdbool.h>

# define WIDTH 			1920
# define HEIGHT 		1080
# define MENU			350
# define LINETOP		50
# define LINEBOT		1030
# define LINELEFT		400
# define LINERIGHT		1870
# define BOXTOP			50 
# define BOXBOT			980
# define BOXLEFT 		450
# define BOXRIGHT		1870
# define BOXWIDTH		1420
# define BOXHEIGHT		930
# define BOX_STD_X		710
# define BOX_STD_Y		465

# define BACKCOLOR		0x3C3D42
# define MENUCOLOR		0x505259

# define WHITE			0x00FFFFFF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define YELLOW			0x00FDDA0D
# define BLUE			0x000000FF
# define BLACK			0x00000000
# define CHARCOAL		0x001E1E1E

# define LEFT_CLICK		1
# define WHEEL_CLICK	3
# define WHEEL_DOWN		4
# define WHEEL_UP		5
# define ZOOM_SCALE		1.25

# define KEY_ESC		53
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_8			28
# define KEY_9			25
# define KEY_0			29

# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126

# define KEY_H			4
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37

# define THEME_RED		33
# define THEME_BLUE		30

# define CLEAR			0
# define MANDELBROT		1
# define JULIA			2
# define BURNINGSHIP	3
# define TRICORN		4
# define LOGISTIC		5
# define THDMANDELBROT	6
# define THDJULIA		7
# define THDBURNINGSHIP	8
# define THDTRICORN		9
# define BUTTONS		10

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_xy {
	int	x;
	int	y;
}				t_xy;

typedef struct s_theme {
	int	mandelbrot;
	int	julia;
	int	burningship;
	int	tricorn;
}		t_theme;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*fractal;
	t_theme		theme;
	t_complex	julia_c;
	t_xy		mouse;
	t_xy		center;
	t_xy		rotate;
	double		zoom;
	int			iter;
	bool		layer;
	int			last_layer;
	bool		button_on_off[BUTTONS];
}				t_data;

/* ui_init_screen
 * initialize the screen
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_screen(t_data *img);
void	init_axis(t_data *img);
void	init_box(t_data *img);
void	clear_box(t_data *img);

/* ui_menu
 * initialize menu bar
 */
bool	check_menu(int a, int b);
void	write_header(t_data *img, int *line, int *gap);
void	write_2ds(t_data *img, int *line, int *gap);
void	write_3ds(t_data *img, int *line, int *gap);
void	write_menu(t_data *img);

/* ui_menu_utils
 * menu utilities
 */
bool	check_menu(int a, int b);
bool	check_write(t_data *img);

/* ui_button
 * set buttons
 */
void	make_button(t_data *img, t_xy start, t_xy button_wh, int color);
void	_button(t_data *img, int start_x, int start_y);
void	make_all_false(t_data *img);
void	turn_on_button(t_data *img, int button);

/* ui_button_execute
 * execute button
 */
void	call_set(t_data *img);
void	call_set_3d(t_data *img);
void	choose_set(t_data *img);
int		terminate_program(void);
void	execute_button(t_data *img, int button, void (*f)(t_data *));

/* ui_key
 * receive key hooks
 * control keys
 */
void	key_fractals(t_data *img, int key);
void	key_offset(t_data *img, int key);
int		key_press(int key, void *param);
void	hook(t_data *img);

/* ui_key_utils
 * control keys by type
 */
void	control_fractals(int key, t_data *img);
void	control_3ds(int key, t_data *img);
void	control_directions(int key, t_data *img);
void	control_theme(int key, t_data *img);
void	control_key(int key, t_data *img);

/* ui_mouse
 * receive mouse hooks
 */
void	init_zoom_center(t_data *img);
void	send_click_to_key(t_data *img, int y);
void	wheel(int button, t_data *img);
int		mouse_move(int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

/* ui_theme
 * set color themes: RED or BLUE
 */
void	init_theme(t_data *img);
void	key_theme(t_data *img, int key);

#endif
