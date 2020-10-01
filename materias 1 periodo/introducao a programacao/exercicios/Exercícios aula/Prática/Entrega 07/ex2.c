//Marcus Vinícius Souza Fernandes  -  19.1.4046  -  BCC201-61P
#include <stdio.h>

typedef struct {
  int numerador;
  int denominador;
} Racional;

int equal(Racional r1, Racional r2);
int mdc(int x, int y);

int main()
{
  Racional r1, r2;
  int volta;

  printf("Insira numerador e denominador de r1: ");
  scanf("%d %d", &r1.numerador, &r1.denominador);
  printf("Insira numerador e denominador de r2: ");
  scanf("%d %d", &r2.numerador, &r2.denominador);

  volta=equal(r1,r2);

  printf("\n");

  if (volta == 1){
    printf("R1 e R2 sao iguais.\n\n");
  }
  else
    printf("Os valores de r1 e r2 nao sao iguais.\n\n");

  return 0;
}

int equal(Racional r1, Racional r2){

    int mdcr1 = mdc(r1.numerador, r1.denominador);
    int mdcr2 = mdc(r2.numerador, r2.denominador);

    r2.numerador /= mdcr2;
    r1.numerador /= mdcr1;
    r2.denominador /= mdcr2;
    r1.denominador /= mdcr1;

    if(r2.numerador == r1.numerador && r2.denominador == r1.denominador) {
      return 1;
    }
    else
      return 0;
}

int mdc(int x, int y){
  int aux;

  do {
      aux = x%y;
      x=y;
      y=aux;
  } while (aux!=0);

  return x;
}
