#include <stdio.h>
#include <math.h>
const int PI = 3.141592653589793;

int main(void) {
  double modu, ang;
  double rad, ParteA, ParteB;
  printf("Inserte modulo:");
  scanf("%lf", &modu);
  printf("Inserte angulo:");
  scanf("%lf", &ang);
  rad = ang * (PI / 180.0);
  ParteA = modu * cos(rad);
  ParteB = modu * sin(rad);
  printf("La forma binomica es: %f + %f i", ParteA, ParteB);
  return 0;
}