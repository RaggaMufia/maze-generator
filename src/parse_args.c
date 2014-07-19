#include <stdlib.h>
#include <maze_gen.h>

void					parse_args(register const char **const argv,
									register t_maze *const maze)
{
	maze->width = atoi(argv[1]);
	maze->height = atoi(argv[2]);
	parse_pos(argv[3], &maze->start);
	parse_pos(argv[4], &maze->end);
	maze->name = argv[5];
}
