#include"Republica.h"

struct republica{
	char nome[100];
	Morador* morador[T];
	Tarefa* tarefa[T];
	Afazer* afazeres[T];
};

Republica *criaRep(char* nome){
	Republica* rep = malloc(sizeof(Republica));
	strcpy(rep->nome,nome);

	return rep;
}

void delRep(Republica* rep){
	free(rep);
}

void setMoradorR(Republica* rep, Morador* morador, int nMorador){
	rep->morador[nMorador]=morador;
}

void setTarefaR(Republica* rep, Tarefa* tarefa, int nTarefa){
	rep->tarefa[nTarefa]=tarefa;
}

void setAfazeresR(Republica* rep, Afazer* afazeres, int nAfazeres){
	rep->afazeres[nAfazeres]=afazeres;
}

Morador** getMoradorR(Republica* rep){
	return rep->morador;
}

Morador* getMoradorEspecR(Republica* rep, int pos){
	return rep->morador[pos];
}

Tarefa** getTarefasR(Republica* rep){
	return rep->tarefa;
}

Tarefa* getTarefasEspecR(Republica* rep, int pos){
	return rep->tarefa[pos];
}

Afazer** getAfazeresR(Republica* rep){
	return rep->afazeres;
}

Afazer* getAfazeresEspecR(Republica* rep, int pos){
	return rep->afazeres[pos];
}

void ImprimeNomeMorador(Republica* rep, int pos){
	printf("%s\n", getNomeMorador(rep->morador[pos]));
}

void ImprimeDescTarefa(Republica* rep, int pos){
	printf("%s\n", getNomeTarefa(rep->tarefa[pos]));
}

void ImprimeAfazerR(Republica* rep, int pos){
	imprimeAfazer(rep->afazeres[pos]);
}
