#include <stdio.h>
#include <math.h>

int main(void) {
  int i, Potencia;
  printf("Primeras 20 potencias de 2:\n");
  for(i=0; i<=20; i++) {
    Potencia=pow(2,i);
    printf("%d\n", Potencia);
  }
  return 0;
}