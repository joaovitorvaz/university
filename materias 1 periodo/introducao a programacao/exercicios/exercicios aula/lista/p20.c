#include <stdio.h>
void imPAR(int *nmr);

int main()
{
  int *nmr;
  printf("Insira um número: ");
  scanf("%d", &nmr);
  imPAR(&nmr);
  printf("Número: %d", *nmr);
  return 0;
}

void imPAR(int *nmr)
{
  if ((nmr%2)==0)
  {
    *nmr=*nmr+5;
  }
  else
    *nmr=*nmr+8;
}
