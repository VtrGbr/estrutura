#include "filtro2.h"
#include "map.h"

int main(){
    int contagem = 0;
    double* vetor = (double*)malloc(TAM * sizeof(double));
    if( !vetor){
        printf("Erro na alocacao do vetor, na funcao main");
        exit(1);
    }

    ler1(vetor,TAM);

    double* filtro = filter(menor,vetor,TAM,&contagem);

    printf("Valores menores que 20: \n");
    imprimir1(filtro,TAM);

    double* mapeado = map(filtro,contagem,quadrado);
    printf("Quadrado do filtro: \n");
    imprimir1(mapeado,contagem);

    free(filtro);
    free(vetor);
    free(mapeado);
    return 0;
}