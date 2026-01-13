#include <stdio.h>

int main(void) {
  int Fecha, Dia, Mes, Year;
  printf("Ingrese fecha en DDMMAAAA\n");
  scanf("%d", &Fecha);
  Dia = Fecha / 1000000;
  Mes = (Fecha / 10000) % 100;
  Year = Fecha % 10000;
  printf("Dia: %d\nMes: %d\nYear: %d\n", Dia, Mes, Year);
  return 0;
}