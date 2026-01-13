#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MAX 100

void Generar(int matriz[N][N]);
int Primo(int);
void EsPrimo(int matriz[N][N], int vector[N*N]);

int main()
{
    int matriz[N][N], vector[N*N]={0};
    Generar(matriz);
    EsPrimo(matriz, vector);
    printf ("Los numeros primos son: ");
    for (int i = 0; i < N*N; i++) {
        if (vector[i] > 0) printf("%d ", vector[i]);
    }
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

int Primo (int num){
    if (num <= 1) return 0;
    for (int k = 2; k <= num/2; k++) {
        if (num % k == 0) {
            return 0;
        }
    }
    return 1;
}

void EsPrimo (int matriz[N][N], int vector[N*N]){
    int indice = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (Primo(matriz[i][j]) == 1){
                if (indice < N*N) {
                    vector[indice] = matriz[i][j];
                    indice++;
                }
            }
        }
    }
}
