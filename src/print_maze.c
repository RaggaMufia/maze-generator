#include <unistd.h>
#include <maze_gen.h>

void					print_maze(register const t_maze *const maze)
{
	register int		i;
	register int		j;

	i = 0;
	while (maze->data[i])
	{
		j = 0;
		while (maze->data[i][j])
		{
			write(1, &maze->data[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
