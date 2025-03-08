#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    //pedir el valor de n
    printf("Ingrese el tamaño del arreglo:\n ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Error: El tamaño debe ser mayor que 0 .\n");
        return 1;
    }
    //se usa malloc para reservar memoria
    int *arreglo = (int *)malloc(n * sizeof(int));
    if (arreglo == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }


    //solicitar los valores del arreglo
    printf("ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        printf("valor %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }
    // mostrar valores del arreglo
    printf("el arreglo es: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
   
   //liberar la memoria
    free(arreglo);
    return 0;
}