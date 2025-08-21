#include <stdio.h>

int main(void) {
  int quiniela[10]={0};
  int posicion, numero, i, j;
  for (i=0;i<10;i++){
    printf("\n\nIngrese posición del numero a ingresar:\n");
    scanf("%d", &posicion);
    if (posicion<1 || posicion>10){
      printf("Posición incorrecta debe ser de 1 a 10\n");
      i--;
      continue;
    }
    printf("Ingrese el numero:\n");
    scanf("%d", &numero);
    quiniela[posicion-1]=numero;
    printf("Números en la Quiniela:\n");
    for (j=0; j<10; j++) printf("%d ", quiniela[j]);
  }
  return 0;
}