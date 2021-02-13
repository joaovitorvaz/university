//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>

void valorxy(int x,int y, float r);

int main()
{
  int x, y, r;
  printf ("Preencha um valor para x e y: ");
  scanf ("%d %d", &x, &y);
  valorxy(x, y, r);
return 0;
}

void valorxy(int x,int y, float r)
{
  printf("\nValor de x: %d", x);
  printf("\nValor de x: %d", y);
  if (x>0 && y>0)
  {
    r=x+y;
    printf ("\nResultado é %f", r);
  }
  if (x>=0 && y<0)
  {
    r=x+(y*y);
    printf ("\nResultado é %f", r);
  }
  if (x<0 && y>=0)
  {
    r=(x*x)+y;
    printf ("\nResultado é %f", r);
  }
  if (x<0 && y<0)
  {
    r=(x*x)+(y*y);
    printf ("\nResultado é %f\n", r);
  }

}
