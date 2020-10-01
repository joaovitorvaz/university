#include "Times.h"
#include "Fila.h"
#include "No.h"
#include "Quadrado.h"
#include "Losango.h"
#include "Trapezio.h"
#include "Pilha.h"
#include "Operacoes.h"

int main(){

  int chave, q=0;

  do{

    scanf("%d", &chave);

    switch(chave){
      case 1:{

        printf("Questao (1):\n\n");

        Pilha* pilha=criarPilha();
        verificarPilha(pilha);
        insereObj(pilha);
        insereObj(pilha);
        insereObj(pilha);
        insereObj(pilha);
        pilhaPop(pilha);
        area(pilha);
        printf("\n");
        liberarPilha(pilha);

      }
      break;

      case 2:{

        if(q!=0){}
        else{
          printf("Questao (2):\n");
        }

        int clubes, njogos;
        scanf("%d", &clubes);
        scanf("%d", &njogos);
        Time *time=CriaTimes(clubes);
        Jogos(time, clubes, njogos);
        AtualizarCampos(time, clubes);
        MergeOrdena(time, 0, clubes-1);
        PrintarTime(time, clubes);
        LiberaTimes(time);
        printf("\n");
        q++;

      }
      break;

      case 3:{

        printf("Questao (3):\n\n");

        Fila* fila=CriaFila();
        int n;
        scanf("%d", &n);
        fila_inserefinal(fila, n);
        scanf("%d", &n);
        fila_inserefinal(fila, n);
        fila_retiraprim(fila);
        scanf("%d", &n);
        fila_inserefinal(fila, n);
        fila_imprime(fila);
        LiberaFila(fila);

      }
      break;
    }
  }while(chave!=0);

  return 0;
}
