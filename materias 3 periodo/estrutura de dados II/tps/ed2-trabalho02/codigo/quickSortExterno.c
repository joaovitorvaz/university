#include "tp2.h"
#include "quickSortExterno.h"

//Método principal do QuickSort Externo
void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, Analise *a){
    int i,j;

    //Area de armazenamento interna
    Aluno *Area;
    Area = malloc(TAMAREA * sizeof(Aluno));

    if (Dir - Esq < 1)
        return;
        
    FAVazia(Area, a);
    Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j, a);
    fflush(*ArqLi);
    fflush(*ArqEi);
    fflush(*ArqLEs);

    //Ordena primeiro o subarquivo menor
    if( i - Esq < Dir - j ){
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, a);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, a);
    }
    else{
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, a);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, a);
    }

    free(Area);
}

void LeSup(FILE **ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer, Analise *a){
    fseek(*ArqLEs, (*Ls-1)*sizeof(Aluno), SEEK_SET);
    contTransferenciaLeitura(a);
	fread(UltLido, sizeof(Aluno), 1, *ArqLEs);
    (*Ls)--;
    *OndeLer = FALSE;
}

void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer, Analise *a){
    contTransferenciaLeitura(a);
    fread(UltLido, sizeof(Aluno), 1, *ArqLi);
    (*Li)++; 
    *OndeLer = TRUE;
}

void InserirArea(Aluno *Area, Aluno *UltLido, int *NRArea, Analise *a){
    //Insere UltLido de forma ordenada na Area
    InsereItem(*UltLido, Area, a);
    *NRArea = ObterNumCelOcupadas(Area, a);
}

void EscreveMax(FILE **ArqLEs, Aluno R, int *Es, Analise *a){
    fseek(*ArqLEs, (*Es-1)*sizeof(Aluno), SEEK_SET);
    contTransferenciaEscrita(a);
	fwrite(&R, sizeof(Aluno), 1, *ArqLEs);
    (*Es)--;
}

void EscreveMin(FILE **ArqEi, Aluno R, int *Ei, Analise *a){
    contTransferenciaEscrita(a);
    fwrite(&R, sizeof(Aluno), 1, *ArqEi);
    (*Ei)++;
}

void RetiraMax(Aluno *Area, Aluno *R, int *NRArea, Analise *a){
    RetiraUltimo(Area, R, a);
    *NRArea = ObterNumCelOcupadas(Area, a);
}

void RetiraMin(Aluno *Area, Aluno *R, int *NRArea, Analise *a){
    RetiraPrimeiro(Area, R, a);
    *NRArea = ObterNumCelOcupadas(Area, a);  
}

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, Aluno* Area, int Esq, int Dir, int *i, int *j, Analise *a){
    int Ls = Dir;
    int Es = Dir;
    int Li = Esq;
    int Ei = Esq;
    int NRArea = 0;
    double Linf = INT_MIN;
    double Lsup = INT_MAX;

    short OndeLer = TRUE;

    //Aluno UltLido;
    Aluno R;

    fseek(*ArqLi, (Li-1)*sizeof(Aluno), SEEK_SET);
	fseek(*ArqEi, (Ei-1)*sizeof(Aluno), SEEK_SET);

    *i = Esq - 1;
    *j = Dir + 1;

    while(Ls >= Li){
        Aluno UltLido;
        
        if(NRArea < TAMAREA - 1){

            if(OndeLer){
                LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, a);
            }
            else{
                LeInf(ArqLi, &UltLido, &Li, &OndeLer, a);
            }

            InserirArea(Area, &UltLido, &NRArea, a);

            continue;
        }

        if(Ls == Es){
            LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, a);
        }
        else if(Li == Ei){
            LeInf(ArqLi, &UltLido, &Li, &OndeLer, a);
        }
        else if(OndeLer){
            LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, a);        
        }
        else{
            LeInf(ArqLi, &UltLido, &Li, &OndeLer, a);
        }

        contComparacao(a);
        if(UltLido.nota > Lsup){
            *j = Es;
            EscreveMax(ArqLEs, UltLido, &Es, a);
            continue;
        }

        contComparacao(a);
        if(UltLido.nota < Linf){
            *i = Ei;
            EscreveMin(ArqEi, UltLido, &Ei, a);
            continue;
        }

        InserirArea(Area, &UltLido, &NRArea, a);

        if(Ei - Esq < Dir - Es){
            RetiraMin(Area, &R, &NRArea, a);
            EscreveMin(ArqEi, R, &Ei, a);
            Linf = R.nota;
        }
        else{
            RetiraMax(Area, &R, &NRArea, a);
            EscreveMax(ArqLEs, R, &Es, a);
            Lsup = R.nota;
        }
    }

    while(Ei <= Es){
        RetiraMin(Area, &R, &NRArea, a);
        EscreveMin(ArqEi, R, &Ei, a);
    }
}

