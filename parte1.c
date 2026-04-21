#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *buscar_nombrePorPalabra(char *array[], char *palabraClave) {
    for (int i = 0; i < 5; i++) {
        if (strstr(array[i], palabraClave) != NULL) {
            return array[i]; 
        }
    }
    return NULL;  
}
void buscar_nombrePorId(int id, char *array[]) {
    for (int i = 0; i < 5; i++)
    {
        if (i == id)
        {
            printf("el nombre cuya id es %d es: %s\n", id, array[i]);
            return;
        }
    }
    printf("no se encontro el valor buscado");
}

void MostrarPersonas (char *array[]) {
    for (int j = 0; j < 5; j++)
    {
        printf("el nombre nro %d es = %s \n", j + 1, array[j]);
    }
}

int main () {
    char *array[5];
    char buff[50];
    for (int i = 0; i < 5; i++)
    {
        printf("\n ingrese un nombre: \n");
        scanf(" %s", buff);
        int tamCadena = strlen(buff);
        array[i] = (char *) malloc( tamCadena * sizeof(char) + 1);
        strcpy( array[i], buff);
                
    }
    MostrarPersonas(array);
    int opcion;
    printf("Opción 1 = buscar nombre por id\n");
    printf("Opción 2 = buscar nombre por palabra\n");
    printf("Escribe 1 o 2 para elegir la opción\n");
    scanf("%d", &opcion);
    if (opcion == 1) {
        int id;
        printf("ingrese la id para buscar el nombre: \n");
        scanf("%d", &id);
        buscar_nombrePorId(id,array);
    } else if (opcion == 2) {
        char palabraClave[50];
        printf("ingrese una palabra clave: \n");
        scanf(" %s", palabraClave);
        char *resultado = buscar_nombrePorPalabra(array, palabraClave);
        
        if (resultado != NULL) {
            printf("encontrado: %s\n", resultado);
        } else {
            printf("no se encontro el valor buscado");
        }
    } else {
        printf("ingreso un nro incorrecto, vuelva a intentar");
    }
    
    for (int k = 0; k < 5; k++) 
    {
        free(array[k]);
    }
    return 0;
}