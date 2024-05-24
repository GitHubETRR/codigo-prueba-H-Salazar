#include <stdio.h>
const int PI=3.14;

int main(void)
{
    int area, figura, radio, largo, ancho;
    printf("1 para rectangulo/cuadrado, cualquier otro numero circunferencia: ");
    scanf("%d", &figura);
    if (figura==1)
    {
        printf("Ingrese largo del rectangulo o cuadrado: ");
        scanf("%d", &largo);
        printf("Ingrese ancho del rectangulo o cuadrado: ");
        scanf("%d", &ancho);
        area=largo*ancho;
        if (largo==ancho)
        {
        printf("El area del cuadrado vale: %d", area);
        }
        else
        {
        printf("El area del rectangulo vale: %d", area);
        }
    }
    else
    {
        printf("Radio de la circunferencia: ");
        scanf("%d", &radio);
        area=PI*radio*radio;
        printf("El area de la circunferencia vale: %d", area);
    }

    return 0;
}