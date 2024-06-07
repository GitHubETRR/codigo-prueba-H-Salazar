#include <stdio.h>

int main(void) {
  int Area;
  double Perimetro;
  printf("Superficie de cuadrado en m2\n");
  scanf("%d", &Area);
  Perimetro=4*sqrt(Area);
  printf("El perimetro del cuadrado es: %.2f", Perimetro);
  return 0;
}