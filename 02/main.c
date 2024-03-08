#include <stdio.h> 
#include <math.h>

void popularVetor(int n, int* vetor) {
    printf("Popule o vetor: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
} 

int calcularDegrau(int n, int* vetor) {
    int maiorDegrau = 0;

    for (int i = 0; i < n-1; i++) {
        int degrau = 0;

        if (vetor[i] > vetor[i+1]) 
            degrau = vetor[i] - vetor[i+1];
        else 
            degrau = vetor[i+1] - vetor[i];

        printf("O degrau do par %d e %d tem altura %d \n", vetor[i], vetor[i+1], degrau);

        if (degrau > maiorDegrau) 
            maiorDegrau = degrau;
    }

    return maiorDegrau;
}

int main() {

    int n = 0;

    do {
        printf("Digite o tamanho do vetor (o tamanho deve ser maior que 1): ");

        scanf("%d", &n);
    } while (n < 2);
    
    int vetor[n];

    popularVetor(n, vetor);

    int maiorDegrau = calcularDegrau(n, vetor);

    printf("O maior degrau e: %d", maiorDegrau);

    return 0;
}