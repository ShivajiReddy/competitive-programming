//this code will generate maze randomly and try to solve it 
//by hitting on enter in the keybord
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Direction { DOWN, RIGHT, UP, LEFT };
const int MAX_DOTS = 100;  // maximum possible dots for maze

void mazeTraversal( char [][ 12 ], const int, const int, int, int, int );
void mazeGenerator( char [][ 12 ], int *, int * );
void printMaze( const char[][ 12 ] );
bool validMove( const char [][ 12 ], int, int );
bool coordsAreEdge( int, int );

int main()
{
   char maze[ 12 ][ 12 ];
   int xStart, yStart, x, y;

   srand( time( 0 ) );

   for ( int loop = 0; loop < 12; ++loop )
      for ( int loop2 = 0; loop2 < 12; ++loop2 )
         maze[ loop ][ loop2 ] = '#';

   mazeGenerator( maze, &xStart, &yStart );

   x = xStart;  // starting row
   y = yStart;  // starting col

   mazeTraversal( maze, xStart, yStart, x, y, RIGHT );
   return 0;
}

// Assume that there is exactly 1 entrance and exactly 1 exit to the maze.
void mazeTraversal( char maze[][ 12 ], const int xCoord, const int yCoord,
                   int row, int col, int direction )
{
   static bool flag = false;   // starting position flag

   maze[ row ][ col ] = 'x';  // insert X at current location
   printMaze( maze );

   if ( coordsAreEdge( row, col ) && row != xCoord && col != yCoord ) {
      cout << "Maze successfully exited!\n\n";
      return;   // maze is complete
   }
   else if ( row == xCoord && col == yCoord && flag ) {
      cout << "Arrived back at the starting location.\n\n";
      return;
   }
   else {
      flag = true;

      for ( int move = direction, count = 0; count < 4; 
            ++count, ++move, move %= 4 )

         switch( move ) {
            case DOWN:
               if ( validMove( maze, row + 1, col ) ) { // move down
                  mazeTraversal( maze, xCoord, yCoord, row + 1, col, LEFT );
                  return;
               }
               break;
            case RIGHT:
               if ( validMove( maze, row, col + 1 ) ) { // move right
                  mazeTraversal( maze, xCoord, yCoord, row, col + 1, DOWN );
                  return;
               }b
               break;
            case UP:
               if ( validMove( maze, row - 1, col ) ) { // move up
                  mazeTraversal( maze, xCoord, yCoord, row - 1, col, RIGHT );
                  return;
               }
               break;
            case LEFT:
               if ( validMove( maze, row, col - 1 ) ) { // move left
                  mazeTraversal( maze, xCoord, yCoord, row, col - 1, UP );
                  return;
               }
               break;
         }
   }
}

bool validMove( const char maze[][ 12 ], int r, int c )
{
   return ( r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[ r ][ c ] != '#' );
}

bool coordsAreEdge( int x, int y )
{
   if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) )
      return true;
   else if ( ( y == 0 || y == 11 ) && ( x >= 0 && x <= 11 ) )
      return true;
   else
      return false;
}

void printMaze( const char maze[][ 12 ] )
{
   for ( int x = 0; x < 12; ++x ) {

      for ( int y = 0; y < 12; ++y )
         cout << maze[ x ][ y ] << ' ';

      cout << '\n';
   }

   cout << "Hit return to see next move";
   cin.get();
}

void mazeGenerator(char maze[][ 12 ], int *xPtr, int *yPtr )
{
   int a, x, y, entry, exit;

   do {
      entry = rand() % 4;
      exit = rand() % 4;
   } while ( entry == exit );

   // Determine entry position

   if ( entry == 0 ) {
      *xPtr = 1 + rand() % 10;    // avoid corners
      *yPtr = 0;
      maze[ *xPtr ][ 0 ] = '.';
   }
   else if ( entry == 1 ) {
      *xPtr = 0;
      *yPtr = 1 + rand() % 10;
      maze[ 0 ][ *yPtr ] = '.';
   }
   else if ( entry == 2 ) {
      *xPtr = 1 + rand() % 10;
      *yPtr = 11;
      maze[ *xPtr ][ 11 ] = '.';
   }
   else {
      *xPtr = 11;
      *yPtr = 1 + rand() % 10;
      maze[ 11 ][ *yPtr ] = '.';
   }

   // Determine exit location

   if ( exit == 0 ) {
      a = 1 + rand() % 10;
      maze[ a ][ 0 ] = '.';
   }
   else if ( exit == 1 ) {
      a = 1 + rand() % 10;
      maze[ 0 ][ a ] = '.';
   }
   else if ( exit == 2 ) {
      a = 1 + rand() % 10;
      maze[ a ][ 11 ] = '.';
   }
   else {
      a = 1 + rand() % 10;
      maze[ 11 ][ a ] = '.';
   }

   for ( int loop = 1; loop < MAX_DOTS; ++loop ) {   // add dots randomly
      x = 1 + rand() % 10;
      y = 1 + rand() % 10;
      maze[ x ][ y ] = '.';
   }
}




