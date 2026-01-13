#include <stdio.h>

int main(void) {
  char Letra;
  printf("Ingrese caracter: ");
  scanf("%c",&Letra);
  if(Letra == 'a' || Letra == 'e' || Letra == 'i' || Letra == 'o' || Letra == 'u'|| Letra == 'A' || Letra == 'E' || Letra == 'I' || Letra == 'O' || Letra == 'U') printf("La letra %c es una vocal", Letra);
  else printf("La letra %c no es una vocal", Letra);
  return 0;
}