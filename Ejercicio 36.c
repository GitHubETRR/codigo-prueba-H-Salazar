#include <stdio.h>

int main(void) {
  int Kilos, Adicional=0, Total, Costo;
  char Env;
  const int Exc = 800;

  printf("Envio de Corta (C) o Larga (L) distancia: ");
  scanf(" %c", &Env);
  printf("Cantidad de kilos: ");
  scanf("%d", &Kilos);
  if (Env == 'C' || Env == 'c') {
    Costo = 1500;
    if (Kilos > 20) {
      Adicional = (Kilos - 20) * Exc;
    }
  } 
  else if (Env=='L'|| Env='l'){
    Costo = 2000;
    if (Kilos > 20) {
      Adicional = ((Kilos - 20 + 4) / 5) * Exc;
    }
  }
  Total = Costo + Adicional;
  printf("Costo total: $%d\n", Total);
  return 0;
  }
