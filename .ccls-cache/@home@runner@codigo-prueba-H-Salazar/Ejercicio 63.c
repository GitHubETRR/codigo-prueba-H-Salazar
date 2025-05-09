#include <stdio.h>

void Multiplo (int, int);
int AreaRectangulo (int, int);

int main(void) {
  int Num1, Num2;
  printf("Ingrese un numero: ");
  scanf("%d", &Num1);
  printf("Ingrese otro numero: ");
  scanf("%d", &Num2);
  printf("¿El primer numero es multiplo del segundo?\n");
  Multiplo (Num1,Num2);
  printf("\nEl area del rectangulo con los numeros iniciales es: %d", AreaRectangulo(Num1, Num2));
  return 0;
}

void Multiplo (int a, int b){
  if (a%b==0) printf("Verdadero\n");
  else printf ("Falso\n");
}

int AreaRectangulo (int bas, int alt){
  return bas * alt;
}