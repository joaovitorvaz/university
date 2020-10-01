#include <stdio.h>
void ord3(int a, int b, int c);
int main()
{
  int a, b, c;
  printf("Insira 3 números diferentes: ");
  scanf ("%d %d %d", &a, &b, &c);
  ord3(a,b,c);
  return 0;
}

void ord3(int a, int b, int c)
{
  if ((a>b) && (b>c))
  {
        printf ("a= %d, b= %d c= %d", a, b, c);
  }
  else if ((a<b) && (b<c))
  {    
    printf ("a= %d, b= %d c= %d", a, b, c);
  }
}
