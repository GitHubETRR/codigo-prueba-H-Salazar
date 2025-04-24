#include <stdio.h>
#define MAX 50

typedef struct {
  int stock;
  char nombre[10];
  float precio;
} Producto;

void agregarProducto(Producto inventario[], int);
void mostrarInventario(Producto inventario[]);
void actualizarInventario(Producto inventario[], int posicion);

int main()
{
  int posicion;
  int accion=0;
  Producto inventario[MAX]= {0};
  while(accion!=4) {
    printf("\nQué acción desea realizar: \n1. Agregar Producto\n");
    printf("2. Actualizar Inventario\n3. Mostar inventario\n4. Salir\n");
    printf("==>");
    scanf("%d",&accion);
    if (accion==4) {
      printf(">>Saliendo del programa...\n");
      break;
    }
    if (accion>4 || accion<1) {
        printf(">>Numero invalido<<\n");
        continue;
    }
    if (accion==3) {
        mostrarInventario(inventario);
        continue;
    }
    printf("Ingrese la posición (0-%d): ", MAX-1);
    scanf("%d",&posicion);
    if (posicion>MAX-1 || posicion<0) {
        printf(">>Numero invalido<<\n");
        continue;
    }
    if (accion==2){
        if (inventario[posicion].stock==0) printf("\n¡¡¡No existe un articulo en esa posición!!!\n");
        else actualizarInventario(inventario, posicion);
    }
    if (accion==1) {
        if (inventario[posicion].stock!=0) printf("¡¡¡Ya existe un producto en esa posición!!!");
        else agregarProducto(inventario, posicion);
      }
  }
  return 0;
}

void mostrarInventario(Producto inventario[]) {
  Producto producto;
  int hayProducto=0;
  for (int i=0; i<MAX; i++) {
    if (inventario[i].stock>0) {
        printf("\n------------------\n");
        printf("Posición %d", i);
      printf("\nNombre: %s\n", inventario[i].nombre);
      printf("Precio: %.2f\n", inventario[i].precio);
      printf("Stock: %d\n", inventario[i].stock);
      printf("------------------\n");
      hayProducto=1;
    }
  }
  if (!hayProducto) printf("\nNo hay productos registrados\n");
}


void agregarProducto(Producto inventario[], int posicion) {
    while(getchar() != '\n');
  printf("\nIngrese nombre del producto: ");
  scanf("%9s",inventario[posicion].nombre);
  while(getchar() != '\n');
  printf("Ingrese stock: ");
  scanf("%d",&inventario[posicion].stock);
  while(getchar() != '\n');
  printf("Ingrese precio: ");
  scanf("%f",&inventario[posicion].precio);
  while(getchar() != '\n');
}

void actualizarInventario(Producto inventario[], int posicion) {
  int nuevoStock, res;
  float nuevoPrecio;
  printf("\n1. Cambiar Precio\n2. Cambiar Stock\n==>");
  scanf("%d",&res);
  switch(res){
  case 1:
      printf("Ingrese nuevo Precio: ");
      scanf("%f",&nuevoPrecio);
      inventario[posicion].precio=nuevoPrecio;
      printf("\nPrecio actualizado.\n");
      break;
  case 2:
      printf("Ingrese nuevo Stock (si ingresa 0 se elimina el producto): ");
      scanf("%d",&nuevoStock);
      inventario[posicion].stock=nuevoStock;
      printf("\nStock actualizado.\n");
      break;
  default:
      printf(">>Numero invalido<<\n");
  }
}

