#include <stdio.h>

typedef struct 
{
	int vert;
	int horiz;
}offsets;

offsets move[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct 
{
	int row; 
	int col;
	int dir;
}element;

enum {FALSE, TRUE};


int maze[20][20] = {
					 {0, 0, 0, 0, 0, 0},
					 {0, 1, 1, 0, 1, 0},
					 {0, 0, 1, 1, 1, 0},
					 {0, 0,	0, 0, 1, 0},
					 {0, 1, 0, 0, 0, 0},
				   };


void main(int argc, char const *argv[])
{
	int exit_row = 3, exit_col = 4;
	int row, col, next_row, next_col, dir, found = FALSE, top, i;
	int mark[20][20] = {{0}};
	element s[200], pos;

	mark[1][1] = 1;
	pos.row = 1;
	pos.col = 1;
	pos.dir = 0;

	s[top = 0] = pos;

	while(top != -1 && !found)
	{
		pos = s[top--];
		row = pos.row;
		col = pos.col;
		dir = pos.dir;

		while(dir < 4 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == exit_row && next_col == exit_col)
				found = TRUE;
			else if(maze[next_row][next_col] == 1 && maze[next_row][next_col] == 1)
			{
				mark[next_row][next_col] = 1;
				pos.row = row, pos.col = col, pos.dir = ++dir;

				s[++top] = pos;
				row = next_row, col = next_col, dir = 0;
			}
			else 
				++dir;
		}
	}

	if(found)
	{
		printf("Path:\n");
		for (int i = 0; i < top; i++)
		{
			printf("%3d%3d\n", s[i].row, s[i].col);
		}
		printf("%3d%3d\n", row, col);
		printf("%3d%3d\n", exit_row, exit_col);
	}
	else 
		printf("Maze does not have a path\n");


	//return 0;
}
