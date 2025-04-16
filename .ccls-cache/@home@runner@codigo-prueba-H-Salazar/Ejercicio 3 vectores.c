#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 20
#define MIN 10
#define TAM 50

void CargarVector(int []);
void MostrarMayor (int []);

int main(void) {
  int vect[TAM];
  CargarVector(vect);
  MostrarMayor(vect);
  return 0;
}

void CargarVector (int vector[]){
  srand(time(NULL));
  for(int i=0; i<TAM; i++){
    vector[i]=rand()%(MAX-MIN+1)+MIN;
  }
}

void MostrarMayor (int vector[]){
  int mayor=vector[0];
  int cont=0;
  for(int i=1; i<TAM; i++){
    if (vector[i]>mayor){
      mayor=vector[i];
    }
  }
  for(int i=0; i<TAM; i++){
    if(vector[i]==mayor) cont++;
  }
  printf("El mayor es %d y se repite %d veces", mayor, cont);
}