//Cria uma Área vazia
void FAVazia(Aluno *Area, Analise *a){
    //Preenchendo a área com células vazias
    for(int i=0; i<TAMAREA; i++){
        Area[i].inscricao = -1;
        Area[i].nota = -1.0;
        strcpy(Area[i].estado,"XX");
        strcpy(Area[i].cidade,"XX");
        strcpy(Area[i].curso,"XX");
    }
}

//Insere um Aluno ordenadamente na Área
void InsereItem(Aluno UltLido, Aluno *Area, Analise *a){
    int i = 0;
    int j = 18, k = 19;

    //Achando a posição correta na área
    contComparacao(a);
    contComparacao(a);
    while(Area[i].nota < UltLido.nota && Area[i].inscricao != -1 && i < TAMAREA){
        contComparacao(a);
        contComparacao(a);
        i++;
    }
    
    //Reorganizando a área
    while(j >= i){
        Area[k] = Area[j];
        j--;
        k--;
    }
    
    //Posição recebe o aluno a ser inserido
    Area[i] = UltLido;
}

//Retorna o número de células ocupadas na Área
int ObterNumCelOcupadas(Aluno *Area, Analise *a){
    int cont = 0;

    //Conta até achar uma posição vazia ou até o fim da área
    contComparacao(a);
    while(Area[cont].inscricao != -1 && cont < TAMAREA){
        contComparacao(a);
        cont++;
    }

    return cont;
}

//Retira o ultimo Aluno presente na Área
void RetiraUltimo(Aluno *Area, Aluno *R, Analise *a){
    int cont = 0;

    //Achando a última posição válida da área
    contComparacao(a);
    while(Area[cont].inscricao != -1 && cont < TAMAREA){
        contComparacao(a);
        cont++;
    }

    cont--; //Achar o último aluno válido, antes da primeira posição vazia (aluno com inscrição -1)

    //R recebe o último aluno
    *R = Area[cont];

    //Esta última posição se torna vazia
    Area[cont].inscricao = -1;
    Area[cont].nota = -1.0;
    strcpy(Area[cont].estado,"XX");
    strcpy(Area[cont].cidade,"XX");
    strcpy(Area[cont].curso,"XX");
}

//Retira o primeiro Aluno presente na Área
void RetiraPrimeiro(Aluno *Area, Aluno *R, Analise *a){
    int i = 0, j = 1;

    //R recebe o primeiro elemento da área
    *R = Area[0];

    //Reorganizando a área
    contComparacao(a);
    while(Area[j].inscricao != -1 && i < TAMAREA-1){
        contComparacao(a);
        Area[i] = Area[j];
        i++;
        j++;
    }

    //Criando uma posição vazia no último elemento
    Area[i].inscricao = -1;
    Area[i].nota = -1.0;
    strcpy(Area[i].estado,"XX");
    strcpy(Area[i].cidade,"XX");
    strcpy(Area[i].curso,"XX");
}

//Função que imprime a área
void imprimirArea(Aluno *Area){
    printf("===== Área =====\n");
    for(int i = 0 ; i < TAMAREA ; i++){
        imprimeAluno(Area[i]);
    }
    printf("\n");
}