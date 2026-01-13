#include <stdio.h>
const int PI=3.14;

void Cuadr_Rect(void);
void Circ(void);
void Trap(void);
void Tria(void);
int area=0;

int main(void) {
  int respuesta=6;
  while (respuesta!=0){
    printf("\n************************************\n****** CÁLCULO DE SUPERFICIES ******\n1. Cuadrado (lado*lado) \n2. Círculo (pi*radio*radio)\n3. Rectángulo (base*altura)\n4. Trapecio (base1+base2)*altura/2)\n5. Triángulo (base*altura)/2)\n0. Salir del programa\n************************************\n");
    printf("Ingrese su respuesta ==> ");
    scanf("%d",&respuesta);
    switch(respuesta){
      case 1: Cuadr_Rect();
        break;
      case 2: Circ();
        break;
      case 3: Cuadr_Rect();
        break;
      case 4: Trap();
        break;
      case 5: Tria();
        break;
      case 0: printf("Saliendo del programa...");
        break;
    }
  }
  return 0;
}

void Cuadr_Rect(){
  int lado1, lado2;
  printf("Ingrese los lados de la figura: ");
  scanf("%d""%d", &lado1, &lado2);
  area=lado1*lado2;
  if (lado1==lado2) printf("El area del cuadrado vale: %d\n", area);
  else printf("El area del rectangulo vale: %d\n", area);
}

void Circ(){
  int radio;
  printf("Radio de la circunferencia: ");
  scanf("%d", &radio);
  printf("El area de la circunferencia vale: %d\n", area=PI*radio*radio);
}

void Trap(){
  int base1, base2, altura;
  printf("Ingrese la base mayor: ");
  scanf("%d", &base1);
  printf("Ingrese la base menor: ");
  scanf("%d", &base2);
  printf("Ingrese la altura: ");
  scanf("%d", &altura);
  printf("El area del trapecio vale: %d\n", area=((base1+base2)*altura)/2);
}

void Tria(){
  int base, altura;
  printf("Ingrese la base del triangulo: ");
  scanf("%d", &base);
  printf("Ingrese la altura del triangulo: ");
  scanf("%d", &altura);
  printf("El area del triangulo vale: %d\n",area=(base*altura)/2);
}