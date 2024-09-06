#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
#define MAX 15

int main(){
    int matriz[N][N];
    int valor_maximo = 0;
    int fila_max = 0, col_max = 0;
    int veces = 0;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand()%MAX+1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] > valor_maximo) {
                valor_maximo = matriz[i][j];
                fila_max = i;
                col_max = j;
            }
        }
    }


    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }


    printf("\nValor máximo: %d\n", valor_maximo);
    printf("Ubicación del valor máximo: Fila %d, Columna %d\n", fila_max, col_max);
    printf("Se repite en las posiciones: \n");

    for (int i = 0; i < N;i++){
        for (int j =0; j < N; j++){
            if (matriz[i][j] == valor_maximo){
                veces++;
                printf("Fila %d, Columna %d\n",i ,j);
            }
        }
    }

    printf("Veces que se repite: %d", veces);

    return 0;
}