#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 8
#define COLUMNS 8
#define BLACK  'B'
#define WHITE 'W'
#define WHITEWOOD '_'
//#define DARKWOOD  '#'
#define INITIAL_FILE	"board.txt"
char* checkersboard(){
  char *p = malloc(ROWS * COLUMNS);
  memset(p, WHITEWOOD, ROWS * COLUMNS);
  return p;
}
void readboard(char *b){
  int i;
  FILE *f = fopen(INITIAL_FILE, "r");
  if(f == NULL){
    printf("Can not open file %s\n", INITIAL_FILE);
    exit(EXIT_FAILURE);
  }
  for(i=0 ; i < ROWS * COLUMNS ; i++){
    *(b + i) = fgetc(f);
  }
fclose(f);
}
void print_board(char *b){
	int i,j;
	int index = 0;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLUMNS;j++){
			index = i*COLUMNS + j;
			if(b[index] == BLACK){
				printf("|_@_");
      }
      if(b[index] == WHITE){
        printf("|_O_");
      }
		  if(b[index] == WHITEWOOD){
        printf("|___");
      }
  /*    if(b[index] == DARKWOOD){
        printf("|_#__");
      }*/
    }
		printf("|\n");
	}
}
void destroy_board(char *b){
	free(b);
}
int isvalidmove(char *b, int turn, int x0, int y0, int x1, int y1){
  //int x0, y0, x1, y1;
  int index0 = (y0 * 8) + x0;
  int n;
  if(turn == 0){
    if(*(b + index0) == 'W'){
      int index1 = y1*8 + x1;
      if(index1 == (index0 + 1)){
      //RIGHT
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      if(index1 == (index0 - 1)){
        //LEFT
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      if(index1 == (index0  + 8)){
        //FOWARD
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      else{
        n = 0;
      }
    }
    else{
      n = 0;
    }
  }
  if(turn == 1){
    if(*(b + index0) == 'B'){
      int index1 = y1*8 + x1;
      if(index1 == (index0 + 1)){
        //RIGHT
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      if(index1 == (index0 - 1)){
        //LEFT
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      if(index1 == (index0 - 8)){
        //FOWARD
        if(*(b + index1) != '_'){
          n = 0;
        }
        if(*(b + index1) == '_'){
          n = 1;
        }
      }
      else{
        n = 0;
      }
    }
    else{
      n = 0;
    }
  }
 return n;
}
void movement(char *b, int turn, int x0, int y0, int x1, int y1){
  int index2 = (8*y0) + x0;
  int index3 = (8*y1) + x1;
  if(turn == 0){
    *(b + index3) = WHITE;
    *(b + index2) = WHITEWOOD;
  }
  if(turn == 1){
    *(b + index3) = BLACK;
    *(b + index2) = WHITEWOOD;
  }
}
int caneat(char *b, int turn){
  int n = 0;
  if(turn == 0){
    //white
    for(int i = 0; i < COLUMNS*ROWS ; i++){
      if(*(b + i) == WHITE){
        if((*(b + i - 1) == BLACK) && (*(b + i - 2) == WHITEWOOD)){
          n++;
        }
        if((*(b + i + 1) == BLACK) && (*(b + i + 2) == WHITEWOOD)){
          n++;
        }
        if((*(b + i + 8) == BLACK) && (*(b + i + 16) == WHITEWOOD)){
          n++;
        }
      }
    }
  }
  if(turn == 1){
    //black
    for(int i = 0; i < COLUMNS*ROWS ; i++){
      if(*(b + i) == BLACK){
        if((*(b + i - 1) == WHITE) && (*(b + i - 2) == WHITEWOOD)){
          n++;
        }
        if((*(b + i + 1) == WHITE) && (*(b + i + 2) == WHITEWOOD)){
          n++;
        }
        if((*(b + i - 8) == WHITE) && (*(b + i - 16) == WHITEWOOD)){
          n++;
        }
      }
    }
  }
  return n;
}
void eating(char *b, int turn, int x4, int y4, int x5, int y5, int x6, int y6){
  int index4 = y4*8 + x4;
  int index5 = y5*8 + x5;
  int index6 = y6*8 + x6;
  if(turn == 0){
    //whıte turn
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = WHITE;
  }
  if(turn == 1){
    //black turn
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = BLACK;
  }
}
/*
int turnchecker(char *b, int startturn){
  int turn = startturn;
  if(caneat(b, turn) != 0){
    turn = startturn;
  }
  else if() {
    turn
  }
  return turn;
}
*/
void move(char *b, int turn){
  printf("\n Please enter which piece you wanna move\n");
  int x0;
  int y0;
  int x1;
  int y1;
  printf("X: ");
  scanf("%d", &x0);
  printf("\nY: ");
  scanf("%d", &y0);
  printf("\nPlease enter where you wanna move\n");
  printf("X: ");
  scanf("%d", &x1);
  printf("\nY: ");
  scanf("%d", &y1);
  int z0 = isvalidmove(b, turn, x0, y0, x1, y1);
  if(z0 == 1){
    movement(b, turn, x0, y0, x1, y1);
  }
}
void eat(char *b, int turn){
  printf("\n Please enter which piece you want to use\n");
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  printf("X: ");
  scanf("%d", &x0);
  printf("\nY: ");
  scanf("%d", &y0);
  printf("\nPlease enter which piece will be eaten\n");
  printf("X: ");
  scanf("%d", &x1);
  printf("\nY: ");
  scanf("%d", &y1);
  printf("\nPlease enter where you will be after eating\n");
  printf("X: ");
  scanf("%d", &x2);
  printf("\nY: ");
  scanf("%d", &y2);
  eating(b, turn, x0, y0, x1, y1, x2, y2);
}
void game_engine(char *b, int turn){
  while(1){
    if(caneat(b, turn) != 0){
      while(caneat(b, turn) != 0){
        if(turn == 0){
          printf("\nWHITES TURN\n");
        }
        else if(turn == 1){
          printf("\nBLACKS TURN\n");
        }
        printf("You can eat %d way \n", caneat(b, turn));
        eat(b, turn);
        if(caneat(b, turn) == 0){
          if(turn == 0){
            turn = 1;
          }
          else if(turn == 1){
            turn = 0;
          }
        }
        print_board(b);
      }
    }
    else if(caneat(b, turn) == 0){
      if(turn == 0){
        printf("\nWHITES TURN\n");
      }
      if(turn == 1){
        printf("\nBLACKS TURN\n");
      }
      move(b, turn);
      print_board(b);
      if(turn == 0){
        turn = 1;
      }
      else if(turn == 1){
        turn = 0;
      }
    }
  }
}
