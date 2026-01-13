#include <stdio.h>
#define TAM 3
#define MAX 5
#define MIN 1


int main(void) {
  int vectorA[TAM]={1,2,3}, vectorB[TAM]={4,5,6};
  int Resul=0;
  for (int i=0;i<TAM;i++){
    Resul+=vectorA[i]*vectorB[i];
  }
  printf("El resultado es: %d",Resul);
  return 0;
}