/*

//this code will generate a maze 30x15
#include <iostream>
#include <stdlib.h>
#include <time.h>

enum Direction { DOWN, RIGHT, UP, LEFT };
const int ROWS = 15, COLS = 30;

void mazeTraversal( char [][ COLS ], const int, const int, int, int, int );
void mazeGenerator( char [][ COLS ], int *, int * );
void printMaze( const char[][ COLS ] );
bool validMove( const char [][ COLS ], int, int );
bool coordsAreEdge( int, int );

int main()
{
   char maze[ ROWS ][ COLS ];
   int xStart, yStart, x, y;

   srand( time( 0 ) );

   for ( int loop = 0; loop < ROWS; ++loop )
      for ( int loop2 = 0; loop2 < COLS; ++loop2 )
         maze[ loop ][ loop2 ] = '#';

   mazeGenerator( maze, &xStart, &yStart );

   x = xStart;  // starting row
   y = yStart;  // starting col

   mazeTraversal( maze, xStart, yStart, x, y, RIGHT );
   return 0;
}

// Assume that there is exactly 1 entrance and exactly 1 exit to the maze.
void mazeTraversal( char maze[][ COLS ], const int xCoord, const int yCoord,
                   int row, int col, int direction )
{
   static bool flag = false;   // starting position flag

   maze[ row ][ col ] = 'x';  // insert x at current location
   printMaze( maze );

   if ( coordsAreEdge( row, col ) && row != xCoord && col != yCoord ) {
      cout << endl << "Maze successfully exited!\n\n";
      return;   // maze is complete
   }
   else if ( row == xCoord && col == yCoord && flag ) {
      cout << "\nArrived back at the starting location.\n\n";
      return;
   }
   else {
      flag = true;

      for ( int move = direction, count = 0; count < 4; 
            ++count, ++move, move %= 4 )
         switch( move ) {
            case DOWN:
               if ( validMove( maze, row + 1, col ) ) { // move down
                  mazeTraversal( maze, xCoord, yCoord, row + 1, col, LEFT );
                  return;
               }
               break;
            case RIGHT:
               if ( validMove( maze, row, col + 1 ) ) { // move right
                  mazeTraversal( maze, xCoord, yCoord, row, col + 1, DOWN );
                  return;
               }
               break;
            case UP:
               if ( validMove( maze, row - 1, col ) ) { // move up
                  mazeTraversal( maze, xCoord, yCoord, row - 1, col, RIGHT );
                  return;
               }
               break;
            case LEFT:
               if ( validMove( maze, row, col - 1 ) ) { // move left
                  mazeTraversal( maze, xCoord, yCoord, row, col - 1, UP );
                  return;
               }
               break;
         }
   }
}

bool validMove( const char maze[][ COLS ], int r, int c )
{
   return ( r >= 0 && r <= ROWS - 1 && c >= 0 && c <= COLS - 1 &&
           maze[ r ][ c ] != '#' );  // a valid move
}

bool coordsAreEdge( int x, int y )
{
   if ( ( x == 0 || x == ROWS - 1 ) && ( y >= 0 && y <= COLS - 1 ) )
      return true;
   else if ( ( y == 0 || y == COLS - 1 ) && ( x >= 0 && x <= ROWS - 1 ) )
      return true;
   else
      return false;
}

void printMaze( const char maze[][ COLS ] )
{
   for ( int x = 0; x < ROWS; ++x ) {

      for ( int y = 0; y < COLS; ++y )
         cout << maze[ x ][ y ] << ' ';

      cout << '\n';
   }

   cout << "\nHit return to see next move";
   cin.get();
}

void mazeGenerator( char maze[][ COLS ], int *xPtr, int *yPtr )
{
   int a, x, y, entry, exit;

   do {
      entry = rand() % 4;
      exit = rand() % 4;
   } while ( entry == exit );

   // Determine entry position
   if ( entry == 0 ) {
      *xPtr = 1 + rand() % ( ROWS - 2 );    // avoid corners
      *yPtr = 0;
      maze[ *xPtr ][ *yPtr ] = '.';
   }
   else if ( entry == 1 ) {
      *xPtr = 0;
      *yPtr = 1 + rand() % ( COLS - 2 );
      maze[ *xPtr ][ *yPtr ] = '.';
   }
   else if ( entry == 2 ) {
      *xPtr = 1 + rand() % ( ROWS - 2 );
      *yPtr = COLS - 1;
      maze[ *xPtr ][ *yPtr ] = '.';
   }
   else {
      *xPtr = ROWS - 1;
      *yPtr = 1 + rand() % ( COLS - 2 );
      maze[ *xPtr ][ *yPtr ] = '.';
   }

   // Determine exit location
   if ( exit == 0 ) {
      a = 1 + rand() % ( ROWS - 2 );
      maze[ a ][ 0 ] = '.';
   }
   else if ( exit == 1 ) {
      a = 1 + rand() % ( COLS - 2 );
      maze[ 0 ][ a ] = '.';
   }
   else if ( exit == 2 ) {
      a = 1 + rand() % ( ROWS - 2 );
      maze[ a ][ COLS - 1 ] = '.';
   }
   else {
      a = 1 + rand() % ( COLS - 2 );
      maze[ ROWS - 1 ][ a ] = '.';
   }

   for ( int loop = 1; loop < ( ROWS - 2 ) * ( COLS - 2 ); ++loop ) {
      x = 1 + rand() % ( ROWS - 2 );    // add dots to maze
      y = 1 + rand() % ( COLS - 2 );
      maze[ x ][ y ] = '.';
   }
}



*/