#include "busca.h"

int busca_b(double *vetor, int tam, double numero) {
    int inicio = 0;
    int fim = tam - 1;
    int meio;
    const double epsilon = 1e-9; // Define a tolerância

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (fabs(vetor[meio] - numero) < epsilon) {
            return meio; // Considera como igual
        } else if (vetor[meio] < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Número não encontrado
}