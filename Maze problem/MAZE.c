#include<stdio.h>
#define EXIT_ROW 4
#define EXIT_COL 6

typedef struct offsets{
  int vert;
  int horiz;
}offsets;

offsets move[4] = {{0,1},{1,0},{0,-1},{-1,0}};

typedef struct element{
  int row;
  int col;
  int dir;
}element;

int maze[8][8] = {
  {0,0,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,1,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,0,0,1,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,1,0,0,1,1,0},
  {0,0,1,0,1,1,0,0}
};

int main(){

  int row,col,nextRow,nextCol,dir,found = 0,top,i;
  int mark[8][8] = {{0}};
  element s[200],pos;

  mark[0][2] = 1;
  pos.row = 0;
  pos.col = 2;
  pos.dir = 0;

  s[top=0] = pos;

  while(top!=-1 && !found){
    pos = s[top--];
    row = pos.row;
    col = pos.col;
    dir = pos.dir;

    while(dir<4 && !found){
      nextRow = row + move[dir].vert;
      nextCol = col + move[dir].horiz;

      if(nextRow==EXIT_ROW && nextCol==EXIT_COL)
        found = 1;
      else if(maze[nextRow][nextCol]==1  &&  mark[nextRow][nextCol]==0){
        mark[nextRow][nextCol] = 1;
        pos.row = row;
        pos.col = col;
        pos.dir = ++dir;

        s[++top] = pos;
        row = nextRow;
        col = nextCol;
        dir = 0;
      }
      else
        ++dir;
    }
  }

  if(found){
    printf("\nPATH is \n");
    printf("Row Col\n");
    for(i = 0;i<=top;i++){
      printf("%d %d\n",s[i].row,s[i].col);
    }

    printf("%d %d\n",row,col);
    printf("%d %d\n",EXIT_ROW,EXIT_COL);
  }
  else
  printf("Doesn't have a path!!");
}