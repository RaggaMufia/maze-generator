#include <stdlib.h>
#include <maze_gen.h>

void					check_maze(register t_maze *const maze)
{
	maze->width = maze->width < 2 ? 2 : maze->width;
	maze->height = maze->height < 2 ? 2 : maze->height;
	maze->start.x = abs(maze->start.x) % maze->width;
	maze->start.y = abs(maze->start.y) % maze->height;
	maze->end.x = abs(maze->end.x) % maze->width;
	maze->end.y = abs(maze->end.y) % maze->height;
}
