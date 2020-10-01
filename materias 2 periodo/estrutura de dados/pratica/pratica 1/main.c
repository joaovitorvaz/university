#include <stdio.h>
#include "Circulo.h"
#include "Ponto.h"

int main()
{
    Ponto *ponto;
    float x, y;
    scanf("%f %f", &x, &y);

    ponto=criarPt(x,y);
    acessarPt(ponto, &x, &y);
    printf ("\nPontos: %.2f %.2f", x, y);
    atribuirPt(ponto, x, y);

    Circulo *circulo;
    float raio;
    scanf("%f", &raio);

    circulo = criarCir(ponto, raio);
    printf("\n\nCalculo do circulo: %f\n", calcularCir(circulo));

    liberarCir(circulo);
    liberarPt(ponto);

    return 0;
}
