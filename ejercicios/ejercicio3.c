#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 2; //asigna un número pequeño
    int *arr; // reserva memoria con malloc
    arr = (int *)malloc(size * sizeof(int)); // Se corrige la asignación de memoria
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese números (ingrese -1 para terminar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) { // rompe el ciclo
            break;
        }

        if (count >= size) { //uso de realloc 
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int)); // utiliza realloc para cambiar el tamaño del arreglo
            if (arr == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        arr[count++] = num;
    }

    printf("La lista es: ");
    for (int i = 0; i < count; i++) { //esta funcion imprime la lista
        printf("%d ", arr[i]); 
    }
    printf("\n");

    // libera la memoria
    free(arr);
    return 0;
}