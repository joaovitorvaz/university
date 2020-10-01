// Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
// Murilo de Paula Vieira Neto - 19.1.4011 - BCC201-62P

#include <stdio.h>
int ehPrimo(int n);
int main ()
{
  int n;
  float s;
  printf("Digite um numero: ");
  scanf("%d", &n);
  s= ehPrimo(n);
    if (s==2) {
      printf("\n%d e um numero primo!\n\n", n);
    }
    else
      printf("\n%d nao e um numero primo!\n\n", n);
  return 0;
}

int ehPrimo(int n)
{
  int x=0;

  for(int i=1; i<=n; i++) {
      if (n%i==0 && n!=2){
        x=x+1;
      }
  }
  if (x==2){
    return 2;
  }
  else
    return 1;
}
