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



void checkersboard(char *b){

  b = malloc(ROWS * COLUMNS);
  memset(b, WHITEWOOD, ROWS*COLUMNS);
}

void readboard(char *b){

  int i;
  FILE *f = fopen(INITIAL_FILE, "r");

  if(f == NULL){
    printf("Can not open file %s\n", INITIAL_FILE);
    exit(EXIT_FAILURE);
  }
  for(i=0 ; i<ROWS * COLUMNS ; i++){
    b[i] = fgetc(f);
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
  if(turn == 0){
    printf("player 0 please chose your pawn\n");
    printf("X: ");
    scanf("%d", &x0);
    printf("\nY: ");
    scanf("%d", &y0);
    int index0 = y0*8 + x0;
    if(*(b + index0) != 'W'){
      printf("ERROR\n");
    }
    if(*(b + index0) == 'W'){
      printf("Where you want to move? \n");
      printf("X: ");
      scanf("%d", &x1);
      printf("\nY: ");
      scanf("%d", &y1);
      int index1 = y1*8 + x1;
      if(index1 == (index0 + 1)){
        //RIGHT
      }
      if(index1 == (index0 - 1)){
        //LEFT
      }
      if(index1 == (index0  + 8)){
        //FOWARD
      }
    }
  }




}
