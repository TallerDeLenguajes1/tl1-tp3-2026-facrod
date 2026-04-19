#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for (int k = 0; k < 5; k++) 
    {
        free(array[k]);
    }

    return 0;
}