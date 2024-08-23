#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 90
#define MIN 20
#define TAM 20

void CargarVector(int []);
void InvertirVector(int [], int []);
void MostrarVector(int [], int []);

int main(void) {
  int vector[TAM];
  int invector[TAM];
  CargarVector(vector);
  InvertirVector(invector,vector);
  MostrarVector(vector,invector);
  return 0;
}

void CargarVector (int vector[]){
  srand(time(NULL));
  for(int i=0; i<TAM; i++){
    vector[i]=rand()%(MAX-MIN+1)+MIN;
  }
}

void InvertirVector(int invector[], int vector[]){
  for(int i=0; i<TAM; i++){
    invector[i]=vector[TAM-1-i];
  }
}

void MostrarVector(int vector[], int invector[]){
  printf("El vector original es: \n");
  for (int i=0; i<TAM; i++){
    printf("%d ", vector[i]);
  }
  printf("\nEl vector invertido es: \n");
  for (int i=0; i<TAM; i++){
    printf("%d ", invector[i]);
  }
}