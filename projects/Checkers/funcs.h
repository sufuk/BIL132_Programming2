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


void move(b){
  int x, y;
  if(turn == 0){
    printf("player 0 please move\n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);
  }




}
