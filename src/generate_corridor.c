#include <maze_gen.h>

t_point					generate_corridor(register const t_maze *const maze,
										register t_point *const start,
										register t_point *const dir,
										register t_point *const dest,
										register int size)
{
	register int		i;
	volatile t_point	crd;

	dest->x = (dest->x < 0 ? 0 : dest->x) % maze->width;
	dest->y = (dest->y < 0 ? 0 : dest->y) % maze->height;
	start->x = (start->x < 0 ? 0 : start->x) % maze->width;
	start->y = (start->y < 0 ? 0 : start->y) % maze->height;
	dir->x = dir->x > 0 ? 1 : (dir->x < 0 ? -1 : dir->x);
	dir->y = dir->y > 0 ? 1 : (dir->y < 0 ? -1 : dir->y);
	size = size < 0 ? 0 : size;
	i = 0;
	while (i < size)
	{
		crd.x = start->x + i * dir->x;
		crd.y = start->y + i * dir->y;
		if (maze->data[crd.y][crd.x] == FULL)
		{
			if ((crd.x <= 1 || crd.x >= maze->width - 2
				|| crd.y <= 1 || crd.y >= maze->height - 2)
				|| (maze->data[crd.y + dir->y * 2][crd.x + dir->x * 2] != FULL))
			{
				maze->data[crd.y][crd.x] = EMPTY;
				return (crd);
			}
			maze->data[crd.y][crd.x] = EMPTY;
		}
		if (crd.x == dest->x && crd.y == dest->y)
			break ;
		++i;
	}
	return (crd);
}
