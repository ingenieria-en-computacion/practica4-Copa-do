 #include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    printf("%p\n");//falta completar
    
    arreglo = (int*)calloc(num , sizeof(int));
    if(arreglo != NULL){
        printf
        ("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d", *(arreglo + cont));            
        }
        printf("\t]\n");
        printf("Liberando el espacio reservado\n");
        free(arreglo);  
        arreglo = NULL;      
    }
    return 0;
}