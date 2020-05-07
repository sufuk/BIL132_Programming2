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

movement(b, 1, x, y, x1, y1);
//destroy_board(b);
printf("\n\n");
print_board(b);
movement(b, 1, 0, 3, 0, 4);
printf("\n\n");
print_board(b);
int t = caneat(b, 2);
printf("%d", t);
destroy_board(b);
int a;
scanf("%d", &a);
  return 0;
}
