#include <stdio.h>

int main(void) {
  int Numero, i;
  printf("Ingrese numero para la tabla\n");
  scanf("%d",&Numero);
  if (Numero<=10){
    for (i=0; i<=10 ; i++) printf("%d x %d = %d\n",Numero,i,Numero*i);
  }
  else printf("El numero no es valido");
  return 0;
}