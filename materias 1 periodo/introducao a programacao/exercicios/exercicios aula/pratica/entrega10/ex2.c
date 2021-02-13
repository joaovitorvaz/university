//Marcus Vinícius Souza Fernandes  -  19.1.4046  -  BCC201-61P
#include <stdio.h>
#include <string.h>
#define M 99

int main()
{
  char palavra[M];
  char fim[] = "FIM";
  int r = 1;
  int cont, i;
  int j = 0;

  do {
    printf("Digite uma palavra ou FIM para sair: ");
    scanf("%s", palavra);

    cont = strlen(palavra);

    if (strcmp(fim,palavra) == 0) {
      r=0;
    }

    else {
      for(i = 0; i < strlen(palavra); i++){
        if(palavra[i] != palavra[cont-1-i]){
          printf("\nA palavra %s nao e um palindromo.\n\n", palavra);
          break;
        }
        else
          printf("\nA palavra %s e um palindromo.\n\n", palavra);
          break;
      }
    }
  } while(r!=0);

  return 0;
}
