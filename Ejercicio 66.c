#include <stdio.h>

void FechaValida (int, int, int);

int main(void) {
  int Dia, Mes, Year;
  printf("Ingrese una fecha: ");
  scanf("%d", &Dia);
  scanf("%d", &Mes);
  scanf("%d", &Year);
  FechaValida (Dia, Mes, Year);
  return 0;
}


void FechaValida (int Day, int Month, int Year){
  int Bisiesto=0;
  if ((Year%4==0 && Year%100!=0) || (Year%400==0)) Bisiesto=1;
  if (Year>0 && Year<2025){
    if (Month>0 && Month<13){
      switch (Month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          if (Day>0 && Day<32) {
            printf("La fecha %d/%d/%d es valida", Day, Month, Year);
          return;
      }
        break;
        case 4: case 6: case 9: case 11:
          if (Day>0 && Day<31) {
            printf("La fecha %d/%d/%d es valida");
            return;
          }
        break;
        case 2:
          if ((Bisiesto && Day>0 && Day<30) || (!Bisiesto && Day>0 && Day<29)) {
            printf("La fecha %d/%d/%d es valida", Day, Month, Year);
            return;
          }
        break;
      }
    }
  }
  printf("La fecha %d/%d/%d es no valida", Day, Month, Year);
}