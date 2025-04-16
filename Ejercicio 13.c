#include <stdio.h>

int main(void) {
  int Cantidad, Masa, Total;
  const int Precio = 25;
  printf("Ingrese cantidad en Kg:\n");
  scanf("%d", &Cantidad);
  Total=Cantidad*Precio;
  printf("Total a pagar: %d\n", Total);
  return 0;
}