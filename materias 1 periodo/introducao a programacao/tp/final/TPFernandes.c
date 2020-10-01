//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 30

typedef struct
{
    //Dimensões da matriz.
    int linhas;
    int colunas;

    //Variaveis Laterais.
    int *termosnalateral;
    int **matrizlateral;
    int **matrizlateralprovisoria;
    int maiornumLateral;

    //Variaveis Superiores.
    int *termosnasuperior;
    int **matrizsuperior;
    int **matrizsuperiorprovisoria;
    int maiornumSuperior;

    //Matriz do nonograma.
    char **nonograma;

    //Matriz para formatar a impressão do cabeçalho superior.
    char **matrizpartesuperior;

    //Variável para comando.
    char comando[T];
    int tamstring;
    int verificacomando;

    //Variável para salvar.
    char salvarcomo[T];
    int habilitasave;

    //Variável para receber retorno da função resolver.
    int recebefuncaoretorno;

} Jogo;

//Lê o arquivo e aloca os dados dinamicamente em matrizes.
void LerArquivOeAlocarDinamicamente(Jogo *jogo, char *argv[]);
//Encontra o maior indice da matriz lateral e superior.
void FormandoMatrizesRegulares(Jogo *jogo, char *argv[]);
//Criando uma matriz invisível para dar simetria na impressão do programa.
void FormatarMatrizSuperior(Jogo *jogo);
//Printa o jogo.
void PrintarNonograma(Jogo *jogo);
//Mudar o nome do comando para não gerar interferência.
void RenomearComando(Jogo *jogo);
//Editar o conteúdo da matriz do nonograma.
void MarcaJogada(Jogo *jogo);
//Verificar se o usuário resolveu.
int VerificarseTerminou(Jogo *jogo);
//Salva o jogo.
void SalvarGame(Jogo *jogo);
//Resolve o nonograma (ou tenta).
void Resolver(Jogo *jogo);
//Liber toda a memória restante usada.
void LiberarAMemoria(Jogo *jogo);

int main(int argc, char *argv[])
{
    //Alocando jogo dinamicamente.
    Jogo *jogo = malloc(sizeof(Jogo));

    //Chamndo funções.
    LerArquivOeAlocarDinamicamente(jogo, argv);
    FormandoMatrizesRegulares(jogo, argv);
    FormatarMatrizSuperior(jogo);

    printf("Bem vindo ao nonograma.\n");

    do
    {
        jogo->verificacomando=0;
        jogo->habilitasave=0;

        //Imprimindo os comandos para o usuário.
        printf("\n");
        printf("    x       - Preenche a celula com o caracter                         \n");
        printf("    -       - Preenche a celula com o caracter                         \n");
        printf("    .       - Limpa a celula e a preenche com o caracter               \n");
        printf(" resolver   - Resolve o nonograma.                                     \n");
        printf(" salvar     - Salva o nonograma.                                       \n");
        printf(" sair       - Encerra o nonograma sem salvar.                          \n\n");

        //Aviso.
        printf(" Insira os comandos identicos ao exemplo acima.");
        printf("\n\n Em caso de preencher posicao, insira letras MAIUSCULAS.");
        printf("\n Exemplo: x AB");
        printf("\n\n");

        jogo->recebefuncaoretorno=VerificarseTerminou(jogo);

        //Printando o nonograma.
        PrintarNonograma(jogo);
        printf("\n");

        //Pedindo um comando.
        do
        {
            if(jogo->recebefuncaoretorno==1)
            {
                printf("Voce finalizou o nonograma.\n");
                break;
            }

            printf("Insira um comando: ");
            fgets(jogo->comando, T, stdin);

            //Removendo o /0.
            jogo->comando[(strlen(jogo->comando)-1)] = '\0';

            //Lendo tamanho da string.
            jogo->tamstring=(strlen(jogo->comando));

            if((jogo->comando[0]=='s') && (jogo->comando[1]=='a') && (jogo->comando[2]=='l') && (jogo->comando[3]=='v') && (jogo->comando[4]=='a') && (jogo->comando[5]=='r') && (jogo->comando[6]==' '))
            {
                jogo->habilitasave=1;

                for(int i=7; i-7<jogo->tamstring-7; i++)
                {
                    jogo->salvarcomo[i-7]=jogo->comando[i];
                }
            }

            else if((jogo->comando[0]=='x') || (jogo->comando[0]=='-') || (jogo->comando[0]=='.'))
            {
                if((jogo->comando[1]==' '))
                {
                    if(((jogo->comando[2]>64) && (jogo->comando[2]<65+jogo->linhas)))
                    {
                        if(((jogo->comando[3]>64) && (jogo->comando[3]<65+jogo->colunas)))
                        {
                            jogo->verificacomando=1;
                            if(jogo->tamstring>4)
                            {
                                jogo->verificacomando=0;
                                RenomearComando(jogo);
                                printf("Comando invalido.\n");
                            }
                        }
                        else
                        {
                            RenomearComando(jogo);
                            printf("Comando invalido.\n");
                        }

                    }
                    else
                    {
                        RenomearComando(jogo);
                        printf("Comando invalido.\n");
                    }
                }
                else
                {
                    RenomearComando(jogo);
                    printf("Comando invalido.\n");
                }
            }
            else if((strcmp(jogo->comando, "resolver")==0))
            {
                Resolver(jogo);
            }

            else if((strcmp(jogo->comando, "sair")==0)) {}

            else
            {
                RenomearComando(jogo);
                printf("Comando invalido.\n");
            }
        }

        while(((strcmp(jogo->comando, "sair")!=0) && (jogo->habilitasave==0) && (jogo->verificacomando==0)));

        MarcaJogada(jogo);

        if(jogo->recebefuncaoretorno==1)
        {
            printf("Saindo do game...\n");
            break;
        }

        if(jogo->habilitasave==1)
        {
            SalvarGame(jogo);
        }

    }
    while((strcmp(jogo->comando, "sair")!=0));

    LiberarAMemoria(jogo);

    return 0;
}

