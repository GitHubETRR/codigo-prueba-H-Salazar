#include <stdio.h>
#include <math.h>

int Potencia(int, int);

int main(void) {
  int base=2, exp=2;
  printf("%d^%d = ",base, exp);
  int Resultado = Potencia(base,exp);
  printf("%d", Resultado);
  return 0;
}

int Potencia(int Entero, int Potencia){
  int Res=1, i;
  for(i=0; i<=Potencia; i++) Res=pow(Entero, i);
  return Res;
}