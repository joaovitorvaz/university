// Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
// Murilo de Paula Vieira Neto - 19.1.4011 - BCC201-62P

#include <stdio.h>
long long fat(int n);
int main()
{
  int n;
  long long s;
  printf("Digite o valore de n: ");
  scanf("%d", &n);
  s= fat(n);
  printf("\n%d! = %lld\n\n", n, s);
  return 0;
}

long long fat(int n)
{
  long long x=1;
  for (int i=1; i<=n; i++){
    x=x*i;
  }
  return x;
}
