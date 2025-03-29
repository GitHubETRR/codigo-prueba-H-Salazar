#include <stdio.h>
#define MAX 5
int SumaVector(int []);
double PromedioVector(double);
void CargarVector(int []);

int main() {
  int vector[MAX] = {0};
  CargarVector(vector);
  int Suma=SumaVector(vector);
  double Pro=PromedioVector(Suma);
  printf("La suma de los numeros del vector es: %d\n", Suma);
  printf("El promedio de los numero del vector es: %.2f", Pro);
  return 0;
}

void CargarVector(int vector[]){
  for (int i=0; i<MAX; i++){
    printf("\nIngrese un numero %d de %d: ", i+1,MAX);
    scanf("%d", &vector[i]);
  }
}

int SumaVector(int vector[]) {
  int Suma=0;
  for (int i=0;i<MAX;i++) Suma+=vector[i];
  return Suma;
}

double PromedioVector(double Suma){
  double Promedio=Suma/MAX;
  return Promedio;
}