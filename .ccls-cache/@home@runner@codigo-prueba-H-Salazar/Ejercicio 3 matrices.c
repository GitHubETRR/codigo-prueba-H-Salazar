#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define MAX 100

void Generar(int matriz[N][N]);
void EsPrimo(int matriz[N][N]);

int main()
{
    int matriz[N][N];
    Generar(matriz);
    EsPrimo(matriz);
    printf("Hello World");

    return 0;
}

void Generar(int matriz[N][N]){
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand()%MAX+1;
        }
    }
}

void EsPrimo (int matriz[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num = matriz[i][j];
            int esPrimo=1;
            if (num <= 1) {
                esPrimo=0;

            }
            for (int k=2; k <= num/2; k++) {
                if (num % k == 0) {
                    esPrimo=0;
                }
            }
            if(esPrimo) printf("El numero %d es primo\n", num);
            else printf("El numero %d es NO primo\n", num);
        }
    }
}
//Todavia no guardalos numeros primos en un vector, pero si los imprimo.