#include <maze_gen.h>

void					generate_path(t_maze *maze)
{
	
}

void					generate_maze(t_maze *maze)
{
	(void)maze;
}

int						main(const int argc, const char **const argv)
{
	t_maze				maze;

	check_args(&argc);
	init_maze(&maze, argv);
	check_maze(&maze);
	print_maze_struct(&maze);
	return (0);
}
