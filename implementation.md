# Implementation 구현
## Categories 분류
|No.|Fractal|UI|Main|Header|
|---|---|---|---|---|
|1|mandelbrot.c|ui_init_screen.c|main.c|fractal.h|
|2|julia.c|ui_menu_utils.c|main_utils.c|ui.h|
|3|burningship.c|ui_menu.c|main_utils_parse.c|main.h|
|4|tricorn.c|ui_key.c|||
|5|fractal_utils.c|ui_key_utils.c|||
|6|fractal_utils_recurrence.c|ui_mouse.c|||
|7|fractal_utils_execute.c|ui_button.c|||
|8|logistic_map.c|ui_button_execute.c|||
|9|logistic_utils.c|ui_theme.c|||
|10|julia3d.c||||
|11|julia3d_utils.c||||
|12|fractal_3d_utils_recurrence.c||||

## Functions 함수
### Fractals
|No.|File|Function|
|---|---|---|
|1|**fractal_utils.c**|```void	init_complex(t_complex *c, double r, double i);```|
|2||```void	init_xy(t_xy *xy, int x, int y);```|
|3||```double	c_abs(t_complex z);```|
|4||```void	c_default_or_arg(t_data *img, t_complex *c);```|
|5|**fractal_recurrence.c**|```void	mandelbrot_julia_next(t_complex *z, t_complex c);```|
|6||```void	burningship_next(t_complex *z, t_complex c);```|
|7||```void	tricorn_next(t_complex *z, t_complex c);```|
|8||```int	iter_complex(t_complex *z, t_complex c, int iter, int flag);```|
|9|**fractal_utils_execute.c**|```int	turn_off_trans(int color);```|
|10||```void	draw_mandelbrot(double z_abs, t_data *img, int i, int j);```|
|11||```void	draw_julia(double z_abs, t_data *img, int i, int j);```|
|12||```void	draw_burningship(double z_abs, t_data *img, int i, int j);```|
|13||```void	draw_tricorn(double z_abs, t_data *img, int i, int j);```|
|14|**fractal3d_recurrence.c**|```void	iter_julia3d(t_julia3d *dots, t_complex c, int z_value);```|
|15|**logistic_utils.c**|```bool	check_inbox(t_xy xy);```|
|16||```void	make_box_black(t_data *img);```|
|17||```void	logistic_next(double r, double *x);```|
|18|**julia3d_utils.c**|```bool	all_diverge(t_complex c);```|
|19||```int	get_total_slices(t_complex c);```|
|20||```void	set_dot_values(t_julia3d *dot, int x_value, int y_value, int z_value);```|
|21||```int	find_layer(t_data *img, t_julia3d *dots);```|
|22||```void	draw_julia3d(t_data *img, t_julia3d *dots, int total_dots);```|
|23|**mandelbrot.c**|```void	mandelbrot(t_data *img);```|
|24|**julia.c**|```void	julia(t_data *img);```|
|25|**burningship.c**|```void	burningship(t_data *img);```|
|26|**tricorn.c**|```void	tricorn(t_data *img);```|
|27|**julia3d.c**|```void	julia3d(t_data *img);```|

### UI
|No.|File|Function|
|---|---|---|
|1|**ui_init_screen.c**|```void	my_mlx_pixel_put(t_data *data, int x, int y, int color);```|
|2||```void	init_screen(t_data *img);```|
|3||```void	init_axis(t_data *img);```|
|4||```void	init_box(t_data *img);```|
|5||```void	clear_box(t_data *img);```|
|6|**ui_menu.c**|```bool	check_menu(int a, int b);```|
|7||```void	write_header(t_data *img, int *line, int *gap);```|
|8||```void	write_2ds(t_data *img, int *line, int *gap);```|
|9||```void	write_3ds(t_data *img, int *line, int *gap);```|
|10||```void	write_menu(t_data *img);```|
