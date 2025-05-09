#include <stdio.h>
const int PI=3.14;

int main(void)
{
    int Area, Figura, Radio, Largo, Ancho, Perimetro;
    printf("1 para rectangulo/cuadrado, cualquier otro numero circunferencia: ");
    scanf("%d", &Figura);
    if (Figura==1){
        printf("Ingrese largo del rectangulo o cuadrado: ");
        scanf("%d", &Largo);
        printf("Ingrese ancho del rectangulo o cuadrado: ");
        scanf("%d", &Ancho);
        Area=Largo*Ancho;
        if (Largo==Ancho){
            printf("El area del cuadrado vale: %d\n", Area);
            Perimetro=4*Largo;
            printf("El perimetro del cuadrado vale: %d\n", Perimetro);
        }
        else{
            Perimetro=2*(Largo+Ancho);
            printf("El area del rectangulo vale: %d\n", Area);
            printf("El perimetro del rectangulo vale: %d\n", Perimetro);
        }
    }
    else{
        printf("Radio de la circunferencia: ");
        scanf("%d", &Radio);
        Area=PI*Radio*Radio;
        Perimetro=2*PI*Radio;
        printf("El area de la circunferencia vale: %d\n", Area);
        printf("El perimetro de la circunferencia vale: %d", Perimetro);
    }
    return 0;
}