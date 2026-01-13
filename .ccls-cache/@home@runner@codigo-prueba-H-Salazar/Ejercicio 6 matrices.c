#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void Generar(int matriz[N][N]);
void Imprimir (int matriz[N][N]);

int main()
{
    int matriz[N][N];
    Generar(matriz);
    printf("Matriz original es:");
    Imprimir(matriz);
    printf("\nMatriz transpuesta:\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d\t", matriz[j][i]);
        }
        printf("\n");
    }
    printf("\nDiagonal principal:\n");
    for (int i=0; i<N; i++){
        printf("%d\t", matriz[i][i]);
    }
    printf("\n");
    printf("\nDiagonal secundaria:\n");
    for (int i=0; i<N; i++){
        printf("%d\t", matriz[i][N-1-i]);
    }
    printf("\n");
    return 0;
}

void Generar(int matriz[N][N]){
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            matriz[i][j] = rand()%51;
        }
    }
}

void Imprimir (int matriz[N][N]){
    for (int i=0; i<N; i++){
        printf("\n");
        for (int j=0; j<N; j++) printf("%d\t", matriz[i][j]);
    }
    printf("\n");
}