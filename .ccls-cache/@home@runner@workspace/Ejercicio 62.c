#include <stdio.h>

void EsPrimo (int);

int main(void) {
  int Numero;
  printf("Ingrese un numero: ");
  scanf("%d", &Numero);
  EsPrimo(Numero);
  return 0;
}

void EsPrimo (int Num){
  if (Num <= 1) {
    printf("El numero %d NO es primo\n", Num);
    return; // Salir de la funcion sin imprimir lo que esta en el final
  }
  for (int i=2; i <= Num/2; i++) {
    if (Num % i == 0) {
      printf("El numero %d NO es primo\n", Num);
      return
    }
  }
  printf("El numero %d es primo\n", Num);
}
