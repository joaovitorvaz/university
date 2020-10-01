//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T

#include <stdio.h>
int main ()
{
  int i=0;
  float n, md;
  float som=0;
  float man=0;
  float men=1000000000;

  do {
    printf("DIGITE UMA NOTA (ou uma nota negativa para sair): ");
    scanf("%f", &n);

      if (n>=0) {
        som+=n;
        i++;
      }

      if (n>=man) {
        man=n;
      }
      if (n>=0 && n<=men) {
        men=n;
      }
  } while (n>=0);

  md=(som/i);

  printf("\nA MEDIA DAS %d NOTAS E: %f", i, md);
  printf("\nA MAIOR NOTA E: %f", man);
  printf("\nA MENOR NOTA E: %f\n", men);
  return 0;
}
