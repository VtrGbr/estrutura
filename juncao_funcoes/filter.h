#ifndef filter_h
#define filter_h
#include <stdio.h>
#include <stdlib.h>

//Funcao para filtrar um array
double* filter(double (*filtro)(double), double *vetor, int tam, int *contagem);

//Retorna se um numero eh menor que 20
double menor(double numero);


#endif