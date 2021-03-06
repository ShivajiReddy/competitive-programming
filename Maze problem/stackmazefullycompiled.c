#include <stdio.h>
#include <stdlib.h>
#define MAX 8

//global vars

int i;
typedef struct position
{
	int x, y;
}position;
int flag;
int desY, desX,   count = -1, top = -1;
position tracker[MAX * MAX];
position finalroute[MAX * MAX];



//Stack Functions:
void push(int y, int x)
{
	top++;
	finalroute[top].y = y;
	finalroute[top].x = x;
}

void pop()
{
	if(top == -1)
	{
		printf("Underflow\n");
		return;
	}
	printf("(%d,%d)->", finalroute[top].y, finalroute[top].x);
	top--;
}


/*Traversal implementation:
  Returns 0 if if X and Y have been visited, 1 otherwise  */
int isVisited(int y, int x)
{
	for( i=0 ;i<=count; i++)
	{
		if(tracker[i].y == y && tracker[i].x == x)
		{
			return 0;
		}
	}
	return 1;
}

//Takes co-ordinates x and y adds it to tracker stack  
void doneVisiting(int y, int x)
{
	count++;
	tracker[count].y = y;
	tracker[count].x = x;
}


/* Takes the maze and the source co-ordinates as input
   Calls itself untill source is equal to destination and updates the finalRoute stack and exits
 */
int findRoute(int maze[][8], int srcY, int srcX)
{
	//Returns 1 if x and y equal to destination
	if(srcY == desX && srcX ==desY )
	{
		return 1;
	}

	doneVisiting(srcY, srcX);

	//GOING DOWN
	if(srcY != MAX - 1 && maze[srcY + 1][srcX] == 1 && isVisited((srcY + 1) , srcX))
	{
		flag = findRoute(maze, srcY + 1, srcX);
		if(flag == 1)
		{
			push(srcY + 1, srcX); //Adds X and Y to tracker stack
			return 1;
		}
	}

	//GOING RIGHT
	if(srcX != MAX - 1 && maze[srcY][srcX + 1] == 1 && isVisited((srcY) , (srcX + 1)))
	{
		flag = findRoute(maze, srcY, srcX+1);
		if(flag == 1)
		{
			push(srcY, srcX + 1);
			return 1;
		}
	}

	//GOING UP
	if(srcY != 0 && maze[srcY - 1][srcX] == 1 && isVisited((srcY - 1) , srcX))
	{
		flag = findRoute(maze, srcY - 1, srcX);
		if(flag == 1)
		{
			push(srcY - 1, srcX);
			return 1;
		}
	}

	//GOING LEFT
	if(srcX != 0 && maze[srcY][srcX - 1 ] == 1 && isVisited((srcY) , (srcX - 1 )))
	{
		flag = findRoute(maze, srcY, srcX-1);
		if(flag == 1)
		{
			push(srcY, srcX - 1);
			return 1;
		}
	}
}

int main()
{
	int srcX, srcY;

	int maze[MAX][MAX] ,m,n,i,j;
	printf("Enter the matrix dimensions\n");
	scanf("%d%d",&m,&n);
	printf("Enter matrix\n");
	for(i=0;i<m;i++)
          {
                    for(j=0;j<n;j++)
                    {
                              scanf("%d",&maze[i][j]);

                     }
                     printf("\n");
          }

	printf("Enter Source Co-ordinates: \n");
	scanf("%d%d", &srcY, &srcX);

	printf("Enter Destination Co-ordinates: \n");
	scanf("%d%d", &desX, &desY);

	printf("\n*******Calculating Path From (%d, %d) to (%d, %d)*******\n", srcY, srcX, desX, desY);

	findRoute(maze, srcY, srcX);

	while(top != -1)
	{
		pop();
	}

	printf("End\n");
}
