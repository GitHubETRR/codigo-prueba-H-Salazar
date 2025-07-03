#include <stdio.h>

int EsBisiesto (int);

int main(void) {
  int Year, Res;
  printf("Ingrese un año: \n");
  scanf("%d",&Year);
  Res = EsBisiesto (Year);
  if (Res) printf("El año %d es bisiesto? VERDADERO \n",Year);
  else printf("El año %d es bisiesto? FALSO \n",Year);
  return 0;
}

int EsBisiesto (int Year){
  if (Year%4==0 && Year%100!=0 || Year%400==0)
    return 1;
  else return 0;
}