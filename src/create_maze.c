#include <stdlib.h>
#include <stdio.h>
#include <maze_gen.h>

void					create_maze(t_maze *maze, char state)
{
	register int		y;
	register int		x;

	if (!(maze->data = malloc(sizeof(char *) * maze->height + 1)))
	{
		perror("create_maze()");
		exit(-1);
	}
	y = 0;
	while (y < maze->height)
	{
		if (!(maze->data[y] = malloc(sizeof(char) * maze->width + 1)))
		{
			perror("create_maze()");
			exit(-1);
		}
		x = 0;
		while (x < maze->width)
		{
			maze->data[y][x] = state;
			++x;
		}
		maze->data[y][maze->width] = '\0';
		++y;
	}
	maze->data[maze->height] = '\0';
	maze->data[maze->start.y][maze->start.x] = START;
	maze->data[maze->end.y][maze->end.x] = END;
}
