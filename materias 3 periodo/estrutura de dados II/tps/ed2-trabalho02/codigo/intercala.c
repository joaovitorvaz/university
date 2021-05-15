#include "intercala.h"

struct fita {
    FILE* arquivo;
    int qtdBlocos;
    int* numReg; // Ponteiro que armazena a quantidade de registros em cada bloco
};

struct heap {
    Aluno registro;
    double marcado; // A marcação em questão é somar um valor grande à nota do aluno
};

// Função que inicializa o metodo de ordenação 1
void intercalaInterno(FILE* arq, int tamanho, Analise* a) {
    Fita fitasE[FITAS];
    Fita fitasS[FITAS];
    Aluno registros[REG];

    // Inicializando as variaveis com tudo vazio
    inicializaFitas(fitasE, fitasS);

    criaBlocosInterno(arq, fitasE, registros, tamanho, a);

    // A variavel op é responsável por determinar se será utilizado as fitas geradas inicialmente (op = 1) ou as fitas geradas pela função de intercalação (op = 0)
    // Fitas de 1 a 20 (op = 1), fitas de 21 a 40 (op = 0)
    int op = 1, continua = 1;
    while(continua) {
        continua = iniciaInterlacao(fitasE, fitasS, registros, op, a);
        op = op == 1 ? 0 : 1;
    }

    fclose(arq);
}

// Função que inicializa o metodo de ordenação 2
void intercalaExterno(FILE* arq, int tamanho, Analise* a) {
    Fita fitasE[FITAS];
    Fita fitasS[FITAS];
    Aluno registros[REG];

    // Inicializando as variaveis com tudo vazio
    inicializaFitas(fitasE, fitasS);

    criaBlocosExterno(arq, fitasE, tamanho, a);

    // A variavel op é responsável por determinar se será utilizado as fitas geradas inicialmente (op = 1) ou as fitas geradas pela função de intercalação (op = 0)
    // Fitas de 1 a 20 (op = 1), fitas de 21 a 40 (op = 0)
    int op = 1, continua = 1;
    while(continua) {
        continua = iniciaInterlacao(fitasE, fitasS, registros, op, a);
        op = op == 1 ? 0 : 1;
    }
}

