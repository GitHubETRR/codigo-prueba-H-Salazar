#include <stdio.h>
#define MES 12

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

int esFechaValida(int, int, int);
int getDia();
int getMes();
int getAnio();
int isBisiesto(int);

int main() {
    Fecha fecha;
    do{
        fecha.dia = getDia();
        fecha.mes = getMes();
        fecha.anio = getAnio();
        if(!esFechaValida(fecha.dia, fecha.mes, fecha.anio)) printf("La fecha ingresada es invalida. Por favor intente de nuevo.\n");
    }
    while(!esFechaValida(fecha.dia, fecha.mes, fecha.anio));
    printf("\n");
    printf("Día: %d\n", fecha.dia);
    printf("Mes: %d\n", fecha.mes);
    printf("Año: %d\n", fecha.anio);
    if (isBisiesto(fecha.anio)) printf("%d es un año bisiesto.\n", fecha.anio);
    else printf("%d no es un año bisiesto.\n", fecha.anio);

    return 0;
}

int esFechaValida(int dia, int mes, int anio) {
    //Todo lo que está abajo es para definir el rango
    if (mes < 1 || mes > 12) return 0; 
    if (dia < 1) return 0;
    int diasxMes[MES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    if (mes == 2 && isBisiesto(anio)) diasxMes[1] = 29; //por febrero, si es bisiesto se cambia sus dias
    if (dia > diasxMes[mes - 1]) return 0;

    return 1;
}

int getDia(){
    int dia;
    printf("Ingrese el día: ");
    scanf("%d", &dia);
    return dia;
}

int getMes(){
    int mes;
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    return mes;
}

int getAnio(){
    int anio;
    printf("Ingrese el año: ");
    scanf("%d", &anio);
    return anio;
}

int isBisiesto(int anio){
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) return 1;
    return 0;
}