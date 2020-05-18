#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"
int main(){
char *b = NULL;
b = checkersboard();
readboard(b);
printf("\n WELCOME TO TURKISH CHECKKERS\n\n\n");
printf("WHITE --> O\nBLACK --> @\n\n\n");
game_engine(b, 0);
int a;
scanf("%d", &a);
  return 0;
}
