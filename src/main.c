#include <time.h>
#include <stdlib.h>
#include <maze_gen.h>

inline static int		op_abs(register const int *const n)
{
	return (*n < 0 ? -(*n) : *n);
}

void					get_random_path_dir(register t_point *const dir,
											register const t_point *const current,
											register const t_point *const end)
{
	if (random() % 2)
	{
		dir->x = end->x - current->x;
		dir->x = dir->x != 0 ? dir->x / op_abs(&dir->x) : dir->x;
		dir->y = 0;
	}
	else
	{
		dir->y = end->y - current->y;
		dir->y = dir->y != 0 ? dir->y / op_abs(&dir->y) : dir->y;
		dir->x = 0;
	}
}

void					generate_main_path(t_maze *maze)
{
	t_point				current;
	t_point				dir;
	t_point				old_dir;

	current.x = maze->start.x;
	current.y = maze->start.y;
	while (current.x != maze->end.x || current.y != maze->end.y)
	{
		dir.x = 0;
		dir.y = 0;
		get_random_path_dir(&dir, &current, &maze->end);
		current = generate_corridor(maze, &current, &dir, &maze->end, 2);
	}
}

void					generate_maze(t_maze *maze)
{
	generate_main_path(maze);
}

int						main(const int argc, const char **const argv)
{
	t_maze				maze;

	srandom(time(NULL));
	check_args(&argc);
	init_maze(&maze, argv);
	check_maze(&maze);
	print_maze_struct(&maze);
	create_maze(&maze, FULL);
	generate_maze(&maze);
	print_maze(&maze);
	free_array(maze.data);
	return (0);
}
