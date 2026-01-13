#include <stdio.h>

int main(void) {
  int Se, Ho, Min, TSe;
  printf("Inserte cantidad de segundos menor a 86400\n");
  scanf("%d", &Se);
  if (Se<=86400){
    Ho = Se / 3600;
    TSe = Se % 3600;
    Min = TSe / 60;
    Se = TSe % 60;
    printf("Horas: %d\nMinutos: %d\nSegundos: %d", Ho, Min, Se);
  }
  else printf("Error");
  return 0;
}