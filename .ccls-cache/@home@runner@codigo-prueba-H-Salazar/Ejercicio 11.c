#include <stdio.h>

int main(void) {
  double Cen, Pies, Pulgadas;
  int Ans;
  Ans=1;
  do{
    printf("\nCentimetros: ");
    scanf("%lf", &Cen);
    Pies = Cen / 30.48;
    Pulgadas = Cen / 2.54;
    printf("La medida en Pies equivale a: %.0lf \n", Pies);
    printf("La medida en Pulgadas sin redondeo equivale a: %lf \n", Pies);
    printf("La medida en Pulgadas equivale a: %lf \n", Pulgadas);
    printf("¿Desea continuar? 1 para SI\n");
    scanf("%d", &Ans);
  }
  while (Ans==1);
  return 0;
}