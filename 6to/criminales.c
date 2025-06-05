#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct ante{
    char descripcion[MAX];
    int year;
    struct ante *next;
} Antecedentes_t;

typedef struct crime{
    char nombre[MAX];
    int nivelPeligro;
    Antecedentes_t *antecedentes;
    struct crime *next;
}Criminal_t;

Criminal_t * agregar_criminal(Criminal_t *inicio);
Antecedentes_t * agregar_ante(Antecedentes_t *inicio);
void imprimir_criminales(Criminal_t *inicio);
void imprimir_ante(Criminal_t *inicio);
void liberar_criminales(Criminal_t *inicio);

int main()
{
    Criminal_t *inicio=NULL;
    int accion;
    do{
        printf("\n1. Agregar criminales");
        printf("\n2. Imprimir criminales");
        printf("\n3. Salir\n");
        printf("\n--> ");
        scanf("%d", &accion);

        switch(accion){
            case 1:
                inicio=agregar_criminal(inicio);
                break;
            case 2:
                imprimir_criminales(inicio);
                break;
            case 3:
                printf("\nSaliendo...");
                break;
            default:
                printf("\nOpcion invalida");
        }

    } while (accion!=3);

    liberar_criminales(inicio);
    return 0;
}

Criminal_t * agregar_criminal(Criminal_t *inicio){
    int res;
    Criminal_t *crime_ptr=(Criminal_t *) malloc(sizeof(Criminal_t));
    crime_ptr->next=inicio;
    crime_ptr->antecedentes=NULL;
    printf("Nombre: ");
    scanf("%s", crime_ptr->nombre);
    printf("Nivel de peligro: ");
    scanf("%d", &crime_ptr->nivelPeligro);
    printf("Cuantos antecedentes tiene?  0=Ninguno: ");
    scanf("%d", &res);
    for(int i=0; i<res; i++){
        crime_ptr->antecedentes=agregar_ante(crime_ptr->antecedentes);
    }
    inicio=crime_ptr;
    return inicio;
}

Antecedentes_t * agregar_ante(Antecedentes_t *inicio){
    Antecedentes_t *ante_ptr=(Antecedentes_t *) malloc(sizeof(Antecedentes_t));
    printf("Agregar descripcion de crimen: ");
    scanf("%s", ante_ptr->descripcion);
    printf("Agregar año del crimen: ");
    scanf("%d", &ante_ptr->year);
    ante_ptr->next=inicio;
    return inicio;
}

imprimir_criminales(Criminal_t *inicio){

}

imprimir_ante(Criminal_t *inicio){

}