void LerArquivOeAlocarDinamicamente(Jogo *jogo, char *argv[])
{
    jogo->maiornumLateral=0;
    jogo->maiornumSuperior=0;

    FILE *file = fopen (argv[1], "r");

    fscanf (file, "%d %d", &jogo->linhas, &jogo->colunas);

    //Realizando a alocação dinâmica para as matrizes e vetores.
    jogo->termosnalateral=malloc(jogo->linhas * sizeof(int));
    jogo->termosnasuperior=malloc(jogo->colunas * sizeof(int));
    jogo->matrizlateralprovisoria=malloc(jogo->linhas * sizeof(int*));
    jogo->matrizsuperiorprovisoria=malloc(jogo->colunas * sizeof(int*));

    jogo->nonograma=malloc(jogo->linhas * sizeof(char*));
    for(int i=0; i<jogo->linhas; i++)
    {
        jogo->nonograma[i]=malloc(jogo->colunas * sizeof(char));
    }

    //Alocando e lendo para matriz lateral.
    for(int i=0; i<jogo->linhas; i++)
    {
        fscanf (file, "%d", &jogo->termosnalateral[i]);
        jogo->matrizlateralprovisoria[i]=malloc(jogo->termosnalateral[i] * sizeof(int));
        for(int j=0; j<jogo->termosnalateral[i]; j++)
        {
            fscanf (file, "%d", &jogo->matrizlateralprovisoria[i][j]);
        }
        if(jogo->termosnalateral[i]>jogo->maiornumLateral)
        {
            jogo->maiornumLateral=jogo->termosnalateral[i];
        }
    }
    //Alocando e lendo para matriz superior.
    for(int i=0; i<jogo->colunas; i++)
    {
        fscanf (file, "%d", &jogo->termosnasuperior[i]);
        jogo->matrizsuperiorprovisoria[i]=malloc(jogo->termosnasuperior[i] * sizeof(int));
        for(int j=0; j<jogo->termosnasuperior[i]; j++)
        {
            fscanf (file, "%d", &jogo->matrizsuperiorprovisoria[i][j]);
        }
        if(jogo->termosnasuperior[i]>jogo->maiornumSuperior)
        {
            jogo->maiornumSuperior=jogo->termosnasuperior[i];
        }
    }
    //Lendo dados para o conteúdo do nonograma.
    for(int i=0; i<jogo->linhas; i++)
    {
        for(int j=0; j<jogo->colunas; j++)
        {
            fscanf (file, "%c", &jogo->nonograma[i][j]);
            if((jogo->nonograma[i][j]!='x') && (jogo->nonograma[i][j]!='-') && (jogo->nonograma[i][j]!='.'))
            {
                j--;
            }
        }
    }
    fclose(file);
}

