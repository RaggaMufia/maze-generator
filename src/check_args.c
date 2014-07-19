#include <stdlib.h>
#include <maze_gen.h>

void					check_args(const int *const argc)
{
	if (*argc > 6)
		dprintf(2, "Too many arguments !\n");
	else if (*argc < 6)
		dprintf(2, "Not enough arguments !\n");
	if (*argc != 6)
	{
		dprintf(2, "usage:\n");
		dprintf(2, "./maze-gen width height start end filename\n");
		dprintf(2, "example:\n");
		dprintf(2, "./maze-gen 100 100 3,10 90,80 test-maze.txt\n");
		exit(-1);
	}
}