// Gera as fitas de entrada para o metodo 1
void criaBlocosInterno(FILE* arq, Fita* fitas, Aluno* registros, int tamanho, Analise* a) {
    // Garantindo que tenha a quantidade de fitas certas
    int qtdFitas = tamanho % REG != 0 ? (tamanho / REG) + 1 : tamanho / REG;
    int countReg = 0;
    int count = 0;
    char nomeArq[20];
    Aluno aluno;

    while(count < qtdFitas) {
        // Lendo os registros do arquivo
        while(!feof(arq) && countReg < REG) {
            contTransferenciaLeitura(a);
            fread(&registros[countReg], sizeof(Aluno), 1, arq);
            countReg++;
        }

        // Garantindo que o numero de fitas não ultrapasse a quantidade estabelecida na constante FITAS, nomeando o arquivo e o criando 
        if(count < FITAS) {
            sprintf(nomeArq, "fita-%d.bin", count + 1);
            fitas[count % FITAS].arquivo = fopen(nomeArq, "w+b");
        }

        else {
            sprintf(nomeArq, "fita-%d.bin", (count % FITAS) + 1);
            fseek(fitas[count % FITAS].arquivo, 0, SEEK_END);
        }

        quickSort(registros, 0, countReg - 1, a);

        for(int i = 0; i < countReg; i++)
            contTransferenciaEscrita(a);

        // Escrevendo o vetor ordenado
        fwrite(registros, sizeof(Aluno), countReg, fitas[count % FITAS].arquivo);

        fitas[count % FITAS].qtdBlocos++;

        // Faz a criação de um vetor para cada bloco presente dentro das fitas
        int* aux = malloc((count / FITAS + 1) * sizeof(int));

        // Garante que a variavel aux tenha o tamanho correto de blocos presente em cada fita
        // Atribui a quantidade de registros para cada posição da variavel aux e aponta numReg para aux
        if((count / FITAS + 1) == 1) {
            aux[0] = countReg;
            fitas[count % FITAS].numReg = aux;
        }

        else {
            // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
            for(int i = 0; i < count / FITAS; i++)
                aux[i] = fitas[count % FITAS].numReg[i];

            aux[count / FITAS] = countReg;
            fitas[count % FITAS].numReg = aux;
        }

        count++;
        countReg = 0;
    }
}
// Gera as fitas de entrada para o metodo 2
void criaBlocosExterno(FILE* arq, Fita* fitas, int tamanho, Analise* a) {
    int count = 0, countReg = 0, reg = 0, length = tamanho * 2; // Garante que length seja um valor grande para ser usado como marcação
    char nomeArq[20];
    Heap regHeap[REG];

    // Faz a leitura dos primeiros registros para o vetor interno
    for(int i = 0; i < REG; i++) {
        contTransferenciaLeitura(a);
        fread(&regHeap[i].registro, sizeof(Aluno), 1, arq);
        regHeap[i].marcado = regHeap[i].registro.nota;
    }

    while(tamanho != 0) {
        // Realiza o Heap dos registros
        heapSort(regHeap, REG - reg, a);

        // Garantindo que o numero de fitas não ultrapasse a quantidade estabelecida na constante FITAS, nomeando o arquivo e o criando 
        if(count < FITAS && fitas[count % FITAS].arquivo == NULL) {
            sprintf(nomeArq, "fita-%d.bin", count + 1);
            fitas[count % FITAS].arquivo = fopen(nomeArq, "w+b");
        }

        else {
            sprintf(nomeArq, "fita-%d.bin", (count % FITAS) + 1);
            fseek(fitas[count % FITAS].arquivo, 0, SEEK_END);
        }

        // Verifica se o vetor esta todo marcado
        if(isTudoMarcado(regHeap, length, reg)) {
            desmarcaTudo(regHeap, length, reg);
            fitas[count % FITAS].qtdBlocos++;

            // Faz a criação de um vetor para cada bloco presente dentro das fitas
            int* aux = malloc((count / FITAS + 1) * sizeof(int));

            // Garante que a variavel aux tenha o tamanho correto de blocos presente em cada fita
            // Atribui a quantidade de registros para cada posição da variavel aux e aponta numReg para aux
            if((count / FITAS + 1) == 1) {
                aux[0] = countReg;
                fitas[count % FITAS].numReg = aux;
            }

            else {
                // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
                for(int i = 0; i < count / FITAS; i++)
                    aux[i] = fitas[count % FITAS].numReg[i];

                aux[count / FITAS] = countReg;
                fitas[count % FITAS].numReg = aux;
            }

            count++;
            countReg = 0;
        }

        else {
            // Pega o menor registro do vetor regHeap
            Heap old = regHeap[0];

            // Escreve o valor na fita
            contTransferenciaEscrita(a);
            fwrite(&old.registro, sizeof(Aluno), 1, fitas[count % FITAS].arquivo);
            countReg++;

            // Garantindo que não haja leitura desnecessária
            if(tamanho - REG > 0) {
                contTransferenciaLeitura(a);
                fread(&regHeap[0].registro, sizeof(Aluno), 1, arq);

                contComparacao(a);
                // A marcação utilizada é aumentando o valor inicial da nota em um valor arbitrário
                if(regHeap[0].registro.nota < old.registro.nota)
                    regHeap[0].marcado = regHeap[0].registro.nota + length;

                else
                    regHeap[0].marcado = regHeap[0].registro.nota;
            }

            // Manipula os registros restantes que estão dentro do vetor regHeap
            else {
                // Pega o ultimo registro e joga ele para a primeira posição
                old = regHeap[REG - reg - 1];
                regHeap[0] = old;
                reg++;
            }

            tamanho--;
        }
    }

    fitas[count % FITAS].qtdBlocos++;

    // Garante que a quantidade de registros restantes seja armazenada na fita

    // Faz a criação de um vetor para cada bloco presente dentro das fitas
    int* aux = malloc((count / FITAS + 1) * sizeof(int));

    // Garante que a variavel aux tenha o tamanho correto de blocos presente em cada fita
    // Atribui a quantidade de registros para cada posição da variavel aux e aponta numReg para aux
    if((count / FITAS + 1) == 1) {
        aux[0] = countReg;
        fitas[count % FITAS].numReg = aux;
    }

    else {
        // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
        for(int i = 0; i < count / FITAS; i++)
            aux[i] = fitas[count % FITAS].numReg[i];

        // Insere na ultima posição
        aux[count / FITAS] = countReg;
        fitas[count % FITAS].numReg = aux;
    }
}

