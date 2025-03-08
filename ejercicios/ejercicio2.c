#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    //solicitar valores de m y n
    printf("Ingrese el número de filas: ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &n);

    //se usa calloc para reservar espacio para la matriz
    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    //imprimir la matriz inicializada en ceros
    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }

    //modificar algunos valores del arreglo d la matriz
    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value;
    //lee los datos solicitados
    scanf("%d %d %d", &row, &col, &value); //guardar las direcciones de las variables

    //checar que las coordenadas esten en el rango de valores
    if (row >= 1 && row <= m && col >= 1 && col <=n){
        matrix[(row - 1) * n + (col - 1)] = value;
    } else {
        printf("Coordenadas no dentro del rango:\n");
    }

    //imprimir la matriz actualizada
    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) { // funcion para actualizar la matriz
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }
    //liberar la memoria reservada
    free(matrix); //free libera memoria
    return 0;
}