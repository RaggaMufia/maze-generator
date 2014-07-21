#include <stdlib.h>

void					free_array(register char **const array)
{
	register int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
