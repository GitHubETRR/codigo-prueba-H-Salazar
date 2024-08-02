#include <stdio.h>

void Menu(int);
int Op;

int main(void) {
  printf("Eliga entre las opciones 1 al 4 para ejecutar el programa: ");
  scanf("%d", &Op);
  Menu(Op);
  return 0;
}

void Menu (int Op) {
  switch (Op){
    case 1: printf("Opcion 1");
    break;
    case 2: printf("Opcion 2");
    break;
    case 3: printf("Opcion 3");
    break;
    case 4: printf("Opcion 4");
    break;
    default: printf("Opcion no valida\n");
  }
}