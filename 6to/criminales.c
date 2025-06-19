#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef enum {
    AGREGAR=1,
    IMPRIMIR,
    SALIR,
} opciones_t;

typedef struct ante {
    char *descripcion;
    int year;
    struct ante *next;
} Antecedentes_t;

typedef struct crime {
    char nombre[MAX];
    char apellido[MAX];
    int nivelPeligro;
    Antecedentes_t *antecedentes;
    struct crime *next;
} Criminal_t;

void menu(void);
int comprobar_entero(int, int);

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
    inicio=cargar_desde_txt("criminales.txt");
    if(inicio==NULL) printf("\nNo se encontro un archivo previo. Iniciando lista vacia\n");
    do {
        menu();
        accion=comprobar_entero(AGREGAR, SALIR);
        switch(accion) {
        case AGREGAR:
            inicio=agregar_criminal(inicio);
            guardar_en_txt(inicio, "criminales.txt");
            break;

        case IMPRIMIR:
            imprimir_criminales(inicio);
            break;

        case SALIR:
            guardar_en_txt(inicio, "criminales.txt");
            printf("\nSaliendo...");
            break;
        }
    } while (accion!=SALIR);

    liberar_todo(inicio);
    return 0;
}

void menu(void) {
    printf("\n1. Agregar criminales");
    printf("\n2. Imprimir criminales");
    printf("\n3. Salir\n");
}

int comprobar_entero(int min, int max) {
    int valor;
    while(1) {
        printf("\n--> ");
        scanf("%d", &valor);
        if(valor>=min && valor<=max) {
            while(getchar()!='\n');
            return valor;
        }
        while(getchar()!='\n');
        printf("\nOpcion no valida. Ingrese numero entre %d y %d\n", min, max);
    }
}

Criminal_t * agregar_criminal(Criminal_t *inicio) {
    int cant;
    int maxPeligro=10, minPeligro=1;
    Criminal_t *crime_ptr=(Criminal_t *) malloc(sizeof(Criminal_t));
    crime_ptr->next=inicio;
    printf("Nombre: ");
    scanf("%s", crime_ptr->nombre);
    printf("Apellido: ");
    scanf("%s", crime_ptr->apellido);
    printf("Nivel de peligro (%d-%d): ", minPeligro, maxPeligro);
    crime_ptr->nivelPeligro=comprobar_entero(minPeligro, maxPeligro);
    crime_ptr->antecedentes=NULL;
    printf("Cuantos antecedentes tiene?  0=Ninguno: ");
    scanf("%d", &cant);
    while(getchar()!='\n');
    for(int i=0; i<cant; i++) {
        printf("Antecedente #%d:\n", i+1);
        crime_ptr->antecedentes=agregar_ante(crime_ptr->antecedentes);
    }
    inicio=crime_ptr;
    printf("¡¡Criminal registrado exitosamente!!\n");
    return inicio;
}

