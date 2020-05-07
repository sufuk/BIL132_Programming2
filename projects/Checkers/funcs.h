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
  if(turn == 1){
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
  if(turn == 2){
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
  if(turn == 1){
    *(b + index3) = WHITE;
    *(b + index2) = WHITEWOOD;
  }
  if(turn == 2){
    *(b + index3) = BLACK;
    *(b + index2) = WHITEWOOD;
  }
}
int caneat(char *b, int turn){
  int n = 0;
  if(turn == 1){
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
  if(turn == 2){
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
void eat(char *b, int turn, int x4, int y4, int x5, int y5, int x6, int y6){
  int index4 = y4*8 + x4;
  int index5 = y5*8 + x5;
  int index6 = y6*8 + x6;
  if(turn == 1){
    //whıte turn
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = WHITE;
  }
  if(turn == 2){
    //black turn
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = BLACK;
  }
}
