#include <stdio.h>
#include <math.h>

double funcintdec(double *n);
int main ()
{
  double n;
  printf("Insira um número: ");
  scanf("%lf", &n);
  funcintdec(&n);
  return 0;
}

double funcintdec(double *n)
{
    int x;
    double y;
    x= trunc(*n);
    y= *n-x;
    printf("\nO número inteiro é: %d", x);
    printf("\nO número decimal é: %lf", y);
}
