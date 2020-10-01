//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T
#include <stdio.h>
#define A 15
#define P1 15
#define P2 15
#define N 15

int main ()
{
  float vetorP1[P1];
  float vetorP2[P2];

  for (int i=0; i<A; i++) {
    printf ("\nInsira a nota p1 do aluno %d: ", i+1);
    scanf ("%f", &vetorP1[i]);
    printf ("Insira a nota p2 do aluno %d: ", i+1);
    scanf ("%f", &vetorP2[i]);
  }

  printf("\n");

  for (int i=0; i<A; i++) {
    if (((vetorP1[i]+vetorP2[i])/2)>=60) {
      printf ("\nO aluno %d foi aprovado.", i+1);
    }
    else
      printf ("\nO aluno %d foi reprovado.", i+1);
  }

  printf ("\n\n");

  return 0;
}
