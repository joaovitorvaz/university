//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T
#include <stdio.h>
#define S 10

int main ()
{
  int vetor[S];

  for (int i=0; i<S; i++) {
    if (i<2) {
      vetor[i]=1;
    }
    else
      vetor[i]=vetor[i-1]+vetor[i-2];
  }

  printf ("\n");

  for (int i=0; i<S; i++) {
    printf ("N%d e igual: %d", i+1, vetor[i]);
    printf ("\n");
  }
  return 0;
}
