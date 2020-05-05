

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
///int	*i = (b +((10*x) + y));

//count = (b[i-1]) + b[i+1] + b[i-10] + b[i + 10] + b[i - 11] + b[i - 9] + b[i + 11] + b[i + 9];
	if(*(b + (10*x + y - 1)) == '1'){
		count++;
	}
	if(*(b + (10*x + y + 1)) == '1'){
		count++;
	}
	if(*(b + (10*x + y - 9)) == '1'){
		count++;
	}
	if(*(b + (10*x + y + 9)) == '1'){
		count++;
	}
	if(*(b + (10*x + y - 10)) == '1'){
		count++;
	}
	if(*(b + (10*x + y + 10)) == '1'){
		count++;
	}
	if(*(b + (10*x + y - 11)) == '1'){
		count++;
	}
	if(*(b + (10*x + y + 11)) == '1'){
		count++;
	}
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


  int z;
   z = count_alive_neighbors(b, 0, 4);
   /*printf("tuy%c\n", *(b));
   int a;
   scanf("%d", &a);
	 if(*(b + 1) == '1'){
	 	printf("anan");
	 }
	 else{
		 printf("mal");

	 }*/
	 int a;
	 printf("%d", z);
	 scanf("%d", &a);
	return EXIT_SUCCESS;
}
