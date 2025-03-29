#include <stdio.h>
#define N 3
void rotar(int matriz[N][N]);

int main()
{
    int matriz[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("La matriz original es:\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nLa matriz rotada es: ");
    rotar(matriz);
    return 0;
}

void rotar(int matriz[N][N]){
    printf("\n");
    for(int k=N-1; k<N && k>=0; k--){
        for(int l=N-1; l<N && l>=0; l--){
            printf("%d\t",matriz[k][l]);
        }
        printf("\n");
    }
}