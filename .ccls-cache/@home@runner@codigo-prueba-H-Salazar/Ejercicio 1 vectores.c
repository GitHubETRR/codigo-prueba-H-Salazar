#include <stdio.h>
#define MAX 5
int SumaVector(int []);

int main() {
  int vector[MAX] = {1, 2, 3, 4, 5};
  int Suma=SumaVector(vector);
  printf("La suma de los numeros del vector es: %d\n", Suma);
  return 0;
}

int SumaVector(int vector[]) {
  int Suma=0;
  for (int i=0;i<MAX;i++) Suma+=vector[i];
  return Suma;
}