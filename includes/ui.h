/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +# +  +:+       +# +      */
/*                                                +# +# +# +# +# +   +# +     */
/*   Created: 2023/12/02 12:59:13 by seojilee          # +#     # +#          */
/*   Updated: 2023/12/06 08:55:31 by seojilee         ###   ########.fr       */
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

# define KL				0
# define KR				1
# define KD				2
# define KU				3
# define KEYS			4

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

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mouse_x;
	int		mouse_y;
	int		center_x;
	int		center_y;
	int		key_x;
	int		key_y;
	double	zoom;
	int		iter;
	bool	button_on_off[BUTTONS];
	bool	keys_on_off[KEYS];
}			t_data;

typedef struct s_ab {
	int	a;
	int	b;
}				t_ab;

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

/* ui_button
 * set buttons
 */
void	make_button(t_data *img, t_ab start, t_ab button_wh, int color);
void	_button(t_data *img, int start_x, int start_y);
void	make_all_false(t_data *img);

/* ui_key
 * receive key hooks
 * control keys
 */
void	init_zoom_center(t_data *img);
void	init_key_xy(t_data *img);
void	control_key(int key, t_data *img);
void	hook(t_data *img);

/* ui_mouse
 * receive mouse hooks
 */
void	call_set(t_data *img);
int		mouse_move(int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

#endif
