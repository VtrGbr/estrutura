#include "filter.h"

double* filter(double (*filtro)(double), double *vetor, int tam, int *contagem) {
    double* temp = (double*)malloc(tam * sizeof(double));
    if (!temp) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    *contagem = 0;
    for (int i = 0; i < tam; i++) {
        if ((*filtro)(vetor[i]) == 0) {
            temp[*contagem] = vetor[i];
            (*contagem)++;
        }
    }

    // Ajustando o tamanho do vetor filtrado
    double* par = (double*)realloc(temp, (*contagem) * sizeof(double));
    if (!par) {
        printf("Erro ao realocar memória.\n");
        free(temp);
        exit(1);
    }

    return par;
}

double menor(double numero){
    return (numero < 20)? 0 : 1;
}