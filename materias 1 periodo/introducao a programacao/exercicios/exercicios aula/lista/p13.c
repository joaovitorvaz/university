#include <stdio.h>
int anobi6(int ano);
int main ()
{
  int ano;
  printf ("Insira um ano: ");
  scanf ("%d", &ano);
  return anobi6(ano);

}

int anobi6(int ano)
{
  if ((ano%4 == 0) && (ano%100 != 0) || (ano%400 == 0))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
