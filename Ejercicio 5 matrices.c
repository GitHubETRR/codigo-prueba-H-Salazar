#include <stdio.h>
#define PROVINCIAS 5
#define MESES 3
void vmes(int ventas[PROVINCIAS][MESES]);
void vpro(int ventas[PROVINCIAS][MESES]);
void vtri(int ventas[PROVINCIAS][MESES]);

int main()
{
    int ventas[PROVINCIAS][MESES]={{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2}};
    int res;
    printf("¿Qué informe desea ver?\n 1.Por mes\n 2.Por provincia\n 3.Por trimestre\n==>");
    scanf("%d",&res);
    switch(res){
        case 1: printf("Las ventas totales por mes son:\n");
            vmes(ventas);
            break;
        case 2: printf("Las ventas totales por provincia son:\n");
            vpro(ventas);
            break;
        case 3: printf("Las ventas totales por trimestre son:\n");
            vtri(ventas);
            break;
        default: printf("Numero ingresado no valido");
    }
    return 0;
}

void vmes(int ventas[PROVINCIAS][MESES]){
    int enero=0, febrero=0, marzo=0;
    for(int i=0; i<PROVINCIAS; i++){
        enero+=ventas[i][0];
        febrero+=ventas[i][1];
        marzo+=ventas[i][2];
    }
    printf("En enero: %d\n", enero);
    printf("En febrero: %d\n", febrero);
    printf("En marzo: %d\n", marzo);
}

void vpro(int ventas[PROVINCIAS][MESES]){
    int ventaspro[PROVINCIAS]={0};
    for(int i=0; i<PROVINCIAS; i++){
        for(int j=0; j<MESES; j++){
            ventaspro[i]+=ventas[i][j];
        }
    }
    printf("Buenos Aires: %d\n", ventaspro[0]);
    printf("Entre Ríos: %d\n", ventaspro[1]);
    printf("Santa Fe: %d\n", ventaspro[2]);
    printf("Córdoba: %d\n", ventaspro[3]);
    printf("San Luis: %d\n", ventaspro[4]);
}

void vtri(int ventas[PROVINCIAS][MESES]){
    int tri=0;
    for(int i=0; i<PROVINCIAS; i++){
        for(int j=0; j<MESES; j++){
            tri+=ventas[i][j];
        }
    }
    printf("%d\n", tri);
}