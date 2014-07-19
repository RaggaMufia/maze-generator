#include <maze_gen.h>

int						main(const int argc, const char **const argv)
{
	t_maze				maze;

	check_args(&argc);
	init_maze(&maze);
	parse_args(argv, &maze);
	check_maze(&maze);
	print_maze_struct(&maze);
	return (0);
}
