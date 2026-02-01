SRC = 	./main.c\
		./utils.c\
		./get_next_line.c\
		./parser.c\
		./ft_split.c\
		./init_mlx.c\
		./mlx_usage.c\
		./mlx_commands.c\

C = cc
FLAGS = -Wall -Werror -Wextra

NAME = so_long
OBJ_DIR = objets

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(C) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -Lmlx -lmlx -lXext -lX11 -Iincludes -Imlx -g -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
