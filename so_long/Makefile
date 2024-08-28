# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Name of the output executable
NAME = so_long

# Source files
SRC = main.c\
	manage_input/check_invalid_file.c\
	gnl/get_next_line.c\
	gnl/get_next_line_util.c\
	utility/ft_strlen.c\
	error/print_error.c\
	utility/ft_strjoin.c\
	utility/ft_split.c\
	manage_input/open_map.c\
	utility/check_map_utils.c\
	utility/queue.c\
	manage_input/check_invalid_map.c\
	utility/ft_strdup.c\
	utility/check_path_utils.c\
	manage_input/check_invalid_path.c\
	utility/ft_free.c\
	manage_map/manage_window.c\
	manage_map/action.c\
	utility/check_available_move.c\
	utility/init_map_info.c\
	utility/ft_itoa.c\
	utility/check_closed_exit.c\
# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the object files into the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -I.

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJ)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
