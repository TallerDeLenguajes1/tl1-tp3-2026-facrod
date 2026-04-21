#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *buscar_nombre(char *array[], char *palabraClave) {
    for (int i = 0; i < 5; i++) {
        if (strstr(array[i], palabraClave) != NULL) {
            return array[i]; 
        }
    }
    return NULL;  
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
        printf("ingrese un nombre: \n");
        scanf(" %s", buff);
        int tamCadena = strlen(buff);
        array[i] = (char *) malloc( tamCadena * sizeof(char) + 1);
        strcpy( array[i], buff);
                
    }
    MostrarPersonas(array);

    char palabraClave[50];
    printf("ingrese una palabra clave: \n");
    scanf(" %s", palabraClave);
    char *resultado = buscar_nombre(array, palabraClave);
    
    if (resultado != NULL) {
        printf("encontrado: %s\n", resultado);
    } else {
        printf("no se encontro el valor buscado");
    }

    
    for (int k = 0; k < 5; k++) 
    {
        free(array[k]);
    }

    return 0;
}