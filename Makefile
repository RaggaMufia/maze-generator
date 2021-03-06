SRC_PATH		=	src/
OBJ_PATH		=	obj/

SRC				=	main.c \
					parse_pos.c \
					check_args.c \
					init_maze.c \
					check_maze.c \
					print_maze_struct.c \
					print_maze.c \
					generate_corridor.c \
					free_array.c \
					create_maze.c

OBJ				=	$(patsubst %.c, $(OBJ_PATH)%.o,$(SRC))

CC				=	gcc
FLAGS			=	-g -O3 -Wall -Werror -Wextra
HEADER			=	-I./include
NAME			=	maze-gen

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(HEADER) $(OBJ) -o $@

$(patsubst %, $(OBJ_PATH)%,%.o): $(SRC_PATH)$(notdir %.c)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
