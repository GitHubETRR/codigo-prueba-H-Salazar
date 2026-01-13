#include <stdio.h>

int main(void) {
    int Lado1, Lado2, Lado3;
    printf("Ingrese lado 1: ");
    scanf("%d", &Lado1);
    printf("Ingrese lado 2: ");
    scanf("%d", &Lado2);
    printf("Ingrese lado 3: ");
    scanf("%d", &Lado3);
    if (Lado1 + Lado2 > Lado3 && Lado1 + Lado3 > Lado2 && Lado2 + Lado3 > Lado1)
        if (Lado1 == Lado2 == Lado3) printf("El triangulo es equilatero");
        else if (Lado1 == Lado2 || Lado1 == Lado3 || Lado2 == Lado3) printf("El triangulo es isoceles");
        else printf("El triangulo es escaleno");
    else printf("No es un triangulo");
    return 0;
}