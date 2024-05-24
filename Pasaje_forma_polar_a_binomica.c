#include <math.h>
#include <stdio.h>
const int PI = 3.14;

int main(void) {
  int modu, ang, rad, ParteA, ParteB;
  printf("Inserte modulo:");
  scanf("%d", &modu);
  printf("Inserte angulo:");
  scanf("%d", &ang);
  rad = ang * PI / 180;
  ParteA = modu * cos(rad);
  ParteB = modu * sin(rad);
  printf("La forma binomica es: %d + %d i", ParteA, ParteB);
  return 0;
}