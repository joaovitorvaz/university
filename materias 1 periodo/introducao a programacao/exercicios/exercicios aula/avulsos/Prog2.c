/*Marcus vinícius Souza Fernandes  -  19.1.40.46 -  BCC201-61P*/
#include <stdio.h>
#include <math.h>
int calculaRaizes(float delta, float *raiz1, float *raiz2, float a, float b, float c);
int main()
{
  float a, b, c, delta, raiz1, raiz2;
  printf ("\nInsira as raízes da equação na ordem a b c: ");
  scanf("%f %f %f", &a, &b, &c);
  calculaRaizes(delta, &raiz1, &raiz2, a, b, c);
  printf("\nO valor das raízes são: %.2f  e  %.2f\n\n", raiz1, raiz2);
  return 0;
}

int calculaRaizes(float delta, float *raiz1, float *raiz2, float a, float b, float c)
{

  delta=(pow(b,2)-4*a*c);
  *raiz1= ((-b)+sqrt(delta))/(2*a);
  *raiz2= ((-b)-sqrt(delta))/(2*a);

  if (delta>=0) {
    return 1;
  }
  else
    return 0;
}
