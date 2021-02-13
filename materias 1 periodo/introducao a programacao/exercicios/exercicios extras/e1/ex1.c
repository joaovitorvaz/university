//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T

#include <stdio.h>
int main ()
{
  int xp=0;
  int xn=0;
  float n=0;

  do {
    printf("DIGITE UM NUMERO REAL (PARAR=0): ");
    scanf ("%f", &n);
      if (n>0) {
        xp++;
      }
      else if (n<0) {
        xn++;
      }
  } while (n!=0);

  printf("\nQUANTIDADE DE POSITIVOS DIGITADOS: %d", xp);
  printf("\nQUANTIDADE DE NEGATIVOS DIGITADOS: %d\n", xn);

  return 0;
}
