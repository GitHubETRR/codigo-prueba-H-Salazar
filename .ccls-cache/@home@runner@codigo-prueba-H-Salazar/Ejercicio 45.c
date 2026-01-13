#include <stdio.h>

int main() {
  int Numero, i;
  for (i = 0; i < 10; i++) {
    printf("Ingrese un número entero: ");
    scanf("%d", &Numero);
    if (Numero > 0) {
      printf("El número %d es positivo.\n", Numero);
    }
  }
    return 0;
}