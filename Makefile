NAME=fractol
CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(HEADER_DIR)
RM=rm -fr
MLX_DIR=./srcs/mlx
MLX_FLAGS=-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
 
MAN_HEADER_DIR=./srcs/mandatory/headers/
MAN_HEADERS=$(MAN_HEADER_DIR)main.h $(MAN_HEADER_DIR)ui.h $(MAN_HEADER_DIR)fractal.h
MAN_SRCS_DIR=./srcs/mandatory/
MAN_MAINS=$(MAN_SRCS_DIR)main/main.c $(MAN_SRCS_DIR)main/main_utils.c $(MAN_SRCS_DIR)main/main_utils_parse.c 
MAN_UIS=$(MAN_SRCS_DIR)ui/ui_init_screen.c $(MAN_SRCS_DIR)ui/ui_key.c $(MAN_SRCS_DIR)ui/ui_key_utils.c $(MAN_SRCS_DIR)ui/ui_mouse.c $(MAN_SRCS_DIR)ui/ui_button.c $(MAN_SRCS_DIR)ui/ui_button_execute.c $(MAN_SRCS_DIR)ui/ui_menu.c $(MAN_SRCS_DIR)ui/ui_theme.c $(MAN_SRCS_DIR)ui/ui_menu_utils.c
MAN_FRACTALS=$(MAN_SRCS_DIR)fractal/fractal_utils.c $(MAN_SRCS_DIR)fractal/fractal_utils_recurrence.c $(MAN_SRCS_DIR)fractal/fractal_utils_execute.c $(MAN_SRCS_DIR)fractal/fractal3d_utils_recurrence.c $(MAN_SRCS_DIR)fractal/logistic_utils.c $(MAN_SRCS_DIR)fractal/julia3d_utils.c $(MAN_SRCS_DIR)fractal/mandelbrot.c $(MAN_SRCS_DIR)fractal/julia.c $(MAN_SRCS_DIR)fractal/burningship.c $(MAN_SRCS_DIR)fractal/tricorn.c $(MAN_SRCS_DIR)fractal/logistic_map.c $(MAN_SRCS_DIR)fractal/mandelbrot3d.c $(MAN_SRCS_DIR)fractal/julia3d.c $(MAN_SRCS_DIR)fractal/fractal3d_utils.c $(MAN_SRCS_DIR)fractal/fractal3d_utils_init.c $(MAN_SRCS_DIR)fractal/fractal3d_utils_matrix.c $(MAN_SRCS_DIR)fractal/mandelbrot3d_utils.c
MAN_SRCS=$(MAN_MAINS) $(MAN_UIS) $(MAN_FRACTALS)
MAN_OBJS=$(MAN_SRCS:.c=.o)

