#include <stdio.h>

int main(void) {
  int Numero,i, Resultado=1;
  printf("Numero entero, mayor o igual a 0: \n");
  scanf("%d", &Numero);
  if (Numero>0){
    for(i=1;i<=Numero;i++) Resultado*=i;
    printf("El factorial de %d es %d\n", Numero, Resultado);
  }
  else if (Numero==0) printf("La factorial de 0 es 1");
  else printf("Numero no valido");
  return 0;
}