#include "map.h"

void ler(double* vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("vetor[%d]: ",i);
        scanf("%lf",&vetor[i]);
    }

}

void imprimir(double* par,int tam){
    for(int i = 0; i < tam; i++){
        printf("%.2lf ",par[i]);
    }
}

double quadrado(double numero){
    return numero * numero;
}

double raiz_quadrada(double numero){
    return sqrt(numero);
}

double cubo( double numero){
    return pow(numero,3);
}

double* map( double *vetor, int tam, double (*funcao)(double)){
    double* temp = (double*)malloc(tam * sizeof(double));

    if( !temp){
        printf("Erro na alocacao de memoria do vetor, na funcao map\n");
        exit(1);
    }

    for( int i = 0; i < tam; i++){
        temp[i] = (*funcao)(vetor[i]);
    }

    return temp;
}