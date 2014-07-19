#include <maze_gen.h>

void					parse_pos(register const char *const a,
									register t_point *const p)
{
	int					i;

	i = -1;
	while (a[++i] != ',')
		p->x = (p->x * 10) + ((a[i] - 48) % 10);
	while (a[++i])
		p->y = (p->y * 10) + ((a[i] - 48) % 10);
}