BONUS_HEADER_DIR=./srcs/bonus/headers/
BONUS_HEADERS=$(BONUS_HEADER_DIR)main_bonus.h $(BONUS_HEADER_DIR)ui_bonus.h $(BONUS_HEADER_DIR)fractal_bonus.h
BONUS_SRCS_DIR=./srcs/bonus/
BONUS_MAINS=$(BONUS_SRCS_DIR)main/main_bonus.c $(BONUS_SRCS_DIR)main/main_utils_bonus.c $(BONUS_SRCS_DIR)main/main_utils_parse_bonus.c 
BONUS_UIS=$(BONUS_SRCS_DIR)ui/ui_init_screen_bonus.c $(BONUS_SRCS_DIR)ui/ui_key_bonus.c $(BONUS_SRCS_DIR)ui/ui_key_utils_bonus.c $(BONUS_SRCS_DIR)ui/ui_mouse_bonus.c $(BONUS_SRCS_DIR)ui/ui_button_bonus.c $(BONUS_SRCS_DIR)ui/ui_button_execute_bonus.c $(BONUS_SRCS_DIR)ui/ui_menu_bonus.c $(BONUS_SRCS_DIR)ui/ui_theme_bonus.c $(BONUS_SRCS_DIR)ui/ui_menu_utils_bonus.c
BONUS_FRACTALS=$(BONUS_SRCS_DIR)fractal/fractal_utils_bonus.c $(BONUS_SRCS_DIR)fractal/fractal_utils_recurrence_bonus.c $(BONUS_SRCS_DIR)fractal/fractal_utils_execute_bonus.c $(BONUS_SRCS_DIR)fractal/fractal3d_utils_recurrence_bonus.c $(BONUS_SRCS_DIR)fractal/logistic_utils_bonus.c $(BONUS_SRCS_DIR)fractal/julia3d_utils_bonus.c $(BONUS_SRCS_DIR)fractal/mandelbrot_bonus.c $(BONUS_SRCS_DIR)fractal/julia_bonus.c $(BONUS_SRCS_DIR)fractal/burningship_bonus.c $(BONUS_SRCS_DIR)fractal/tricorn_bonus.c $(BONUS_SRCS_DIR)fractal/logistic_map_bonus.c $(BONUS_SRCS_DIR)fractal/julia3d_bonus.c
BONUS_SRCS=$(BONUS_MAINS) $(BONUS_UIS) $(BONUS_FRACTALS)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

#BONUS_HEADER_DIR=./srcs/bonus/headers/
#BONUS_HEADERS=$(BONUS_HEADER_DIR)main_bonus.h $(BONUS_HEADER_DIR)ui_bonus.h $(BONUS_HEADER_DIR)fractal_bonus.h
#BONUS_SRCS_DIR=./srcs/bonus/
#BONUS_MAINS=$(BONUS_SRCS_DIR)main/main_bonus.c $(BONUS_SRCS_DIR)main/main_utils_bonus.c $(BONUS_SRCS_DIR)main/main_utils_parse_bonus.c 
#BONUS_UIS=$(BONUS_SRCS_DIR)ui/ui_init_screen_bonus.c $(BONUS_SRCS_DIR)ui/ui_key_bonus.c $(BONUS_SRCS_DIR)ui/ui_mouse_bonus.c $(BONUS_SRCS_DIR)ui/ui_button_bonus.c $(BONUS_SRCS_DIR)ui/ui_button_execute_bonus.c $(BONUS_SRCS_DIR)ui/ui_menu_bonus.c $(BONUS_SRCS_DIR)ui/ui_theme_bonus.c
#BONUS_FRACTALS=$(BONUS_SRCS_DIR)fractal/fractal_utils_bonus.c $(BONUS_SRCS_DIR)fractal/fractal_utils_recurrence_bonus.c $(BONUS_SRCS_DIR)fractal/fractal_utils_execute_bonus.c $(BONUS_SRCS_DIR)fractal/logistic_utils_bonus.c $(BONUS_SRCS_DIR)fractal/mandelbrot_bonus.c $(BONUS_SRCS_DIR)fractal/julia_bonus.c $(BONUS_SRCS_DIR)fractal/burningship_bonus.c $(BONUS_SRCS_DIR)fractal/tricorn_bonus.c $(BONUS_SRCS_DIR)fractal/logistic_map_bonus.c
#BONUS_SRCS=$(BONUS_MAINS) $(BONUS_UIS) $(BONUS_FRACTALS)
#BONUS_OBJS=$(BONUS_SRCS:.c=.o)

ifeq ($(MAKECMDGOALS),bonus)
	HEADER_DIR=$(BONUS_HEADER_DIR)
	OBJS=$(BONUS_OBJS)
else
	HEADER_DIR=$(MAN_HEADER_DIR)
	OBJS=$(MAN_OBJS)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS)

$(MAN_OBJS): $(MAN_SRCS) $(MAN_HEADERS)

$(BONUS_OBJS): $(BONUS_SRCS) $(BONUS_HEADERS)

clean:
	$(RM) $(MAN_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
