#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"
int main(){
char *b = NULL;
b = checkersboard();
readboard(b);
printf("\n WELCOME TO TURKISH CHECKKERS\n\n\n");
printf("WHITE --> @\nBLACK --> O\n\n\n");
//game_engine(b, 1);
print_board(b);
printf("\n\n");
int z = isvalidmove(b, 0, 0, 2, 0, 3);
printf("%d\n\n", z);
movement(b, 0, 0, 2, 0, 3);
print_board(b);
printf("\n\n");
z = isvalidmove(b, 0, 0, 3, 1, 3);
printf("%d", z);
int a;
scanf("%d", &a);
  return 0;
}
