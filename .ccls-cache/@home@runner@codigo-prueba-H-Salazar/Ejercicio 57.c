#include <stdio.h>

//void MayorDeDos (int Num1, int Num2);
int GetMayorDeDos (int,int);

int main(void) {
  //MayorDeDos(45,2);
  int Numero = GetMayorDeDos(1,2);
  printf("El numero mayor es %d", Numero);
  return 0;
}

/*void MayorDeDos (int Num1, int Num2){
  printf("El primer numero es %d y el segundo es %d\n", Num1, Num2);
  if (Num1 > Num2) printf("El numero mayor es: %d", Num1);
  else printf("El numero mayor es: %d", Num2);
}*/

int GetMayorDeDos (int Num1, int Num2){
  printf("El primer numero es %d y el segundo es %d\n", Num1, Num2);
  if (Num1>Num2) return Num1;
  else return Num2;
}
//Las partes que estan en comentarios son los que forman en la primera parte