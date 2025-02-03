#ifndef filter_h
#define filter_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


double paridade(int numero);

double menor(double numero);

void ler(int* vetor, int tam);

void imprimir(int* par,int tam);

double* filter(double (*filtro)(double),double *vetor,int tam,int* contagem);

#endif