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

### Functions 함수
|No.|File|Function|
|---|---|---|
|1|fractal_utils.c|void		init_complex(t_complex *c, double r, double i);|
|2||void		init_xy(t_xy *xy, int x, int y);|
|3||double		c_abs(t_complex z);|
|4||void		c_default_or_arg(t_data *img, t_complex *c);|
|5||void		init_complex(t_complex *c, double r, double i);)|
