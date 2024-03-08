#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[20];
    float notas[3];

} Aluno;

float calcularMediaAluno(Aluno aluno) {
    float media = 0.0;

    for (int i = 0; i < 3; i++) {
        media += aluno.notas[i];
    }

    return media / 3.0;
}

int quantidadeAprovados(Aluno* alunos, int n) {
    int qtdAprovados = 0;

    for (int i = 0; i < n; i++) {
        if (calcularMediaAluno(alunos[i]) >= 7.0) {
            qtdAprovados++;
        }
    }

    return qtdAprovados;
}

int ordenarVetorAlunos(Aluno* alunos, int n) {
   for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {
            
            if (calcularMediaAluno(alunos[i]) < calcularMediaAluno(alunos[j])) {

                Aluno aux = alunos[i];

                alunos[i] = alunos[j];

                alunos[j] = aux;
            }
        }
    }
}

void imprimirAluno(Aluno aluno) {
    printf("Aluno");

    printf("     Matricula: %d", aluno.matricula);

    printf("     Nome %d", aluno.nome);

    printf("     Notas: ");

    for (int i = 0; i < 3; i++) {
        printf("%.2f ", aluno.notas[i]);
    }

    printf("--------------------\n");
}

void imprimirAlunos(Aluno* aluno, int n) {
    for (int i = 0; i < n; i++) {
        imprimirAluno(aluno[i]);
    }
}

int* matriculaAlunosAprovados(Aluno* alunos, int n) {
    int *vetor = malloc((quantidadeAprovados(alunos, n) * sizeof(int)) + 1);

    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (calcularMediaAluno(alunos[i]) >= 7.0) {
            vetor[cont] = alunos[i].matricula;
            cont++;
        }
    }
    vetor[cont] = -1;

    return vetor;
}

int main() {

    // Alternativa a)

    Aluno aluno1;
    strcpy(aluno1.nome, "Jose");
    aluno1.matricula = 124;
    aluno1.notas[0] = 6.5;
    aluno1.notas[1] = 7.0;
    aluno1.notas[2] = 7.6;

    printf("Media aluno1 = %.2f \n", calcularMediaAluno(aluno1));

    // Alternativa b)

    Aluno aluno2;
    strcpy(aluno2.nome, "Maria");
    aluno2.matricula = 832;
    aluno2.notas[0] = 6.2;
    aluno2.notas[1] = 5.4;
    aluno2.notas[2] = 2.5;

    Aluno aluno3;
    strcpy(aluno3.nome, "Joao");
    aluno3.matricula = 432;
    aluno3.notas[0] = 8.6;
    aluno3.notas[1] = 7.2;
    aluno3.notas[2] = 5.2;

    Aluno alunos[3];
    alunos[0] = aluno1;
    alunos[1] = aluno2;
    alunos[2] = aluno3;

    printf("Quantidade de alunos aprovados: %d \n", 
        quantidadeAprovados(alunos, 3)
    );

    // Alternativa c)
    ordenarVetorAlunos(alunos, 3);

    imprimirAlunos(alunos, 3);

    int* temp = matriculaAlunosAprovados(alunos, 3);

    printf("%d", matriculaAlunosAprovados(alunos, 3));

    free(temp);
}

