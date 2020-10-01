#include<stdio.h>

int main()
{
    int num, fat=1;
    scanf("%d", &num);

    for(int i=1; i<=num; i++){
      fat*=i;
    }
    printf("O fatorial de %d = %d\n", num, fat);
    return 0;
}
