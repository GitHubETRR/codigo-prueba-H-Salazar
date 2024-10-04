#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void Generar(int matriz[N][N], int ordmatriz[N][N]);
void Ordenar(int matriz[N][N], int ordmatriz[N][N]);
void Imprimir(int mat[N][N]);

int main()
{
    int matriz[N][N], ordmatriz[N][N];
    Generar(matriz,ordmatriz);
    Ordenar(matriz,ordmatriz);
    printf("La matriz es: \n");
    Imprimir(matriz);
    printf("La matriz ordenada de mayor a menor es: \n");
    Imprimir(ordmatriz);
    return 0;
}

void Generar(int matriz[N][N], int ordmatriz[N][N]){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand()%101;
            ordmatriz[i][j]=matriz[i][j];
        }
    }
}

void Ordenar(int matriz[N][N], int ordmatriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                for(int l = (k == i) ? j + 1 : 0; l < N; l++){
                    //k==i porque tienen los mismos numeros las matrices por eso si es cierto luego evaluo el j que esta al lado al sumarle 1
                    if (ordmatriz[i][j] > ordmatriz[k][l]){
                    int temp = ordmatriz[i][j];
                    ordmatriz [i][j]= ordmatriz [k][l];
                    ordmatriz [k][l] = temp;
                    //intercambios entre variables usado en ejercicio 37
                    }
                }
            }
        }
    }
}

void Imprimir (int mat[N][N]){
    for (int i = 0; i < N; i++){
        printf("\n");
        for (int j = 0; j < N; j++) printf("%d\t", mat[i][j]);
    }
    printf("\n");
}