TARGET=fractol
CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(HEADER_DIR)
RM=rm -fr
HEADER_DIR=./srcs/headers/
HEADERS=$(HEADER_DIR)main.h $(HEADER_DIR)ui.h $(HEADER_DIR)fractal.h $(HEADER_DIR)ft_printf.h
MLX_DIR=./srcs/mlx
MLX_FLAGS=-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS_DIR=./srcs/
SRCS=$(SRCS_DIR)main.c $(SRCS_DIR)main_utils.c $(SRCS_DIR)main_utils_parse.c $(SRCS_DIR)ui_init_screen.c $(SRCS_DIR)ui_key.c $(SRCS_DIR)ui_mouse.c $(SRCS_DIR)ui_button.c $(SRCS_DIR)ui_button_execute.c $(SRCS_DIR)ui_menu.c $(SRCS_DIR)ui_theme.c $(SRCS_DIR)fractal_utils.c $(SRCS_DIR)fractal_utils_recurrence.c $(SRCS_DIR)fractal_utils_execute.c $(SRCS_DIR)logistic_utils.c $(SRCS_DIR)mandelbrot.c $(SRCS_DIR)julia.c $(SRCS_DIR)burningship.c $(SRCS_DIR)tricorn.c $(SRCS_DIR)logistic_map.c $(SRCS_DIR)ft_printf.c $(SRCS_DIR)ft_putchar_fd.c $(SRCS_DIR)ft_puthex_s_fd.c $(SRCS_DIR)ft_puthex_l_fd.c $(SRCS_DIR)ft_putint_fd.c $(SRCS_DIR)ft_putmem_fd.c $(SRCS_DIR)ft_puts.c $(SRCS_DIR)ft_putstr_fd.c $(SRCS_DIR)ft_putunbr_fd.c
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(TARGET) $(OBJS)

$(OBJS): $(SRCS) $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: clean all

.PHONY: all clean fclean re
