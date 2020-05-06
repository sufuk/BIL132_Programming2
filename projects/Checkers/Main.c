#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"


int main(){
char *b;

checkersboard(b);
readboard(b);
print_board(b);
int x = 0;
int y = 6;
int x1 = 0;
int y1 = 5;
int z;
z = isvalidmove(b, x, y, x1, y1);
printf("%d", z);
int a;
scanf("%d", &a);


  return 0;
}
