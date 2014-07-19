#include <maze_gen.h>

void					init_maze(t_maze *maze)
{
	maze->start.x = 0;
	maze->start.y = 0;
	maze->end.x = 0;
	maze->end.y = 0;
	maze->width = 0;
	maze->height = 0;
	maze->data = NULL;
	maze->name = NULL;
	maze->file = NULL;
}
