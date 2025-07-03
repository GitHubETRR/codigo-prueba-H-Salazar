#include <stdio.h>

int main(void) {
  int Y, X, Jugada, Jugador, Blanco=0, Cuadrante1=0, Cuadrante2=0, Cuadrante3=0, Cuadrante4=0;
  for(Jugada=1;Jugada<=1;Jugada++){
    for (Jugador=1;Jugador<=5;Jugador++){
      printf("Jugador %d ingrese coordenadas(x,y): \n", Jugador);
      scanf("%d %d",&X,&Y);
      if (X==0 && X==0 && Y==0 && Y==0) Blanco++;
      else if (X>0 && Y>0) Cuadrante1++;
      else if (X>0 && Y<0) Cuadrante4++;
      else if (X<0 && Y>0) Cuadrante2++;
      else if (X<0 && Y<0) Cuadrante3++;
    }
    printf("Se tiro al Blanco %d veces\n", Blanco);
    printf("Se tiro al Cuadrante1 %d veces\n", Cuadrante1);
    printf("Se tiro al Cuadrante2 %d veces\n", Cuadrante2);
    printf("Se tiro al Cuadrante3 %d veces\n", Cuadrante3);
    printf("Se tiro al Cuadrante4 %d veces\n", Cuadrante4);
  }
  return 0;
}