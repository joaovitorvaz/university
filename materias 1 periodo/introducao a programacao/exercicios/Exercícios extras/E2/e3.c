//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T
#include <stdio.h>
#define V 50

int main ()
{
  int vetor[V];
  int c;

  for (int i=0; i<V; i++) {
    printf ("Insira um numero: ");
    scanf ("%d", &vetor[i]);
  }

  printf("\n");

  for (int i=0; i<V; i++) {
    c=0;
    do {
      printf ("*");
      c+=1;
    } while (c != vetor[i]);
    printf ("\n");
  }
  return 0;
}
