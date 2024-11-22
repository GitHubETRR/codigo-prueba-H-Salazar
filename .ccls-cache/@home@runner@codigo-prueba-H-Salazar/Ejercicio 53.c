#include <stdio.h>

int main(void) {
  int Pares, i;
  printf("Los numeros pares entre 1 a 50 son: \n");
  for(i=1; i<=50; i++){
    if(i%2==0) printf("%d\n", i);
  }
  return 0;
}