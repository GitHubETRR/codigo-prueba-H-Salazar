#include <stdio.h>

int main(void) {
  int Primero, Segundo, i, Impar, Par;
  char Opcion;
  printf("Ingresa el primer número (menor): ");
  scanf("%d", &Primero);
  printf("Ingresa el segundo número (mayor): ");
  scanf("%d", &Segundo);
  if (Primero<Segundo){
    while (getchar() != '\n');
    printf("¿Qué números deseas ver? (I) Impares, (P) Pares: ");
    scanf("%c", &Opcion);
    if (Opcion=='I'||Opcion=='i'){
      printf("Los numeros impares entre %d hasta %d\n", Primero, Segundo);
      for(i=Primero;i<=Segundo&&i>=Primero;i++){
        if (i%2!=0) printf("%d\n",i);
      } 
    }
    else if (Opcion=='P'||Opcion=='p'){
      printf("Los numeros pares entre %d hasta %d\n", Primero, Segundo);
      for(i=Primero;i<=Segundo&&i>=Primero;i++){
        if (i%2==0) printf("%d\n", i);
      }
    }
  }
  else printf("El primer numero tiene que ser menor al segundo");
  return 0;
}