void FormandoMatrizesRegulares(Jogo *jogo, char *argv[])
{

    int aux;

    FILE *file = fopen (argv[1], "r");

    fscanf (file, "%d %d", &jogo->linhas, &jogo->colunas);

    jogo->matrizlateral=malloc(jogo->linhas * sizeof(int*));
    jogo->matrizsuperior=malloc(jogo->colunas * sizeof(int*));

    //Alocando e lendo para matriz lateral.
    for(int i=0; i<jogo->linhas; i++)
    {
        fscanf (file, "%d", &jogo->termosnalateral[i]);
        jogo->matrizlateral[i]=malloc(jogo->maiornumLateral * sizeof(int));
        aux=jogo->maiornumLateral;
        for(int j=0; j<jogo->maiornumLateral; j++)
        {
            if(aux>jogo->termosnalateral[i])
            {
                jogo->matrizlateral[i][j]=0;
                aux--;
            }
            else
                fscanf (file, "%d", &jogo->matrizlateral[i][j]);
        }
    }

    //Alocando e lendo para matriz superior.
    for(int i=0; i<jogo->colunas; i++)
    {
        fscanf (file, "%d", &jogo->termosnasuperior[i]);
        jogo->matrizsuperior[i]=malloc(jogo->maiornumSuperior * sizeof(int));
        aux=jogo->maiornumSuperior;
        for(int j=0; j<jogo->maiornumSuperior; j++)
        {
            if(aux>jogo->termosnasuperior[i])
            {
                jogo->matrizsuperior[i][j]=0;
                aux--;
            }
            else
                fscanf (file, "%d", &jogo->matrizsuperior[i][j]);
        }
    }
    fclose(file);
}

void FormatarMatrizSuperior(Jogo *jogo)
{

    //Criando e preenchendo a matriz com o layout do cabeçalho superior.
    jogo->matrizpartesuperior = malloc (jogo->maiornumSuperior * sizeof(int*));
    for(int i=0; i<jogo->maiornumSuperior; i++)
    {
        jogo->matrizpartesuperior[i] = malloc ((jogo->maiornumLateral+jogo->colunas + 1) * sizeof(int));
        for(int j=0; j<jogo->maiornumLateral+jogo->colunas+1; j++)
        {
            if(j<=jogo->maiornumLateral)
            {
                jogo->matrizpartesuperior[i][j] = 0;
            }
            else
            {
                jogo->matrizpartesuperior[i][j] = jogo->matrizsuperior[j-jogo->maiornumLateral-1][i];
            }
        }
    }
}

