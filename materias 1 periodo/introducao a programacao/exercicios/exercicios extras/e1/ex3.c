//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T

#include <stdio.h>
#include <math.h>
int main ()
{
  int i;
  float x, n;
  float soma= 0;
  double md=0;

  printf("DIGITE O VALOR DE N: ");
  scanf("%f", &n);
  printf("\n");

  for (i=1; i<=n; i++) {
    printf("DIGITE O VALOR DE X%d: ", i);
    scanf("%f", &x);
    soma+=pow(x,2);
  }
  md=sqrt(soma/n);
  printf("\nMEDIA QUADRATICA: %lf\n", md);

  return 0;
}
