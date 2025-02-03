#ifndef filter_h
#define filter_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double paridade(int numero);

void ler(int* vetor, int tam);

void imprimir(int* par,int tam);

double* filter(double (*filtro)(double),int *vetor,int tam,int* contagem);

#endif