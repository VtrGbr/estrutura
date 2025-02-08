#ifndef filtro2_h
#define filtro2_h
#define TAM 10

#include <stdio.h>
#include <stdlib.h>

double* filter(double (*filtro)(double), double *vetor, int tam, int *contagem);

double menor(double numero);

#endif