// Função que alterna as fitas de entrada pelas fitas de saida e vice versa
int iniciaInterlacao(Fita* fitasE, Fita* fitasS, Aluno* registro, int op, Analise* a) {
    // Fitas de 1 a FITAS, no caso de 1 a 20
    if(op == 1)
        return intercala(fitasE, fitasS, registro, op, a);

    // Fitas de FITAS + 1 a FITAS * 2, no caso de 21 a 40
    else
        return intercala(fitasS, fitasE, registro, op, a);
}

// Função principal de intercalação. retorna 0 caso a intercalação tenha terminado e 1 caso contrário
int intercala(Fita* fitasE, Fita* fitasS, Aluno* registro, int op, Analise* a) {
    int numFitas = 0;
    char nomeArq[20];
    int fitaSelecionada = op == 1 ? 1 : (FITAS + 1); // Determina a fita final gerada apos toda intercalação
    int fitaResultante = op == 1 ? (FITAS + 1) : 1; // Determina o numero da fita gerada pelo metodo
    int length = 0;

    // Confere o numero de fitas validás
    numFitas = getFitasDisponiveis(fitasE);

    // Arquivo totalmente ordenado e sendo renomeado
    if(numFitas == 1) {
        sprintf(nomeArq, "fita-%d.bin", fitaSelecionada);
        rename(nomeArq, "resultado.bin");

        // Fecha todos os arquivos
        for(int i = 0; i < FITAS; i++) {
            if(fitasE[i].arquivo != NULL)
                fclose(fitasE[i].arquivo);

            if(fitasS[i].arquivo != NULL)
                fclose(fitasS[i].arquivo);
        }

        // Exclui todos os outros arquivos
        for(int i = 0; i < FITAS * 2; i++) {
            sprintf(nomeArq, "fita-%d.bin", i + 1);
            remove(nomeArq);
        }

        return 0;
    }

    // Move o ponteiro de todos os arquivos que serão utilizados para o inicio
    for(int i = 0; i < numFitas; i++)
        fseek(fitasE[i].arquivo, 0, SEEK_SET);

    // Cria um vetor com o numero maximo de fitas que sera utilizado
    int* count = malloc(numFitas * sizeof(int));
    int posicao, continua, index = 0;
    int* aux;
    Aluno menor;

    while(numFitas != 0) {
        // Atribui ao contador o numero de registros disponível em cada arquivo
        for(int i = 0; i < numFitas; i++)
            count[i] = fitasE[i].numReg[index];

        // Faz a leitura do primeiro item de cada bloco
        for(int i = 0; i < numFitas; i++) {
            contTransferenciaLeitura(a);
            fread(&registro[i], sizeof(Aluno), 1, fitasE[i].arquivo);
            count[i]--;
        }

        continua = 1;
        sprintf(nomeArq, "fita-%d.bin", fitaResultante);
        // Cria a fita quando não existe as fitas de saida
        if(fitasS[(fitaResultante - 1) % FITAS].arquivo == NULL)
            fitasS[(fitaResultante - 1) % FITAS].arquivo = fopen(nomeArq, "w+b");

        // Apenas continua
        else if(fitasS[(fitaResultante - 1) % FITAS].arquivo != NULL && fitasS[(fitaResultante - 1) % FITAS].qtdBlocos != 0)
            continua = 1;

        // Move o ponteiro para o inicio do arquivo quando as fitas de saida já se encontram criadas
        else
            fseek(fitasS[(fitaResultante - 1) % FITAS].arquivo, 0, SEEK_SET);

        // Verifica se tem ou não blocos nas fitas
        if(length / FITAS == 0) {
            // Faz a alocação do vetor aux
            aux = malloc((length / FITAS + 1) * sizeof(int));
            // Caso não tenha blocos, o aux simplesmente recebe 0 e o numReg é apontado para ele
            aux[0] = 0;
            fitasS[(fitaResultante - 1) % FITAS].numReg = aux;
        }

        else {
            aux = malloc((length / FITAS + 1) * sizeof(int));
            for(int i = 0; i < length / FITAS; i++)
                aux[i] = fitasS[(fitaResultante - 1) % FITAS].numReg[i];

            // Caso tenha blocos na fita, o aux copia tudo o que está no numReg, atribui 0 para a ultima posição do aux e numReg é apontado para ele
            aux[length / FITAS] = 0;
            fitasS[(fitaResultante - 1) % FITAS].numReg = aux;
        }

        while(continua) {
            menor.nota = RAND_MAX;
            posicao = -1;

            // Procura qual é a menor nota presente no vetor registro, guardando ele e sua posição
            for(int i = 0; i < numFitas; i++) {
                contComparacao(a);
                if(registro[i].nota <= menor.nota && count[i] >= 0) {
                    menor = registro[i];
                    posicao = i;
                }
            }

            // Realiza a escrita do registro na fita de saida e le um novo registro da fita de entrada
            contTransferenciaEscrita(a);
            fwrite(&menor, sizeof(Aluno), 1, fitasS[(fitaResultante - 1) % FITAS].arquivo);
            fitasS[(fitaResultante - 1) % FITAS].numReg[length / FITAS]++;

            // Lê apenas a quantidade de registros presente no bloco
            if(count[posicao] > 0) {
                contTransferenciaLeitura(a);
                fread(&registro[posicao], sizeof(Aluno), 1, fitasE[posicao].arquivo);
            }

            count[posicao]--;

            // Confere se os registros de todos os blocos foram lidos
            continua = isContinua(count, numFitas);
        }

        for(int i = 0; i < numFitas; i++)
            fitasE[i].qtdBlocos--;

        fitasS[(fitaResultante - 1) % FITAS].qtdBlocos++;

        numFitas = getFitasDisponiveis(fitasE);
        fitaResultante++;
        index++;
        length++;
    }

    free(count);

    return 1;
}

