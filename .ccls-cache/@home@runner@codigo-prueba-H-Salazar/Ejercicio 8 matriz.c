#include <stdio.h>
#define LINEA 3
#define COCHE 12

int recxlin (int cole[LINEA][COCHE], int);

int main()
{
    int cole[LINEA][COCHE]={0};
    int rec=0;
    int linea, coche, dinero;

    char continuar='S';
    while (continuar == 'S' || continuar == 's'){
        printf("\nIngrese numero de linea (1 al 3):\n");
        scanf("%d", &linea);
        printf("Ingrese numero de coche (1 al 12):\n");
        scanf("%d", &coche);
        printf("Ingrese recaudación:\n");
        scanf("%d", &dinero);
        while(getchar() != '\n');

        if (linea <= 0 || linea > LINEA || coche <= 0 || coche > COCHE) {
            printf("\nNumero de linea o coche incorrecto. Intente de nuevo\n");
            continue;
        }

        cole[linea-1][coche-1] += dinero;

        printf("\nDesea continuar la operación (S/N) => ");
        scanf("%c",&continuar);
    }

    printf("\nLa recaudación total por linea es de:\n");
    for (int i=0; i<LINEA; i++) printf("Linea %d: %d\n", i+1, recxlin(cole, i));
    printf("\nLa recaudación por coche es de:\n");
    for(int i=0; i<LINEA; i++){
        for( int j=0; j<COCHE; j++) printf("Linea: %d - Coche: %d => %d\n", i+1, j+1, cole[i][j]);
    }
    for(int i=0; i<LINEA; i++){
        for(int j=0; j<COCHE; j++){
            rec+=cole[i][j];
        }
    }
    printf("\nLa recaudación total es: %d", rec);

    return 0;
}

int recxlin (int cole[LINEA][COCHE], int k){
    int reclin=0;
    for(int j=0; j<COCHE; j++){
        reclin+=cole[k][j];
    }
    return reclin;
}