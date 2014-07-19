#include <stdlib.h>
#include <maze_gen.h>

void					init_maze(register t_maze *const maze,
									register const char **const argv)
{
	maze->width = atoi(argv[1]);
	maze->height = atoi(argv[2]);
	parse_pos(argv[3], &maze->start);
	parse_pos(argv[4], &maze->end);
	maze->name = argv[5];
	maze->data = NULL;
	maze->file = NULL;
}
