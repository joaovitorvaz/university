#include <stdio.h>
int main()
{
  int num=10;
    printf("\n%d", num);
  int *ptr=&num;
    printf("\n%d", *ptr);
  int *ptr2=*&ptr;
    printf("\n%d", *ptr2);
  *ptr=100;
    printf("\n%d", num);
  *ptr2=101;
    printf("\n%d", num);
  return 0;
}
