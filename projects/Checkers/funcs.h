#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define ROWS 8
#define COLUMNS 8
#define BLACK  'B'
#define WHITE 'W'
#define WOOD '_'
#define INITIAL_FILE	"board.txt"



void checkersboard(char *b){

  b = malloc(ROWS * COLUMNS);
  memset(b, WOOD, ROWS*COLUMNS);
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
				printf("| B ");
      }
      if(b[index] == WHITE){
        printf("| W");
      }
		  if(b[index] == WOOD){
        printf("|  ");
      }
    }
		printf("|\n");
	}
}
