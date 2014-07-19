#include <maze_gen.h>

void					print_maze_struct(register const t_maze *const maze)
{
	dprintf(2, "maze:\n");
	dprintf(2, "width  = %d\n", maze->width);
	dprintf(2, "height = %d\n", maze->height);
	dprintf(2, "start  = %d,%d\n", maze->start.x, maze->start.y);
	dprintf(2, "end    = %d,%d\n", maze->end.x, maze->end.y);
	dprintf(2, "name   = %s\n", maze->name);
}
