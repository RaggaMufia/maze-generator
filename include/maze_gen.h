#ifndef MAZE_GEN_H
# define MAZE_GEN_H

# include <stdio.h>

# define EMPTY			'0'
# define FULL			'1'
# define START			'S'
# define END			'E'

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_maze
{
	int					width;
	int					height;
	t_point				start;
	t_point				end;
	char				**data;
	const char			*name;
	FILE				*file;
	int					gen_status[2];
}						t_maze;

void					parse_pos(register const char *a,
									register t_point *const p);
void					check_args(const int *const argc);
void					free_array(register char **const array);
void					init_maze(register t_maze *const maze,
									register const char **const argv);
void					check_maze(register t_maze *const maze);
void					create_maze(t_maze *maze, char state);
void					print_maze_struct(register const t_maze *const maze);
void					print_maze(register const t_maze *const maze);
t_point					generate_corridor(register const t_maze *const maze,
										register t_point *const start,
										register t_point *const dir,
										register t_point *const dest,
										register int size);
#endif
