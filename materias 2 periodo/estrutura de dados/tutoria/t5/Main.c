#include "Lista.h"

int main(){
  int info, chave;
  int op=0;
  Lista *pilha;

  do{

    scanf("%d", &chave);

    switch (chave){
      case 1:
      {
        pilha = lst_cria();

        while(op != -1){
          scanf("%d", &info);
          scanf("%d", &op);

          //PUSH
          lst_insere(pilha, info);
        }

        printf("Pilha: ");
        lst_imprime(pilha);

        printf("\n");

        //POP
        info = lst_retira_primeiro(pilha);

        printf("\nPilha apos a primeira remocao: ");
        lst_imprime(pilha);

        //UNSTACK
        lst_libera(pilha);
      break;
      }

      case 2:
      {
        Lista* fila = lst_cria();
        op = 0;

        while(op != -1){
          scanf("%d", &info);
          scanf("%d", &op);

          lst_insere_final(fila, info);
        }

        printf("\n\nFila: ");
        lst_imprime(fila);

        printf("\n");

        inverteFila(fila);

        printf("\nFila invertida: ");
        lst_imprime(fila);

        lst_libera(fila);
      break;
      }

      case 3:
      {
        Lista *a = lst_cria();
        Lista *b = lst_cria();
        op = 0;

        while(op != -1){
          scanf("%d", &info);
          scanf("%d", &op);

          lst_insere(a, info);
        }

        op = 0;

        while(op != -1){
          scanf("%d", &info);
          scanf("%d", &op);

          lst_insere(b, info);
        }

        printf("\n\nLista A: ");
        lst_imprime(a);

        printf("\n");

        printf("\nLista B: ");
        lst_imprime(b);

        Lista *c = concatenaLista(a, b);

        printf("\n\nConcatenada: ");
        lst_imprime(c);

        printf("\n");

        lst_libera(a);
        lst_libera(b);
        lst_libera(c);
      break;
      }
    }

  }while(chave!=0);

  return 0;
}
