/*
	Student name :
	Student ID   :
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

int main()
{
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
