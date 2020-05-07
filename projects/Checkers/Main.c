#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"


int main(){
char *b = NULL;
//char *lap = NULL;
b = checkersboard();
readboard(b);
print_board(b);
int x = 0;
int y = 2;
int x1 = 0;
int y1 = 3;
int z;
z = isvalidmove(b, 1, x, y, x1, y1);
printf("%d\n", z);

move(b, x, y, x1, y1);
//destroy_board(b);
printf("\n\n");
print_board(b);
destroy_board(b);

int a;

scanf("%d", &a);


  return 0;
}
