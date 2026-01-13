#include <stdio.h>

int main(void) {
  char Car1, Car2, Car3, temp;
  printf("Caracter 1:\n");
  scanf(" %c",&Car1);
  printf("Caracter 2:\n");
  scanf(" %c", &Car2);
  printf("Caracter 3:\n");
  scanf(" %c", &Car3);
  if (Car1 > Car2) {
    temp = Car1;
    Car1 = Car2;
    Car2 = temp;
  }
  if (Car1 > Car3) {
    temp = Car1;
    Car1 = Car3;
    Car3 = temp;
  }
  if (Car2 > Car3) {
    temp = Car2;
    Car2 = Car3;
    Car3 = temp;
  }
  printf("Caracteres ordenados: %c %c %c\n", Car1, Car2, Car3);
  return 0;
}