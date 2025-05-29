#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 30

typedef enum{
    AGREGAR=1,
    IMPRIMIR,
    MAYOR,
    MENOR,
    PROM,
    BUSCAR,
}opciones_t;

typedef struct alum {
    char nombre[CANT];
    char apellido[CANT];
    int promedio;
    struct alum *next;
} alum_t;

int mostrar_menu();
void imprimir(alum_t *);
void imprimir_alum_especifico(alum_t *alum);
alum_t * agregar_alumno(alum_t *lista);
alum_t * mayor(alum_t *lista);
alum_t * menor(alum_t *lista);
float promgen(alum_t *lista);
alum_t * buscar(alum_t *lista, char *nombre, char *apellido);
void liberar (alum_t *lista);
void guardar_en_txt(alum_t *lista, const char *nombre_archivo);
alum_t * cargar_desde_txt(const char *nombre_archivo);

int main() {
    alum_t *_6TEL=NULL;

    FILE *archivo = fopen("alumnos.txt", "r");
    fclose(archivo);
    _6TEL = cargar_desde_txt("alumnos.txt");


    int accion, res, opcion;
    do {
        do{
            accion=mostrar_menu();
            if(accion>BUSCAR || accion<AGREGAR){
                printf("¡¡Accion invalida!!\n\n");
                while (getchar() != '\n');
            }
        } while(accion<AGREGAR || accion>BUSCAR);

        switch(accion) {
        case AGREGAR:
            do {
                printf("\nAgrege alumno:\n");
                _6TEL = agregar_alumno(_6TEL); 
                printf("Desea agregar otro alumno? (1: Si, 0: No): ");
                scanf("%d", &opcion);
            } while (opcion == 1);
            break;
        case IMPRIMIR:
            printf("\nLista de alumnos:\n");
            imprimir(_6TEL);
            break;
        case MAYOR:
            alum_t *promayor=mayor(_6TEL);
            printf("\nMayor promedio: %d", promayor->promedio);
            printf("\nNombre: %s \nApellido: %s\n", promayor->nombre, promayor->apellido);
            break;
        case MENOR:
            alum_t *promenor=menor(_6TEL);
            printf("\nMenor promedio: %d", promenor->promedio);
            printf("\nNombre: %s \nApellido: %s\n", promenor->nombre, promenor->apellido);
            break;
        case PROM:
            float genpro=promgen(_6TEL);
            printf("\nPromedio general: %.2f", genpro);
            break;
        case BUSCAR:
            char nom_bus[CANT], ap_bus[CANT];
            printf("\nNombre a buscar--> ");
            scanf("%s", nom_bus);
            printf("Apellido a buscar--> ");
            scanf("%s", ap_bus);
            alum_t *encontrado=buscar(_6TEL, nom_bus, ap_bus);
            if(encontrado){
                printf("\n¡¡Alumno encontrado!!\n");
                imprimir_alum_especifico(encontrado);
            }
            else printf("\n¡¡Alumno no encontrado!!\n");
            break;
        default:
            printf("\nNumero ingresado incorrecto");
        }
        printf("\nDesea seguir operando? (0: No): ");
        scanf("%d", &res);
    } while(res!=0);
    guardar_en_txt(_6TEL, "alumnos.txt");
    liberar(_6TEL);
    return 0;
}

int mostrar_menu() {
    int opcion;
    printf("\n¿Qué desea hacer?\n");
    printf("1. Agregar alumno\n2. Imprimir lista\n3. Ver mayor promedio\n");
    printf("4. Ver menor promedio\n5. Promedio general\n6. Buscar alumno\n--> ");
    scanf("%d", &opcion);
    return opcion;
}


void imprimir(alum_t *lista) {
    while(lista!=NULL) {
        printf("---------------------\n");
        printf("Nombre: %s\n", (*lista).nombre);
        printf("Apellido: %s\n", lista->apellido);
        printf("Promedio: %d\n", lista->promedio);
        printf("---------------------\n");
        lista=lista->next;
    }
}

void imprimir_alum_especifico(alum_t *alum) {
    printf("Nombre: %s\n", alum->nombre);
    printf("Apellido: %s\n", alum->apellido);
    printf("Promedio: %d\n", alum->promedio);
}

alum_t *agregar_alumno(alum_t *lista) {
    alum_t *alu_ptr=(alum_t *) malloc(sizeof(alum_t));
    alu_ptr->next=lista;
    printf("Nombre: ");
    scanf("%s", alu_ptr->nombre);
    printf("Apellido: ");
    scanf("%s", alu_ptr->apellido);
    printf("Promedio: ");
    scanf("%d", &alu_ptr->promedio);
    lista=alu_ptr;
    printf("Alumno creado exitosamente\n");
    return lista;
}

alum_t *mayor(alum_t *lista) {
    if(lista==NULL) return NULL;
    alum_t *max=lista;
    while(lista!=NULL) {
        if(lista->promedio>max->promedio) max=lista;
        lista=lista->next;
    }
    return max;
}
alum_t *menor(alum_t *lista) {
    if(lista==NULL) return NULL;
    alum_t *men=lista;
    while(lista!=NULL) {
        if(lista->promedio<men->promedio) men=lista;
        lista=lista->next;
    }
    return men;
}

float promgen(alum_t *lista) {
    if(lista==NULL) return 0;
    float suma=0, cantidad=0;
    while(lista!=NULL) {
        suma+=lista->promedio;
        cantidad++;
        lista=lista->next;
    }
    return suma/cantidad;
}

void liberar (alum_t *lista) {
    alum_t *aux;
    while(lista!=NULL) {
        aux=lista;
        lista=lista->next;
        free(aux);
    }
}

alum_t *buscar(alum_t *lista, char *nombre, char *apellido){
    while(lista!=NULL){
        if(strcasecmp(lista->nombre, nombre)==0 && strcasecmp(lista->apellido, apellido)==0) return lista; 
        lista=lista->next;
    }
    return NULL;
}

void guardar_en_txt(alum_t *lista, const char *nombre_archivo){
    FILE *f=fopen(nombre_archivo, "w");//lo abre para w (es escribir)
    if(!f){
        perror("No se pudo abrir el archivo");
        return;
    }
    while(lista!=NULL){
        fprintf(f, "Nombre:%s Apellido:%s Promedio:%d\n", lista->nombre, lista->apellido, lista->promedio);
        lista=lista->next;//por cada alumno escribe una linea en ese formato
    }
    fclose(f);
    printf("Datos guardados en >%s<\n", nombre_archivo);
}

alum_t * cargar_desde_txt(const char *nombre_archivo){
    FILE *f=fopen(nombre_archivo, "r");
    if(!f){
        perror("No se pudo abrir el archivo");
        return NULL;
    }
    alum_t *lista=NULL;
    char nombre[CANT], apellido[CANT];
    int promedio;
    while(fscanf(f, "Nombre:%s Apellido:%s Promedio:%d\n", nombre, apellido, &promedio)==3){
        //lee una línea que cumpla el mismo formato que fprintf
        alum_t *nuevo = (alum_t *) malloc(sizeof(alum_t));
        strcpy(nuevo->nombre, nombre);
        strcpy(nuevo->apellido, apellido);
        nuevo->promedio=promedio; 
        //asignan el contenido (leído desde el archivo) al campo correspondiente del nuevo nodo
        nuevo->next=lista; //next del nuevo apunta al inicio de la lista
        lista=nuevo;//inicio de lista apunta al nuevo nodo
    }
    fclose(f);
    return lista;
}