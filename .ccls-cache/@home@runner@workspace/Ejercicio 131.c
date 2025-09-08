#include <stdio.h>
#define LETRAS 10

typedef struct {
    int valor1;
    float valor2;
    char valor3[10];
} Datos;

Datos crearEstructura();

int main() {
    Datos datos = crearEstructura();
    printf("\nValor1: %d\n", datos.valor1);
    printf("Valor2: %.2f\n", datos.valor2);
    printf("Valor3: %s\n", datos.valor3);
    return 0;
}

Datos crearEstructura() {
    Datos resultado;
    printf("Ingrese valor tipo numero entero:\n");
    scanf("%d",&resultado.valor1);
    printf("Ingrese valor tipo numero con 2 decimales:\n");
    scanf("%f",&resultado.valor2);
    while (getchar() != '\n'); //refrescar el buffer(teclado)
    printf("Ingrese valor tipo caracter:\n");
    scanf("%s",resultado.valor3); //si coloco & le estoy dando un puntero a todo el array (%s epera un puntero a un solo caracter donde pueda empezar a guardar el string)(Solo me da una advertencia al ejecutar)
    return resultado;
}