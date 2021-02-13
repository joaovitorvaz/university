#include <stdio.h>
#define IMOUPAR(x) x%2;
int main()
{
  int x, r;
  printf ("Insira um número: ");
  scanf ("%d", &x);
  r= IMOUPAR(x);
  if (r==0)
  {
    printf ("\nO número é par!!!");
  }
  else
    printf ("\nO número é ímpar.");
}
