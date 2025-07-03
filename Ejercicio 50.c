#include <stdio.h>

int main(void) {
  int Numero, i;
  printf("Ingrese numero entero positivo: \n");
  scanf("%d",&Numero);
  if (Numero>0){
    printf("Los divisores de %d son: \n",Numero);
    for(i=1;i<=Numero;i++) {
      if (Numero%i==0){
        printf("%d\n",i);
      }
    }
  }
  else printf("Numero no valido");
  return 0;
}