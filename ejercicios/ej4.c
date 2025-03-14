#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char nombre[40];
    int edad;
} Estudiante;
int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    Estudiante *estudiantes = (Estudiante *)malloc(size * sizeof(Estudiante));

    // Si el arreglo es nulo imprime el mensaje
    if (estudiantes == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    
    printf("Ingresa nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0)break;
        printf("edad: ");
        scanf("%d", &edad);
        if (count >= size) {
            size *= 2;
        // Cambia el tamaño del arreglo
            estudiantes = (Estudiante *)realloc(estudiantes, size * sizeof(Estudiante));
            // Verifica nuevamente que si apunta a nulo se imprima el error
            if (estudiantes == NULL) {
                printf("No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        // Copia el nombre leido en el nuevo estudiante y su edad
        strncpy(estudiantes[count].nombre, nombre, 40);
        estudiantes[count].edad = edad;
        count++;
    }
    printf("list de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("nombre: %s, edad: %d\n", estudiantes[i].nombre, estudiantes[i].edad);
    }
    // Libera la memoria
    free(estudiantes);
    return 0;
}
