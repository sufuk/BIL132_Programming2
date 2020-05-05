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
int count_alive_neighbors(char *b, int x, int y)
{
	int count = 0;

	/* do stuff with b, x and y */

	return count;
}

char* evaluate(char *b)
{
	char *n = create_board();

	/* do stuff with b and n */

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