void PrintarNonograma(Jogo *jogo)
{

    for(int i=0; i<jogo->maiornumSuperior; i++)
    {
        for(int j=0; j<jogo->maiornumLateral+jogo->colunas+1; j++)
        {
            if(jogo->matrizpartesuperior[i][j] == 0)
            {
                printf("%-3c", ' ');
            }
            else
            {
                printf("%-3d", jogo->matrizpartesuperior[i][j]);
            }
        }
        printf("\n");
    }

    for(int i=0; i<jogo->maiornumLateral+jogo->colunas+1; i++)
    {
        if (i<=jogo->maiornumLateral)
        {
            printf("%-3c", ' ');
        }
        else
        {
            printf("%-3c", (65+(i-(jogo->maiornumLateral+1))));
        }
    }
    printf("\n");

    for(int i=0; i<jogo->linhas; i++)
    {
        for(int j=0; j<jogo->maiornumLateral+jogo->colunas+1; j++)
        {
            if (j<jogo->maiornumLateral)
            {
                if (jogo->matrizlateral[i][j] == 0)
                {
                    printf("%-3c", ' ');
                }
                else
                {
                    printf("%-3d", jogo->matrizlateral[i][j]);
                }
            }
            else if (j == jogo->maiornumLateral)
            {
                printf("%-3c", (65 + i));
            }
            else
            {
                printf("%-3c", jogo->nonograma[i][j-(jogo->maiornumLateral+1)]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void RenomearComando(Jogo *jogo)
{
    for(int i=0; i<T; i++)
    {
        jogo->comando[i]=-1;
    }
}

void MarcaJogada(Jogo *jogo)
{
    //Caso as condições de acordo com a ASCII forem verdadeiras, substituir o conteúdo do nonograma pelo caracter da posição [0] da string.
    for(int i=0; i< jogo->linhas; i++)
    {
        for(int j=0; j<jogo->colunas; j++)
        {
            if((jogo->comando[2]-65==i) && (jogo->comando[3]-65==j))
            {
                jogo->nonograma[i][j]=jogo->comando[0];
            }
        }
    }
}

int VerificarseTerminou(Jogo *jogo)
{
    int contLinha;
    int somLinha;
    int contColuna;
    int somColuna;

    int totalnaslinhas=0;
    int totalnascolunas=0;

    for (int i=0; i<jogo->linhas; i++)
    {
        somLinha=0;
        contLinha=0;
        somColuna=0;
        contColuna=0;

        for (int j=0; j<jogo->termosnalateral[i]; j++)
        {
            somLinha+=jogo->matrizlateralprovisoria[i][j];
        }

        for (int j=0; j<jogo->colunas; j++)
        {
            if (jogo->nonograma[i][j]=='x')
            {
                contLinha++;
            }
        }
        if (somLinha-contLinha == 0)
        {
            totalnaslinhas++;
        }

        for (int j=0; j<jogo->termosnasuperior[i]; j++)
        {
            somColuna+=jogo->matrizsuperiorprovisoria[i][j];
        }
        for (int j=0; j<jogo->linhas; j++)
        {
            if (jogo->nonograma[j][i]=='x')
            {
                contColuna++;
            }
        }

        if (somColuna-contColuna == 0)
        {
            totalnascolunas++;
        }
    }

    if((totalnaslinhas==jogo->linhas) && (totalnascolunas==jogo->colunas))
    {
        return 1;

    }
    else
    {
        return 0;
    }

}

void SalvarGame(Jogo *jogo)
{

    FILE * finalizar=fopen(jogo->salvarcomo, "w");

    fprintf(finalizar, "%d %d", jogo->linhas, jogo->colunas);
    fprintf(finalizar, "\n");
    fprintf(finalizar, "\n");

    for (int i=0; i<jogo->linhas; i++)
    {
        fprintf(finalizar, "%-2d", jogo->termosnalateral[i]);
        for (int j = 0; j < jogo->termosnalateral[i]; j++)
        {
            fprintf(finalizar, "%-2d", jogo->matrizlateralprovisoria[i][j]);
        }
        fprintf(finalizar, "\n");
    }

    fprintf(finalizar, "\n");

    for (int i=0; i<jogo->colunas; i++)
    {
        fprintf(finalizar, "%-2d", jogo->termosnasuperior[i]);
        for (int j=0; j<jogo->termosnasuperior[i]; j++)
        {
            fprintf(finalizar, "%-2d", jogo->matrizsuperiorprovisoria[i][j]);
        }
        fprintf(finalizar, "\n");
    }

    for (int i=0; i<jogo->linhas; i++)
    {
        fprintf(finalizar, "\n");
        for (int j=0; j<jogo->colunas; j++)
        {
            fprintf(finalizar, "%-2c", jogo->nonograma[i][j]);
        }
    }

    fclose (finalizar);

    printf("Arquivo salvo.\n");
}

void Resolver(Jogo *jogo)
{
    printf("Devido a muitos erros, a mesma ainda não foi implementada com sucesso.\n\n");
}

void LiberarAMemoria(Jogo *jogo)
{

    //Desalocando matriz lateral.
    for(int i=0; i<jogo->linhas; i++)
    {
        free(jogo->matrizlateral[i]);
    }
    free(jogo->matrizlateral);

    //Desalocando matriz superior.
    for(int i=0; i<jogo->colunas; i++)
    {
        free(jogo->matrizsuperior[i]);
    }
    free(jogo->matrizsuperior);

    //Desalocando matriz da parte superior completa.
    for(int i=0; i<jogo->maiornumSuperior; i++)
    {
        free(jogo->matrizpartesuperior[i]);
    }
    free(jogo->matrizpartesuperior);

    //Desalocando nonograma.
    for(int i=0; i<jogo->linhas; i++)
    {
        free(jogo->nonograma[i]);
    }
    free(jogo->nonograma);

    //Desalocando vetor número de termos na matriz lateral.
    free(jogo->termosnalateral);

    //Desalocando vetor número de termos na matriz lateral.
    free(jogo->termosnasuperior);

    //Desalocando a matriz lateral feita provisóriamente.
    for(int i=0; i<jogo->linhas; i++)
    {
        free(jogo->matrizlateralprovisoria[i]);
    }
    free(jogo->matrizlateralprovisoria);

    //Desalocando a matriz superior feita provisóriamente.
    for(int i=0; i<jogo->colunas; i++)
    {
        free(jogo->matrizsuperiorprovisoria[i]);
    }
    free(jogo->matrizsuperiorprovisoria);

    //Liberando Jogo jogo.
    free(jogo);
}
