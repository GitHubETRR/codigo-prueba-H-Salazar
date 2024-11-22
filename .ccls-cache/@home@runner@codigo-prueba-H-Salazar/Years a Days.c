#include <stdio.h>

int main(void) {
  int Years, Days;
  printf("Ingrese años\n");
  scanf("%d",&Years);
  Days = Years * 365;
  printf("Usted a vivido %d", Days);
  return 0;
}