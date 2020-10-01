//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>
#include <stdlib.h>

void tresvalores(int *n1, int *n2, int *n3);
void sorteio(int *nmaleatorio1, int *nmaleatorio2, int *nmaleatorio3);
double valorpremio(int premio, int *n1, int *n2, int *n3, int *nmaleatorio1, int *nmaleatorio2, int *nmaleatorio3);

int main ()
{
  int n1, n2, n3, nmaleatorio1, nmaleatorio2, nmaleatorio3, premio;
  tresvalores(&n1, &n2, &n3);
  sorteio(&nmaleatorio1, &nmaleatorio2, &nmaleatorio3);
  valorpremio(premio, &n1, &n2, &n3, &nmaleatorio1, &nmaleatorio2, &nmaleatorio3);

return 0;
}

void tresvalores(int *n1, int *n2, int *n3)
{
  printf("Insira 3 números de 0 a 30 por favor: ");
  scanf("%d %d %d", n1, n2, n3);
}

void sorteio(int *nmaleatorio1, int *nmaleatorio2, int *nmaleatorio3)
{
  *nmaleatorio1 = (rand()%30)+1;
  *nmaleatorio2 = (rand()%30)+1;
  *nmaleatorio3 = (rand()%30)+1;
}

double valorpremio(int premio, int *n1, int *n2, int *n3, int *nmaleatorio1, int *nmaleatorio2, int *nmaleatorio3)
{
  premio=0;
  if (nmaleatorio1 == n1 || nmaleatorio1 == n2 || nmaleatorio1 == n3)
  {
    premio=premio+1;
  }
  if (nmaleatorio2 == n1 || nmaleatorio2 == n2 || nmaleatorio2 == n3)
  {
    premio=premio+1;
  }
  if (nmaleatorio3 == n1 || nmaleatorio3 == n2 || nmaleatorio3 == n3)
  {
    premio=premio+1;
  }
  switch (premio) {
    case 3:
      printf("Seu prêmio é de R$100.000,00\n");
      break;

    case 2:
      printf("Seu prêmio é de R$1.000,00\n");
      break;

    case 1:
      printf("Seu prêmio é de R$1,00\n");
      break;

    case 0:
      printf("Seu prêmio é de R$0,0\n");
      break;
  }

}
