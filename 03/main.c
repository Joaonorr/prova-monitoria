#include <stdio.h>

void popularMatriz(int n, int* matriz, float* vetorMedia) {

    for (int i = 0; i < n; i++) {

        int acumulador = 0;

        printf("Digite a linha %d: ", i+1);

        for (int j = 0; j < n; j++) {

            int valor = 0;

            scanf("%d", &valor);

            matriz[(i * n) + j] = valor;

            acumulador += valor;

        }

        vetorMedia[i] = acumulador/ (float) n;
    }
} 

void mostrarMatriz(int n, int* matriz) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("\t%d", matriz[(i * n) + j]);
        }

        printf("\n");
    }
}

void mostrarVetor(int n, float* vetor) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", vetor[i]);
    }

    printf("\n");
}

int main() {
    int n = 0;

    printf("Digite o tamanho da matriz quadratica: ");

    scanf("%d", &n);
    
    int matriz[n][n];

    float vetorMedia[n];

    popularMatriz(n, matriz[0], vetorMedia);

    mostrarMatriz(n, matriz[0]);

    mostrarVetor(n, vetorMedia);

    return 0;    
}