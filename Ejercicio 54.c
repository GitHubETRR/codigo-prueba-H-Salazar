#include <stdio.h>

int main(void) {
  int PrimerNumero, SegundoNumero, i;
  printf("Ingrese el primer numero (menor): \n");
  scanf("%d",&PrimerNumero);
  printf("Ingrese el segundo numero (mayor): \n");
  scanf("%d",&SegundoNumero);
  if (PrimerNumero<SegundoNumero){
    printf("Los numeros enteros desde %d hasta %d son: \n", PrimerNumero, SegundoNumero);
    for(i=PrimerNumero; i<=SegundoNumero && i>=PrimerNumero; i++){
      printf("%d\n", i);
    }
  }
  else printf("Numeros incorrecto");
  return 0;
}