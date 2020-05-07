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
void movement(char *b, int x0, int y0, int x1, int y1){
  int index2 = (8*y0) + x0;
  int index3 = (8*y1) + x1;
  if(*(b+index2) == WHITE){
    *(b + index3) = WHITE;
    *(b + index2) = WHITEWOOD;
  }
}

void destroy_board(char *b)
{
	free(b);
}
