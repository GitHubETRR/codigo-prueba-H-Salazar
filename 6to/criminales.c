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
    char apellido[MAX];
    int nivelPeligro;
    Antecedentes_t *antecedentes;
    struct crime *next;
}Criminal_t;

void menu(void);
Criminal_t * agregar_criminal(Criminal_t *inicio);
Antecedentes_t * agregar_ante(Antecedentes_t *inicio);
void imprimir_criminales(Criminal_t *inicio);
void imprimir_ante(Antecedentes_t *inicio);
void liberar_todo(Criminal_t *inicio);
void guardar_en_txt(Criminal_t * inicio, const char *nombreArchivo);
Criminal_t * cargar_desde_txt(const char *nombreArchivo);

int main()
{
    Criminal_t *inicio=NULL;
    int accion;
    do{
        menu();
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

    liberar_todo(inicio);
    return 0;
}

void menu(void){
    printf("\n1. Agregar criminales");
    printf("\n2. Imprimir criminales");
    printf("\n3. Salir\n");
    printf("\n--> ");
}

Criminal_t * agregar_criminal(Criminal_t *inicio){
    int cant;
    Criminal_t *crime_ptr=(Criminal_t *) malloc(sizeof(Criminal_t));
    crime_ptr->next=inicio;
    printf("Nombre: ");
    scanf("%s", crime_ptr->nombre);
    printf("Apellido: ");
    scanf("%s", crime_ptr->apellido);
    printf("Nivel de peligro: ");
    scanf("%d", &crime_ptr->nivelPeligro);
    crime_ptr->antecedentes=NULL;
    printf("Cuantos antecedentes tiene?  0=Ninguno: ");
    scanf("%d", &cant);
    for(int i=0; i<cant; i++){
        printf("Antecedente #%d:\n", i+1);
        crime_ptr->antecedentes=agregar_ante(crime_ptr->antecedentes);
    }
    inicio=crime_ptr;
    printf("¡¡Criminal registrado exitosamente!!\n");
    return inicio;
}

Antecedentes_t * agregar_ante(Antecedentes_t *inicio){
    Antecedentes_t *ante_ptr=(Antecedentes_t *) malloc(sizeof(Antecedentes_t));
    printf("Agregar descripcion de crimen: ");
    scanf("%s", ante_ptr->descripcion);
    printf("Agregar año del crimen: ");
    scanf("%d", &ante_ptr->year);
    ante_ptr->next=inicio;
    return ante_ptr;
}

void imprimir_criminales(Criminal_t *inicio){
    Criminal_t *actual=inicio;
    int contador=1;
    printf("\n=== LISTA DE CRIMINALES ===\n");
    while(actual != NULL) {
        printf("\n----- CRIMINAL #%d -----\n", contador++);
        printf("Nombre completo: %s %s\n", actual->nombre, actual->apellido);
        printf("Nivel de peligro: %d/10\n", actual->nivelPeligro);

        if(actual->antecedentes != NULL) {
            printf("\nHistorial de antecedentes:\n");
            imprimir_ante(actual->antecedentes);
        } else {
            printf("\nNo registra antecedentes.\n");
        }

        printf("------------------------\n");
        actual = actual->next;
    }
}

void imprimir_ante(Antecedentes_t *inicio){
    Antecedentes_t *actual=inicio;
    int i=0;
    while(actual!=NULL){
    printf("%d- [Year %d]: %s\n", i++, actual->year, actual->descripcion);
        actual=actual->next;
    }
}

void liberar_todo(Criminal_t *inicio){
    while(inicio!=NULL){
        Antecedentes_t *ante=inicio->antecedentes;
        while(ante!=NULL){
            Antecedentes_t *aux=ante;
            ante=ante->next;
            free(aux);
        }
        Criminal_t *aux=inicio;
        inicio=inicio->next;
        free(aux);
    }
}

void guardar_en_txt(Criminal_t * inicio, const char *nombreArchivo){

}

Criminal_t * cargar_desde_txt(const char *nombreArchivo){

}