// Função que ordena o vetor de alunos por um quickSort
void quickSort(Aluno* vetor, int esquerda, int direita, Analise* a) {
    int i, j;
    Aluno x, y;

    i = esquerda;
    j = direita;
    x = vetor[(esquerda + direita) / 2];

    while(i <= j) {
        contComparacao(a);
        while(vetor[i].nota < x.nota && i < direita) {
            contComparacao(a);
            i++;
        }

        contComparacao(a);
        while(vetor[j].nota > x.nota && j > esquerda) {
            contComparacao(a);
            j--;
        }

        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if(j > esquerda) {
        quickSort(vetor, esquerda, j, a);
    }
    if(i < direita) {
        quickSort(vetor, i, direita, a);
    }
}

// Função que ordena o vetor de alunos por um heapSort
void heapSort(Heap* vetor, int n, Analise* a) {
    int i = n / 2, pai, filho;
    Heap temp;

    while(true) {
        if(i > 0) {
            i--;
            temp = vetor[i];
        }

        else {
            n--;
            if(n <= 0) return;
            temp = vetor[n];
            vetor[n] = vetor[0];
        }

        pai = i;
        filho = i * 2 + 1;
        while(filho < n) {
            contComparacao(a);
            if((filho + 1 < n) && (vetor[filho + 1].marcado > vetor[filho].marcado))
                filho++;

            contComparacao(a);
            if(vetor[filho].marcado > temp.marcado) {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }

            else {
                break;
            }
        }
        vetor[pai] = temp;
    }
}

// Função que inicializa as fitas
void inicializaFitas(Fita* fitasE, Fita* fitasS) {
    for(int i = 0; i < FITAS; i++) {
        fitasE[i].arquivo = NULL;
        fitasE[i].qtdBlocos = 0;
        fitasE[i].numReg = NULL;
        fitasS[i].arquivo = NULL;
        fitasS[i].qtdBlocos = 0;
        fitasS[i].numReg = NULL;
    }
}

// Função que retorna a quantidade de fitas disponíveis
int getFitasDisponiveis(Fita* fitas) {
    int numFitas = 0;

    for(int i = 0; i < FITAS; i++) {
        if(fitas[i].qtdBlocos != 0)
            numFitas++;

        else
            break;
    }

    return numFitas;
}

// Função que verifica se todo o bloco foi lido, retornando 0 caso a condição seja verdadeira e 1 caso seja falsa
int isContinua(int* count, int numFitas) {
    int continua = 0;

    for(int i = 0; i < numFitas; i++) {
        if(count[i] < 0)
            continua++;
    }

    if(continua == numFitas)
        return 0;

    else
        return 1;
}

// Função que verifica se todos os registros do vetor foram marcados
bool isTudoMarcado(Heap* vetor, int tamanho, int reg) {
    for(int i = 0; i < REG - reg; i++) {
        if(vetor[i].marcado <= tamanho / 2)
            return false;
    }

    return true;
}

// Função que desmarcar todos os registros do vetor
void desmarcaTudo(Heap* vetor, int tamanho, int reg) {
    for(int i = 0; i < REG - reg; i++)
        vetor[i].marcado -= tamanho;
}