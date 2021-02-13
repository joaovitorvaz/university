//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61T

#include <stdio.h>
int main ()
{
  int i;
  int n;
  int fat=1;

  printf("DIGITE O VALOR DE N: ");
  scanf ("%d", &n);

  for (i=1; i<n; i++) {
    fat+=(fat*i);
  }

  printf("%d! = %d\n", n, fat);
  return 0;
}
