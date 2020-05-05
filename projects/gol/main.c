/*
	Student name :
	Student ID   :
*/

/*
C   N                 new C
   1   0,1             ->  0  # Lonely
   1   4,5,6,7,8       ->  0  # Overcrowded
   1   2,3             ->  1  # Lives
   0   3               ->  1  # It takes three to give birth!
   0   0,1,2,4,5,6,7,8 ->  0  # Barren
	 */
#include <stdlib.h>
#include <stdio.h>
#include "gol.h"
#include "gol.c"
int count_alive_neighbors(char *b, int x, int y){
	FILE *f = fopen(INITIAL_FILE, "r");
	int count = 0;
/* do stuff with b, x and y */
if(*(b + (10*y + x - 1)) == '1'){
	count++;
}
if(*(b + (10*y + x + 1)) == '1'){
	count++;
}
if(*(b + (10*y + x - 9)) == '1'){
	count++;
}
if(*(b + (10*y + x + 9)) == '1'){
	count++;
}
if(*(b + (10*y + x - 10)) == '1'){
	count++;
}
if(*(b + (10*y + x + 10)) == '1'){
	count++;
}
if(*(b + (10*y + x - 11)) == '1'){
	count++;
}
if(*(b + (10*y + x + 11)) == '1'){
	count++;
}

	return count;
}

char* evaluate(char *b){
	char *n = create_board();
	/* do stuff with b and n */
	int i, j;
	int z;
	int index;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			index = ((i*M) + j);
			if (*(b + index) == '0'){
				z = count_alive_neighbors(b, j, i);
				if(z == 3){
					//GIVE BIRTH !!
					*(n + index) = '1';
					}
				else{
					//STILL DEAD
					*(n + index) = '0';
				}
				}
			else if(*(b + index) == '1'){
				z = count_alive_neighbors(b, j, i);
				if((z == 2) || (z == 3)){
					//LIVES
						*(n + index) = '1';
				}
				else{
					//DIE
					*(n + index) = '0';
				}
			}
				}
			}
	return n;
}

int main(){
	int i = 0;
	char *b = NULL;
	char *next_generation = NULL;

	b = create_board();
	read_initial(b);

	printf("Welcome to game of life, please type 'q' to quit\n\n");

	do
	{
		printf("Generation %d\n", ++i);

		print_board(b);
		next_generation = evaluate(b);
		destroy_board(b);
		b = next_generation;

		printf("\n\n");

	}while(getchar() != 'q');
	destroy_board(b);

	return EXIT_SUCCESS;
}
