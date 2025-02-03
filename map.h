#ifndef map_h
#define map_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ler1(double* vetor, int tam);

void imprimir1(double* par,int tam);

double quadrado(double numero);

double raiz_quadrada(double numero);

double cubo( double numero);

double* map( double *vetor, int tam, double (*funcao)(double));

#endif