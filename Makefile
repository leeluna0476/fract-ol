TARGET=fractol
CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(HEADER_DIR)
RM=rm -fr
HEADER_DIR=./includes/
HEADERS=$(HEADER_DIR)ui.h $(HEADER_DIR)fractal.h
MLX_DIR=./mlx
MLX_FLAGS=-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS_DIR=./srcs/
SRCS=$(SRCS_DIR)main.c $(SRCS_DIR)ui_init_screen.c $(SRCS_DIR)ui_key.c $(SRCS_DIR)ui_mouse.c $(SRCS_DIR)ui_button.c $(SRCS_DIR)ui_menu.c $(SRCS_DIR)fractal_utils.c $(SRCS_DIR)fractal_utils_recurrence.c $(SRCS_DIR)fractal_utils_execute.c $(SRCS_DIR)logistic_utils.c $(SRCS_DIR)mandelbrot.c $(SRCS_DIR)julia.c $(SRCS_DIR)burningship.c $(SRCS_DIR)tricorn.c $(SRCS_DIR)logistic_map.c
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
