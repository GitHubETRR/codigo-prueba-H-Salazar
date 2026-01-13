#include <stdio.h>

int main(void) {
  int Numero, Positivos=0, Negativos=0, Contador=0;
  printf("Ingrese numeros: \n");
  scanf("%d", &Numero);
  while (Numero != 0){
    if(Numero>0){
      Positivos++;
    }
    else Negativos++;
    Contador++;
    scanf("%d", &Numero);
  }
  if(Contador==0) printf("No se ingresaron numeros validos");
  else printf("La cantidad de numeros positivos es: %d y la de negativos es de %d", Positivos, Negativos);
  return 0;
}