Antecedentes_t * agregar_ante(Antecedentes_t *inicio) {
    int minYear= 1900, yearActual=2025;
    char buffer[1000];
    Antecedentes_t *ante_ptr=(Antecedentes_t *) malloc(sizeof(Antecedentes_t));
    printf("Agregar descripcion de crimen: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';// Eliminar el salto de línea final
    ante_ptr->descripcion = strdup(buffer);// Asignar memoria dinámica para la descripción
    printf("Agregar year del crimen (%d-%d): ", minYear, yearActual);
    ante_ptr->year=comprobar_entero(minYear, yearActual);
    ante_ptr->next=inicio;
    return ante_ptr;
}

void imprimir_criminales(Criminal_t *inicio) {
    Criminal_t *actual=inicio;
    int contador=1;
    printf("\n=== LISTA DE CRIMINALES ===\n");
    while(actual!=NULL) {
        printf("\n----- CRIMINAL #%d -----\n", contador++);
        printf("Nombre completo: %s %s\n", actual->nombre, actual->apellido);
        printf("Nivel de peligro: %d/10\n", actual->nivelPeligro);

        if(actual->antecedentes!=NULL) {
            printf("\nHistorial de antecedentes:\n");
            imprimir_ante(actual->antecedentes);
        } else {
            printf("\nNo registra antecedentes.\n");
        }
        printf("------------------------\n");
        actual=actual->next;
    }
}

void imprimir_ante(Antecedentes_t *inicio) {
    Antecedentes_t *actual=inicio;
    int i=0;
    while(actual!=NULL) {
        printf("%d- [Year %d]: %s\n", ++i, actual->year, actual->descripcion);
        actual=actual->next;
    }
}

void liberar_todo(Criminal_t *inicio) {
    while(inicio!=NULL) {
        Antecedentes_t *ante=inicio->antecedentes;
        while(ante!=NULL) {
            Antecedentes_t *aux=ante;
            ante=ante->next;
            free(aux->descripcion);
            free(aux);
        }
        Criminal_t *aux=inicio;
        inicio=inicio->next;
        free(aux);
    }
}

void guardar_en_txt(Criminal_t *inicio, const char *nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "w");
    if(!f) {
        perror("No se pudo abrir el archivo");
        return;
    }

    Criminal_t *crime_ptr = inicio;
    while(crime_ptr != NULL) {
        // Escribir información del criminal
        fprintf(f, "Nombre:%s Apellido:%s Nivel de Peligro:%d\n", crime_ptr->nombre, crime_ptr->apellido, crime_ptr->nivelPeligro);
        // Contar antecedentes
        Antecedentes_t *ante_ptr=crime_ptr->antecedentes;
        int contador_antecedentes=0;
        while(ante_ptr != NULL) {
            contador_antecedentes++;
            ante_ptr = ante_ptr->next;
        }
        fprintf(f, "Antecedentes:%d\n", contador_antecedentes);
        // Escribir antecedentes
        ante_ptr=crime_ptr->antecedentes;
        while(ante_ptr != NULL) {
            fprintf(f, "Descripcion:%s\nYear:%d\n", ante_ptr->descripcion, ante_ptr->year);
            ante_ptr=ante_ptr->next;
        }
        crime_ptr=crime_ptr->next;
    }

    fclose(f);
}

Criminal_t *cargar_desde_txt(const char *nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "r");
    if(!f) {
        perror("No se pudo abrir el archivo");
        return NULL;
    }
    Criminal_t *lista = NULL;
    char nombre[MAX], apellido[MAX];
    int nivelPeligro, cantAntecedentes;
    while(fscanf(f, "Nombre:%s Apellido:%s Nivel de Peligro:%d\n", nombre, apellido, &nivelPeligro) == 3) {
        Criminal_t *nuevo = (Criminal_t *)malloc(sizeof(Criminal_t));
        if(!nuevo) {
            perror("Error de memoria");
            fclose(f);
            return lista;
        }
        strcpy(nuevo->nombre, nombre);
        strcpy(nuevo->apellido, apellido);
        nuevo->nivelPeligro = nivelPeligro;
        nuevo->antecedentes = NULL;
        // Leer cantidad de antecedentes
        if(fscanf(f, "Antecedentes:%d\n", &cantAntecedentes) != 1) {
            free(nuevo);
            break;
        }
        // Leer antecedentes
        for(int i = 0; i < cantAntecedentes; i++) {
            char descripcion[1024];  // Buffer temporal grande
            int year;
            if(fscanf(f, "Descripcion:%[^\n]\nYear:%d\n", descripcion, &year) != 2) {
                // Liberar memoria si hay error
                liberar_todo(nuevo);
                fclose(f);
                return lista;
            }
            Antecedentes_t *ante=(Antecedentes_t *)malloc(sizeof(Antecedentes_t));
            if(!ante) {
                perror("Error de memoria");
                liberar_todo(nuevo);
                fclose(f);
                return lista;
            }
            ante->descripcion=strdup(descripcion);
            if(!ante->descripcion) {
                perror("Error de memoria");
                free(ante);
                liberar_todo(nuevo);
                fclose(f);
                return lista;
            }
            ante->year = year;
            ante->next = nuevo->antecedentes;
            nuevo->antecedentes = ante;
        }
        // Agregar a la lista (al inicio)
        nuevo->next = lista;
        lista = nuevo;
    }

    fclose(f);
    return lista;
}