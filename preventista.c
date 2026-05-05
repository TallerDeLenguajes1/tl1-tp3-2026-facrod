#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
float costoTotal (int cantidad, float precioUnitario) {
    float costoFinal;
    costoFinal = cantidad * precioUnitario;
    return costoFinal;
}
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
};
int main() {
    srand(time(NULL));

    int clientesNro;
    printf("¿Cuántos nombres vas a ingresar?: ");
    scanf("%d", &clientesNro);
    
    struct Cliente clientes[clientesNro];
    char buff[50];

    for (int i = 0; i < clientesNro; i++)
    {
        clientes[i].ClienteID = i;
        printf("Nombre del cliente: \n");
        scanf("%s", buff);
        clientes[i].NombreCliente = (char *) malloc( strlen(buff) * sizeof(char) + 1);
        strcpy(clientes[i].NombreCliente, buff);
        int cantidadProductos = (rand() % (5 - 1 + 1)) + 1;
        clientes[i].CantidadProductosAPedir = cantidadProductos;
        clientes[i].Productos = (struct Producto *) malloc(cantidadProductos * sizeof(struct Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = (rand() % 10) + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10;
        };
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
            
    for (int k = 0; k < clientesNro; k++)
    {
        printf("-------Cliente: %s -------\n", clientes[k].NombreCliente);
        printf("Id: %d\n", clientes[k].ClienteID);
        printf("Cantidad de productos pedidos: %d\n", clientes[k].CantidadProductosAPedir);

        for ( int l = 0; l < clientes[k].CantidadProductosAPedir; l++)
        {
            printf("%d) Producto: %s\n", l , clientes[k].Productos[l].TipoProducto);
            printf("-Cantidad: %d\n", clientes[k].Productos[l].Cantidad);
            printf("-id: %d\n", clientes[k].Productos[l].ProductoID);
            printf("-Precio unitario: %f\n", clientes[k].Productos[l].PrecioUnitario);
            float costoFinal = costoTotal(clientes[k].Productos[l].Cantidad, clientes[k].Productos[l].PrecioUnitario);
            printf("Producto: %f\n", costoFinal);
        }
    }
    
    return 0;
}