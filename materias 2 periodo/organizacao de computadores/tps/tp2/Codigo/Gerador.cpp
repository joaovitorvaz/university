#include<iostream>
#include<cmath>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<time.h>


#define op_min 0 //Intervalo de OPCODES -> menor OPCODE
#define op_max 1 //maior OPCODE
#define hault -1 //OPCODE que representa o final do seu programa -> A ultima instrucao do ultimo FOR contera' esse OPCODE.
#define TAM_FOR 50 //Tamanho dos blocos de instrucoes.

#define REPETICOES 100 /* (0 <= REPETICOES <= 100) Porcentagem que representa a quantidade de blocos de FOR repetidos dentro do NUM_INS.-> O mesmo bloco (FOR) aparecera' "REPETICOES(%)" da quantidade total de blocos (FORs), nao necessariamente em sequencia.*/

#define TAM_MEM 100 //Tamanho da RAM
#define NUM_INS 100 //Quantidade de instrucoes -> Maior que o TAM_FOR (vide item 2 das observacoes).
#define QUANTIDADE_DE_ENDERECOS 3 //Numero de enderecos na memoria RAM sobre os quais seu OPCODE (unico por linha) ira' atuar.
#define ENDERECO_DE_PALAVRAS 1

using namespace std;

void geraInstrucao();

int main(){
		geraInstrucao();
    return 0;
}

void geraInstrucao(){
	ofstream instrucoes;
	instrucoes.open("file.txt");
	vector< vector<int> > vetor;
	vetor.clear();
	vector<int> aux;
	aux.clear();
	srand((unsigned int)time(NULL));
	int quant_for = NUM_INS / TAM_FOR;
	int quant_repeticoes = (REPETICOES / 100.0 + 0.0001) * (quant_for);
	vector<int> sequence;
	sequence.clear();
	for (int i = 0; i < quant_for; i++)
	{
		sequence.push_back(i);
	}
	for (int i = 0; i < quant_for - quant_repeticoes; i++)
	{
		size_t tmp = rand() % quant_for;
		while (tmp >= sequence.size())
			tmp -= sequence.size();
		sequence.erase(sequence.begin() + tmp);
	}
	//Sequencia aleatoria completa
	for (int i = 0; i < TAM_FOR; i++)
	{
		aux.push_back(rand() % (op_max - op_min + 1) + op_min);
		for (int add = 0; add < QUANTIDADE_DE_ENDERECOS; add++)
		{
			aux.push_back(rand() % TAM_MEM);
			if (ENDERECO_DE_PALAVRAS != 0)
				aux.push_back(rand() % 4);
		}
		vetor.push_back(aux);
		aux.clear();
	}
	//FOR a ser repetido completo
	int tamanho = (ENDERECO_DE_PALAVRAS == 0 ? QUANTIDADE_DE_ENDERECOS + 1 : QUANTIDADE_DE_ENDERECOS * 2 + 1);
	bool end = false, same = false;
	for (int a = 0; a < quant_for; a++)
	{
		if (!end)
		{
			if (a == sequence[0])
			{
				if (a == quant_for - 1)
					vetor[TAM_FOR - 1][0] = hault;

				for (int i = 0; i < TAM_FOR; i++)
				{
					for (int j = 0; j < tamanho; j++)
					{
						instrucoes << vetor[i][j] << (j == tamanho - 1 ? "\n" : " ");
					}
				}
				if (sequence.size() > 0)
				{
					sequence.erase(sequence.begin());
					if (sequence.size() == 0)
						end = true;
				}
				same = true;
			}
		}
		if (!same)
		{
			for (int j = 0; j < TAM_FOR; j++)
			{
				if (j == TAM_FOR - 1 && a == quant_for - 1)
					instrucoes << hault;
				else
					instrucoes << rand() % (op_max - op_min + 1) + op_min;

				for (int add = 0; add < QUANTIDADE_DE_ENDERECOS; add++)
				{
					instrucoes << " " << rand() % TAM_MEM;
					if (ENDERECO_DE_PALAVRAS != 0)
						instrucoes << " " << rand() % 4;
				}
				instrucoes << "\n";
			}
		}
		same = false;
	}
	instrucoes.close();
}
