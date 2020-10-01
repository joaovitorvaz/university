#include <stdio.h>
#include <stdlib.h>

#include "Aluno.h"
#include "Disciplina.h"
#include "Atestado.h"

#define T 100

int main()
{
    char nomeAluno[T], NomeDisc[T], curso[T], codigo[T], data[11], renameDisciplina[T];
    int matricula, sala, hmax;
    double carga, cpf;

    scanf("%s %lf %d %s %s", nomeAluno, &cpf, &matricula, curso, data);

    Aluno* aluno = criarAluno(nomeAluno, cpf, matricula, curso, data);
    Disciplina** disc = malloc(4 * sizeof (Disciplina*));
    for (int i = 0; i < 4; i++){
        scanf("%s %s %lf %s %d", NomeDisc, codigo, &carga, curso, &sala);
        disc[i] = criardisciplina(NomeDisc, codigo, carga, curso, sala);
    }
    Atestado* atestado = criarAtestado(aluno, disc, hmax);

    imprimeAtestado(atestado);

    apagaAtestado(atestado, hmax);

    return 0;
}
