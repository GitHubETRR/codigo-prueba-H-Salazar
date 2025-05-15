#include <stdio.h>

int main(void) {
  int Numero, Suma=0;
  printf("Ingrese un numero entero positivo: \n");
  scanf("%d",&Numero);
  while(Numero>0){
    Suma+=(Numero%10);
    Numero/=10;
  }
  printf("La suma total de su numero es de: %d", Suma);
  return 0;
}