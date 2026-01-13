#include <stdio.h>
#include <stdlib.h>

int buscarMayor(int *numeros, int);

int main()
{
    int nums;
    do{
        printf("Ingrese cantidad de numeros:");
        scanf("%d", &nums);
    } while(nums<=0);
    int *numeros=(int *) malloc(nums*sizeof(int)); 
    //No se puede hacer malloc(sizeof(nums)); porque solo reserva la cantidad para un entero
    //hay que multiplicar un int por cada cantidad de numeros
    if(numeros==NULL){
        printf("Error al reservar memoria\n");
        exit(-1);
    }
    for (int i=0; i<nums; i++){
        printf("Ingrese los valores:");
        scanf("%d", &numeros[i]);
    }
    int mayor=buscarMayor(numeros, nums);
    printf("El mayor numero ingresado es: %d", mayor);
    free(numeros);
    return 0;
}

int buscarMayor(int *numeros, int nums){
    int mayor=numeros[0];
    for(int i=0; i<nums; i++){
        if(numeros[i]>mayor) mayor=numeros[i];
    }
    return mayor;
}
