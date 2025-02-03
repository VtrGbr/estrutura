#include "filter.h"
//--------------------------Funcoes para serem chamadas pela funcao genericas -----------------------------
int paridade(int numero){
    return (numero % 2 == 0)? 0: 1;
}

int impar(int numero){
    return (numero % 2 != 0) ? 0: 1;
}

double menor(double numero){
    return (numero < 20)? 0 : 1;
}

void ler(int* vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("vetor[%d]: ",i);
        scanf("%d",&vetor[i]);
    }

}

void imprimir(int* par,int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ",par[i]);
    }
}

double* filter(double (*filtro)(double), int *vetor, int tam, int *contagem) {
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
    int* par = (int*)realloc(temp, (*contagem) * sizeof(int));
    if (!par) {
        printf("Erro ao realocar memória.\n");
        free(temp);
        exit(1);
    }

    return par;
}


int main(){
    int tam;
    int contagem = 0;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d",&tam);

    int* vetor= (int*)malloc(tam * sizeof(int));

    ler(vetor,tam);

    int* par = filter(paridade, vetor,tam,&contagem);

    printf("vetor par: ");
    imprimir(par,contagem);

    contagem = 0;
    
    int *imparidade = filter(impar,vetor,tam,&contagem);
    printf("vetor impar: ");
    imprimir(imparidade,contagem);


    free(par);
    free(vetor);
    free(imparidade);
    return 0;
}