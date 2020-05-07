#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"
int main(){
char *b = NULL;
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
printf("\n\n");
print_board(b);
movement(b, 1, 0, 3, 0, 4);
printf("\n\n");
print_board(b);
int t = caneat(b, 2);
printf("%d", t);
eat(b, 2, 0, 5, 0, 4, 0, 3);
printf("\n\n");
print_board(b);
printf("\n\n");
movement(b, 1, 1, 2, 1, 3);
print_board(b);
printf("\n\n");
eat(b, 2, 0, 3, 1, 3, 2, 3);
print_board(b);
printf("\n\n");
destroy_board(b);
int a;
scanf("%d", &a);
  return 0;
}
