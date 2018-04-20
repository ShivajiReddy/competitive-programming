#include <stdio.h>
#include <stdlib.h>
#define MAX 8



//global vars


typedef struct position {
	int y, x;
} position;

int desy, desx, flag, count = -1, top = -1;
position tracker[MAX * MAX];
position finalroute[MAX * MAX];



//Stack Functions: 
void pushStack(int y, int x) {
	top++;
	finalroute[top].y = y;
	finalroute[top].x = x;
}

void popStack() {
	if(top == -1) {
		printf("Underflow\n");
		return;
	}
	printf("(%d,%d)->", finalroute[top].y, finalroute[top].x);
	top--;
}




//traversal implementation:
int isVisited(int y, int x)
{
	for(int i=0 ;i<=count;i++) {
		if(tracker[i].y == y && tracker[i].x == x)
		{
			return 0;
		}
	}
	return 1;
}

void doneVisiting(int y, int x) {
	count++;
	tracker[count].y = y;
	tracker[count].x = x;
}

int findRoute(int maze[][8], int srcy, int srcx) {
	
	if(srcy == desx && srcx ==desy ) {
		return 1;
	}

	doneVisiting(srcy, srcx);

	//try going DOWN
	if(srcy != MAX - 1 && maze[srcy + 1][srcx] == 1 && isVisited((srcy + 1) , srcx)) {
		flag = findRoute(maze, srcy + 1, srcx);
		if(flag == 1) {
			pushStack(srcy + 1, srcx);
			return 1;
		}
	}
	
	//try going RIGHT
	if(srcx != MAX - 1 && maze[srcy][srcx + 1] == 1 && isVisited((srcy) , (srcx + 1))) {
		flag = findRoute(maze, srcy, srcx+1);
		if(flag == 1) {		
			pushStack(srcy, srcx + 1);
			return 1;
		}
	}
	
	//try going UP
	if(srcy != 0 && maze[srcy - 1][srcx] == 1 && isVisited((srcy - 1) , srcx)) {
		flag = findRoute(maze, srcy - 1, srcx);
		if(flag == 1) {	
			pushStack(srcy - 1, srcx);
			return 1;
		}
	}

	//try going LEFT
	if(srcx != 0 && maze[srcy][srcx - 1 ] == 1 && isVisited((srcy) , (srcx - 1 ))) {
		flag = findRoute(maze, srcy, srcx-1);
		if(flag == 1) {
			pushStack(srcy, srcx - 1);
			return 1;
		}
	}
}

int main() {
	int srcx, srcy;

	int maze[MAX][MAX] = {
							{0,0,1,0,0,1,1,1},
					  		{0,1,1,1,1,1,0,1},
					  		{0,0,1,0,0,0,0,1},
					  		{1,1,1,1,1,1,1,1},
					  		{0,0,0,1,0,0,1,0},
					  		{0,0,0,0,0,0,1,0},
					  		{0,0,1,0,0,1,1,0},
					  		{0,0,1,0,1,1,0,0}
					  	};
	
	printf("Enter Source Co-ordinates: \n");
	scanf("%d%d", &srcy, &srcx);
	
	printf("Enter Destination Co-ordinates: \n");
	scanf("%d%d", &desx, &desy);
	
	printf("\n*******Calculating Path From (%d, %d) to (%d, %d)*******\n", srcy, srcx, desx, desy);
	
	findRoute(maze, srcy, srcx); 

	while(top != -1) {
		popStack();
	}

	printf("End\n");
}