#include <stdlib.h>
#include <math.h>

#include "Circulo.h"

struct circulo {
    Ponto *centro;
    float raio;
};

Circulo* criarCir(Ponto *ponto, float raio){
    Circulo *circulo=malloc(sizeof(Circulo));
    circulo->centro = ponto;
    circulo->raio = raio;
    return circulo;
}
void liberarCir(Circulo *circulo){
    free(circulo->centro);
    free(circulo);
}
float calcularCir(Circulo *circulo){
    return 3.1415 * pow(circulo->raio, 2);
}
