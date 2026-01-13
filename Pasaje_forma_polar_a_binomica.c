#include <stdio.h>
#include <math.h>
const int PI = 3.141592653589793;

int main(void) {
  double Modu, Ang;
  double Rad, ParteA, ParteB;
  printf("Inserte modulo:");
  scanf("%lf", &Modu);
  printf("Inserte angulo:");
  scanf("%lf", &Ang);
  Rad = Ang * (PI / 180.0);
  ParteA = Modu * cos(Rad);
  ParteB = Modu * sin(Rad);
  printf("La forma binomica es: %f + %f i", ParteA, ParteB);
  return 0;
}