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

int						check_empty_around_point(t_maze *maze, t_point *p)
{
	int					c;

	if (maze->data[p->y][p->x] != EMPTY)
		return (0);
	if (maze->data[p->y][p->x] != )
	c = 0;
	c += maze->data[p->y - 1][p->x - 1] != EMPTY;
	c += maze->data[p->y - 1][p->x] != EMPTY;
	c += maze->data[p->y - 1][p->x + 1] != EMPTY;
	c += maze->data[p->y][p->x - 1] != EMPTY;
	c += maze->data[p->y][p->x + 1] != EMPTY;
	c += maze->data[p->y + 1][p->x - 1] != EMPTY;
	c += maze->data[p->y + 1][p->x] != EMPTY;
	c += maze->data[p->y + 1][p->x + 1] != EMPTY;
	if (c > 1)
		return (0);
	return (1);
}

int						check_within_borders(t_point *p, int *w, int *h)
{
	if (p.x < 1 || p.y < 1 || p.x > *w - 2 || p.y > *h - 2)
		return (0);
	return (1);
}

int						generate_cell(t_maze *maze, t_point p)
{
	if (!check_within_borders(&p, &maze->width, &maze->height))
		return (0);
	if ()
}

void					generate_main_path(t_maze *maze)
{
	t_point				current;
	t_point				dir;

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
