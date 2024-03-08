#include <stdio.h>

#define TRUE 1
#define FALSE 0

void popularVetor(int n, int* vetor) {
    printf("Popule o vetor: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
} 

void ordenarVetor(int n, int* vetor) {
   for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {
            
            if (vetor[i] > vetor[j]) {

                int aux = vetor[i];

                vetor[i] = vetor[j];

                vetor[j] = aux;
            }
        }
    }
}

void contarRepetidos(int n, int *vetor) {
    int contador = 1;

    for (int i = 0; i < n; i++) {
        if (vetor[i] == vetor[i+1]) {
            contador++;
        }
        else {
            printf("Numero %d, Quantidade %d \n", vetor[i], contador);

            contador = 1;
        }
    }
}

int main() {

    int n = 0;

    printf("Digite o tamanho do vetor: ");

    scanf("%d", &n);
    
    int vetor[n];

    popularVetor(n, vetor);

    ordenarVetor(n, vetor); 

    contarRepetidos(n, vetor);

    return 0;
}