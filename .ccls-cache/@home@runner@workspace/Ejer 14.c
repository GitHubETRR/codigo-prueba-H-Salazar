#include <stdio.h>

int main(void) {
  int Ang1, Ang2, AngRes;
  printf("Angulo 1:\n");
  scanf("%d", &Ang1);
  printf("Angulo 2:\n");
  scanf("%d", &Ang2);
  AngRes=180-(Ang1+Ang2);
  printf("El angulo restante del triangulo es de: %d", AngRes);
  return 0;
}