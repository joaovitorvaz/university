//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T
#include <stdio.h>
#define N 7

int main()
{
  int vetor[N];
  int n;
  int r=0;

  for (int i=0; i<N; i++) {
    printf ("Insira um numero para ser armazenado: ");
    scanf ("%d", &vetor[i]);
  }

  printf ("\nDigite um numero para ser pesquisado: ");
  scanf ("%d", &n);

  for (int i=0; i<N; i++) {
    if (vetor [i] == n) {
      r+=1;
    }
  }

  if (r=1) {
    printf ("\nO numero foi encontrado!\n");
  }
  else
    printf ("\nO numero não foi encontrado!\n");

  return 0;
}
