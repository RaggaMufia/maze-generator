#ifndef MAZE_GEN_H
# define MAZE_GEN_H

#include <stdio.h>

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
	char				*name;
	FILE				*file;
}						t_maze;

void					parse_pos(char *a, t_point *p);
void					check_args(const int *const argc);
void					init_maze(t_maze *maze);
void					parse_args(char **argv, t_maze *maze);
void					check_maze(t_maze *maze);
void					print_maze_struct(t_maze *maze);

#endif