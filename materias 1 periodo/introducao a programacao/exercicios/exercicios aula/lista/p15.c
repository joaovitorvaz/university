#include <stdio.h>

void troca3(int a, int b, int c);

int main()
{
  int a, b, c;
  printf ("Insira a b c: ");
  scanf ("%d %d %d", &a, &b, &c);
  troca3(a, b, c);
  return 0;
}

void troca3(int a, int b, int c)
{
  int temp;

  temp=a;
  a=b;
  b=c;
  c=temp;
  printf ("\n%d %d %d\n", a, b, c);
}
