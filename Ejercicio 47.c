#include <stdio.h>

int main(void) {
  int Numeros;
  double Promedio=0, Suma=0, Cantidad=0;
  printf("Ingrese numeros: \n");
  scanf("%d", &Numeros);
  while(Numeros>=0){
    Suma+=Numeros;
    Cantidad++;
    scanf("%d", &Numeros);
  }
  if (Cantidad==0) printf("No se ingresaron numeros positivos");
  else {
    Promedio=Suma/Cantidad;
    printf("El promedio es: %.3f", Promedio);
  }
  return 0;
}