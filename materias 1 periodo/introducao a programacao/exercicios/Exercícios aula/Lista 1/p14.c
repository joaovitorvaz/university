#include <stdio.h>
#include <stdlib.h>

void aposta(int *rand1, int *rand2, int *rs);

int main()
{
  int a1, a2, ap, *rand1, *rand2, rs;
  printf ("Faça sua aposta para cada um dos dois dados: ");
  scanf ("%d %d", &a1, &a2);
  ap= a1+a2;

  aposta(&rand1, &rand2, &rs);

  printf ("\nSua aposta foi: %d", ap);
  printf ("\nOs números sorteados foram: %d e %d", rand1, rand2);
  printf ("\nA soma do campeão é: %d", rs);

  if (ap==rs)
  {
    printf ("\n\nParabéns você acertou!");
  }
  else
    printf ("\n\nInfelizmente você perder.");

  return 0;
}

void aposta(int *rand1, int *rand2, int *rs)
{
  srand(time(NULL));
  *rand1= (rand()%6)+1;
  *rand2= (rand()%6)+1;
  *rs= *rand1 + *rand2;
}
