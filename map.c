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

int main(){
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    double* vetor = (double*)malloc(tam * sizeof(double));

    if( !vetor){
        printf("Erro na alocacao do vetor, na funcao main");
        exit(1);
    }

    ler(vetor,tam);

    double* final = map(vetor,tam,quadrado);
    printf("Quadrado dos valores: \n");
    imprimir(final,tam);

    final = map(vetor,tam,raiz_quadrada);
    printf("Raiz quadrada: \n");
    imprimir(final,tam);
    
    final = map(vetor,tam,cubo);
    printf("Raiz quadrada: \n");
    imprimir(final,tam);
    
    
    free(final);
    free(vetor);
    return 0;
}