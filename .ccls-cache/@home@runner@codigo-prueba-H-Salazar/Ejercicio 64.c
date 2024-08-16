#include <stdio.h>

int EsPrimo (int);
int Siguiente (int);

int main(void) {
  int Numero;
  printf("Ingrese un numero primo:\n");
  scanf("%d",&Numero);
  int SiguientePrimo = Siguiente(Numero);
  printf("El siguiente número primo después de %d es %d\n", Numero, SiguientePrimo);
  return 0;
}

int EsPrimo (int Num){
  if (Num<=1) return 0;
  for (int i=2; i<=Num/2; i++) if (Num%i==0) return 0;
  return 1;
}

int Siguiente (int Num){
  int Siguiente=Num+1;
  while (!EsPrimo(Siguiente)) {
    Siguiente++;
  }
  return Siguiente;
}