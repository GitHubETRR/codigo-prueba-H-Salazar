#include <stdio.h>

int main(void) {
  double PNumero, SNumero, Suma, Resta, Multiplicacion, Division, Promedio, DoblePMenosMitadS;
  printf("Primer Numero: \n");
  scanf("%lf",&PNumero);
  printf("Segundo Numero \n");
  scanf("%lf",&SNumero);
  Suma = PNumero + SNumero;
  Resta = PNumero - SNumero;
  Multiplicacion = PNumero * SNumero;
  Division = PNumero / SNumero;
  Promedio = Suma / 2;
  DoblePMenosMitadS = (PNumero * PNumero) - (SNumero / 2);
  printf("Suma: %lf \n", Suma);
  printf("Resta: %lf \n", Resta);
  printf( "Multiplicacion: %lf \n", Multiplicacion);
  printf("Division: %lf \n", Division);
  printf("Promedio: %lf\n", Promedio);
  printf("Doble del primer numero menos la mitad del segundo: %lf", DoblePMenosMitadS);
  return 0;
}