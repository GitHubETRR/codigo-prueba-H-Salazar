#include <stdio.h>

void intercambio(int *,int *);
void dupli(int *, int *);

int main()
{
    int num1, num2;
    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&num2);
    dupli(&num1, &num2);
    printf("\nDuplicados: num1=%d  num2=%d", num1, num2);
    printf("\nAntes del intercambio: num1=%d  num2=%d", num1, num2);
    intercambio(&num1, &num2);
    printf("\nDespues del intercambio: num1=%d  num2=%d", num1, num2);

    return 0;
}

void intercambio(int *n1, int *n2){
    int temp=0;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
}
void dupli(int *n1, int *n2){
    *n1*=2;
    *n2*=2;
}
