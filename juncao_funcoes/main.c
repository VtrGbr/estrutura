#include "filter.h"
#include "map.h"
#include "busca.h"

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    return (diff > 0) - (diff < 0); // Retorna 1, 0 ou -1
}


int main(){
    int tam, contagem = 0;
    double numero;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d",&tam);
    double* vetor = (double*)malloc(tam * sizeof(double));

    if( !vetor){
        printf("Falha na alocacao do vetor na main");
        exit(1);
    }

    ler(vetor,tam);

    double* filtro = filter(menor,vetor,tam,&contagem);

    printf("Vetor filtrado: \n");
    imprimir(filtro,contagem);

    double* mapaeado = map(filtro,contagem,cubo);
    printf("\nVetor mapeado: \n");
    imprimir(mapaeado,contagem);

    // Ordena o vetor antes da busca binária
    qsort(mapaeado, contagem, sizeof(double), compara);

    printf("\nDigite o numero que voce quer buscar no array: ");
    scanf("%lf",&numero);

    int posicao = busca_b(mapaeado,contagem,numero);

    if( posicao != -1){
        printf("A posicao do numero %lf no array eh %d\n",numero,posicao);
    }else{
        printf("Numero nao encontrado no array\n");
    }
    printf("\nPosicao: %d",posicao);

    return 0;
    
}