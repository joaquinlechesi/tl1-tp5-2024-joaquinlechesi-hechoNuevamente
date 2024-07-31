#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/* estas estructuras estan en la libreria funciones.h
typedef struct TProducto
{
    char * Descripcion;
    char * Categoria;
    int Precio;
    int Stock;

}TProducto;

typedef struct Tnodo
{
    TProducto dato;
    struct Tnodo *siguiente;
}Tnodo;
*/
// DECLARE SUS FUNCIONES AQUI
Tnodo *crearNodo(char *descripcion, char *categoria, int precio, int stock);
void crearLista(Tnodo **listaDeProductos, TProducto *listaDeProveedor);
Tnodo *filtrarPorStock(Tnodo *listaDeProductos);

int main()
{
    TProducto * ProductosDeProveedor1  = ProveedorDeLacteosPanaderiaLiquidos();
    MostrarProductosDeArreglo(ProductosDeProveedor1, 17, "Proveedor 1");

     
    // PUNTO 1. Insertar todos los productos en una única lista
    Tnodo *listaDeProductos=NULL;
    // llame sus funciones aquí
    crearLista(&listaDeProductos, ProductosDeProveedor1);

    MostrarLista(listaDeProductos, "Todos los productos");
    // FIN PUNTO 1
    
    // PUNTO 2. Ingrese un precio y filtre los productos que tengan un precio mayor al ingresado
    Tnodo *productosFiltradosPorPrecio=NULL;
    float precio;
    printf("Ingrese precio: \n");
    scanf("%f", &precio); 
    printf("Precio ingresado: %f",precio);
    // llame sus funciones aquí
    //productos = filtrado por precio

    MostrarLista(productosFiltradosPorPrecio, "Productos con precio filtrado"); 
    // FIN PUNTO 2

    // PUNTO 3. Contar productos sin stock y mostrar la cantidad
    int cantidadSinStock; 
    // llame sus funciones aquí

    MostrarCantidadSinStock(cantidadSinStock); 
    //FIN PUNTO 3

    // PUNTO 4. Desenlazar los productos sin stock y mostrarlos
    Tnodo *productosFiltradoPorStock=NULL;
    int stock;
    printf("Ingrese stock: \n");
    scanf("%d", &stock); 
    printf("Stock ingresado: %d",stock);
    // llame sus funciones aquí
    
    MostrarLista(productosFiltradoPorStock, "Productos con stock mayor al ingresado");
    MostrarLista(listaDeProductos, "Productos con stock menor a al ingresado"); 
    // FIN PUNTO 4

    //PUNTO 5. Liberar todas las listas
    // llame sus funciones aquí

    MostrarLista(listaDeProductos, "Lista vacia de listaDeProductos "); 
    MostrarLista(productosFiltradosPorPrecio, "Lista vacia de productosFiltradosPorPrecio");
    MostrarLista(productosFiltradoPorStock, "Lista vacia de productosSinStock");
    // FIN PUNTO 5
}

//IMPLEMENTE SUS FUNCIONES AQUI

Tnodo *crearNodo(char *descripcion, char *categoria, int precio, int stock){
    Tnodo *nuevoNodo;
    int longitud;
    nuevoNodo = (Tnodo *)malloc(sizeof(Tnodo));
    longitud = strlen(descripcion) + 1;
    nuevoNodo->dato.Descripcion = (char *)malloc(sizeof(char) * longitud);
    strcpy(nuevoNodo->dato.Descripcion, descripcion);
    longitud = strlen(categoria) + 1;
    nuevoNodo->dato.Categoria = (char *)malloc(sizeof(char) * longitud);
    strcpy(nuevoNodo->dato.Categoria, categoria);
    nuevoNodo->dato.Precio = precio;
    nuevoNodo->dato.Stock = stock;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void crearLista(Tnodo **listaDeProductos, TProducto *listaDeProveedor){
    //Tnodo *aux = NULL;
    //*listaDeProductos = aux;
    //int longitud;
    //aux = *listaDeProductos;
    for (int i = 0; i < 17; i++)
    {
        Tnodo *aux = NULL;
        aux = crearNodo(listaDeProveedor[i].Descripcion, listaDeProveedor[i].Categoria, listaDeProveedor[i].Precio, listaDeProveedor[i].Stock);
        if (*listaDeProductos == NULL)
        {
            *listaDeProductos = aux;
        }else
        {
            aux->siguiente = *listaDeProductos;
            *listaDeProductos = aux;
        }
    }
}

Tnodo *filtrarPorStock(Tnodo *listaDeProductos){
    
}