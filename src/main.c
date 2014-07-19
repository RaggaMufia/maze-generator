#include <maze_gen.h>

int						main(int argc, char **argv)
{
	t_maze				maze;

	check_args(&argc);
	init_maze(&maze);
	parse_args(argv, &maze);
	check_maze(&maze);
	print_maze_struct(&maze);
	return (0);
}
