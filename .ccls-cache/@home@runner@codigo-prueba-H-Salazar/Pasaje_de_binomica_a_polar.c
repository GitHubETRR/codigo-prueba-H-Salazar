#include <stdio.h>
#include <math.h>
const int PI=3.141592653589793;

int main(void) {
  double ParteA, ParteB, ParteAB, Modulo, Rad, Ang; 
  printf("Inserte a de la forma binomica:");
  scanf("%lf", &ParteA);
  printf("Inserte b de la forma binomica:");
  scanf("%lf", &ParteB);
  Modulo = sqrt(ParteA*ParteA + ParteB*ParteB);
  ParteAB = ParteB/ParteA;
  Rad = atan(ParteAB);
  Ang = (Rad*180)/PI;
  if (ParteA>0){
    if (ParteB<0) Ang+=360;
  }
  else Ang+=180;
  printf("El modulo es: %lf\n", Modulo);
  printf("El angulo es: %lf\n", Ang);
  return 0;
}