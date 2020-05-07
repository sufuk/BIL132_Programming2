#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"


int main(){
char *b = NULL;

checkersboard(b);
readboard(b);
print_board(b);
int x = 0;
int y = 5;
int x1 = 0;
int y1 = 4;
int z;
z = isvalidmove(b, 1, x, y, x1, y1);
printf("%d", z);
int a;
scanf("%d", &a);


  return 0;
}
