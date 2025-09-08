#include <stdio.h>
#include <math.h>

int main(void) {
  int ParteA, ParteB, ParteC, Paso1;
  double Raiz1, Raiz2, ParteR, ParteI, Parte;
  printf("Partes del polinomio\n");
  printf("Inserte A: ");
  scanf("%d", &ParteA);
  printf("Inserte B: ");
  scanf("%d", &ParteB);
  printf("Inserte C: ");
  scanf("%d", &ParteC);
  Paso1=ParteB*ParteB-4*ParteA*ParteC;
  if (Paso1>=0){
    Raiz1= ((-ParteB)+sqrt(Paso1))/(2*ParteA);
    Raiz2= ((-ParteB)-sqrt(Paso1))/(2*ParteA);
    printf("Las raices del polinomio son: %lf y %lf", Raiz1,Raiz2);
  }
  else {
    Parte =2*ParteA;
    ParteR = -ParteB/Parte;
    ParteI=sqrt(-Paso1)/Parte;
    printf("Las raices son imaginarias");
    printf("Raiz 1: %lf + %lfi\n", ParteR, ParteI);
    printf("Raiz 2: %lf - %lfi", ParteR, ParteI);
  }
  return 0;
}