/*

Devido a nossa falha de não prestar atenção no enunciado fizemos uma interaçãoc om usuário bem simples para que o trabalho pudesse ser adequado
ao que foi pedido. 
Portanto é possível interagir com o banco através ads consultas SELECT, UPDATE e DELETE.
Vários dados já foram inseridos no banco pelo script, as operações estáticas comentadas em baixo do menu de interação trabalham com esses dados
previamente inseridos.
Para evitar problemas com as querys estáticas está sendo criado uma instância de Pessoa com cpf='444.444.444-44' e nome='Gusttavo Lima' para que
as querys possam ser feitas nessa instância.
Devido ao tempo não foi possível implementar o insert pois seria necessário fazer uma verificação de todos os atributos de cada tabela.

Seguem abaixo um exemplo para executar as 3 querys sobre essa instância gerada inicialmente:

Operação 1 (SELECT){
    Digite a tabela primaria do item desejado: Pessoa
    Digite a condição para a consulta do item desejado: cpf='444.444.444-44'
}

Operação 2 (UPDATE){
    Digite a tabela que deseja alterar: Pessoa
    Digite a chave primaria do item desejado: '444.444.444-44'
    Digite o atributo que deseja alterar: nome
    Digite o novo valor do atributo: 'Nivaldo Batista Lima'
}

Operação 3 (DELETE){
    Digite a tabela da qual deseja excluir um item: Pessoa
    Digite a condição para a consulta desejado: cpf='444.444.444-44'
}

Para compilar e executar o programa digite no terminal{
    > g++ -o main -I /usr/include/postgresql/ main.cpp -L /usr/lib/ -lpq
    > ./main
}

Por fim, existem duas partes no código, a com interação e a estática. Para executar uma delas comente a outra.
OBS: o tamanho das querys estão limitadas a 200 caracteres.

*/

#include <iostream>
#include <string.h>
#include "libpq-fe.h" // Lib necessária

using namespace std;


// CRUD
void CREATE(PGconn *conn, const char* query);
void READ(PGconn *conn, const char* query);
void UPDATE(PGconn *conn, const char* query);
void DELETE(PGconn *conn, const char* query);

int main()
{
    // Declara uma variavel logica que representara o banco de dados
    PGconn *conn = NULL;
    // Cria uma conexao com um banco do PostgreSQL
    conn = PQconnectdb ("host=localhost port=5432 dbname=postgres user=postgres password=marcusv77");

    // Verifica a conexao feita
    if (PQstatus(conn) != CONNECTION_OK){
        // Retorna uma mensagem de erro do PostgreSQL
        cout << PQerrorMessage(conn);
        
        // Encerra a conexao com o banco de dados
        PQfinish(conn);
        return 1;
    }
    else cout << "Conexao executada com sucesso!" << endl;

    // Apagando a instância criada na execução anterior
    try
    {
        DELETE(conn, "delete from Pessoa where cpf='444.444.444-44';");
    }
    catch(const std::exception& e)
    {}
    

    // Inserindo a nova instância
    cout << "\nCriando uma pessoa com CPF = a 444.444.444-44 e nome = a Gusttavo Lima." << endl;
    CREATE(conn, "insert into Pessoa values ('444.444.444-44', 'Gusttavo Lima');");
    
    char table[30], atribute[30], value[30], pk[30], condition[30];
    int option;
    char query[200];


    // PARTE 1 - INTERACAO COM O USUÁRIO
    do{
        cout << endl;
        cout << "Selecione a opcao que deseja realizar:"<<endl;
        cout << "1 - Consulta"<<endl;
        cout << "2 - Atualizacao"<<endl;
        cout << "3 - Exclusao"<<endl;
        cout << "4 - Sair"<<endl <<endl <<"Digite o comando: ";
        
        cin >> option;
        cout << endl;
        
        switch(option) {
            case 1:
                cout << "Digite a tabela primaria do item desejado: ";
                cin >> table;
                cout << "Digite a condição para a consulta do item desejado: ";
                cin >> condition;

                strcpy(query, "SELECT * FROM ");
                strcat(query, table);
                strcat(query, " WHERE ");
                strcat(query, condition);
                strcat(query, ";");
                READ(conn, query);
                
                break;
            case 2:
                cout << "Digite a tabela que deseja alterar: ";
                cin >> table;
                cout << "Digite a chave primaria do item desejado: ";
                cin >> pk;
                cout << "Digite o atributo que deseja alterar: ";
                cin >> atribute;
                cout << "Digite o novo valor do atributo: ";
                cin >> value;
                
                strcpy(query, "UPDATE ");
                strcat(query, table);
                strcat(query, " SET ");
                strcat(query, atribute);
                strcat(query,"=");
                strcat(query, value);
                strcat(query," WHERE cpf=");
                strcat(query, pk);
                strcat(query, ";");
                 
                UPDATE(conn, query);

                break;
            case 3:
                cout << "Digite a tabela da qual deseja excluir um item: ";
                cin >> table;
                cout << "Digite a condição para a consulta desejado: ";
                cin >> condition;

                strcpy(query, "DELETE FROM ");
                strcat(query, table);
                strcat(query, " WHERE ");
                strcat(query, condition);
                strcat(query, ";");

                DELETE(conn, query);
                
                break;
            default:
                cout << "Encerrando o programa..." << endl;
                option = 4;
        }
    } while(option != 4);

    //PARTE 2 - QUERYS ESTÁTICAS
    
    // // Realizando a consulta Número 01
    // cout << "Consultando se há um jogo com valor <= a R$15.00." << endl;
    // READ(conn, "select Acessivel.nome from Jogo as Acessivel where valor<=15.00;");

    // // Realizando a consulta Número 02
    // cout << "\nConsultando se há um aluguel com valor <= a R$15.00." << endl;
    // READ(conn, "select * from Aluguel where valor<=15.00;");

    // // Realizando a consulta Número 03
    // cout << "\nConsultando se há um desenvolvedor com CPF = a 578.847.812-04." << endl;
    // READ(conn, "select * from Desenvolvedor where cpf='578.847.812-04';");

    // // Realizando a consulta Número 04 (COMPLEXA)
    // cout << "\nConsultando Alugueis com valor total >= 14.00." << endl;
    // READ(conn, "select P.nome, E.Numero, E.CodigoJogo from Usuario as U, Aluguel as A, Pessoa as P, Exemplar as E where (E.Numero=A.NumeroExemplar) and (E.CodigoJogo=A.CodigoJogo) and (U.Cpf=P.Cpf) and (A.CpfUsuario=U.Cpf) and (A.Valor >= 14.00);");

    // // Inserindo uma nova pessoa
    // cout << "\nCriando uma pessoa com CPF = a 444.444.444-44 e nome = a Gusttavo Lima." << endl;
    // CREATE(conn, "insert into Pessoa values ('444.444.444-44', 'Gusttavo Lima');");

    // // Realizando a atualização Número 01
    // cout << "\nAtualizando a pessoa com CPF = a 444.444.444-44." << endl;
    // UPDATE(conn, "update Pessoa set nome='Nivaldo Batista Lima' where cpf='444.444.444-44';");

    // // Realizando a remoção Número 01
    // cout << "\nApagando a pessoa cujo CPF = 444.444.444-44." << endl;
    // DELETE(conn, "delete from Pessoa where cpf='444.444.444-44';");

    // Encerra a conexao com o banco de dados
    PQfinish(conn);

    return 0;
}

void CREATE(PGconn *conn, const char* query){
    char* nTuplas;
    
    PGresult *res;
    res = PQexec(conn, query);
    
    // Verifica a validade da consulta
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        cout << PQerrorMessage(conn);
        PQclear(res);
        PQfinish(conn);
        exit (2);
    }

    // Obtem o numero de tuplas
    nTuplas = PQcmdTuples(res);
    cout << "Número de tuplas alteradas no INSERT: " << nTuplas << endl;

    // Fecha o acesso ao resultado da consulta
    PQclear(res);

}

void READ(PGconn *conn, const char* query){
    int nTuplas, nAtributos;

    PGresult *res;
    res = PQexec(conn, query);
    
    // Verifica a validade da consulta
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        cout << PQerrorMessage(conn);
        PQclear(res);
        PQfinish(conn);
        exit (2);
    }

    // Obtem o numero de tuplas
    nTuplas = PQntuples(res);
    // Obtem o numero de atributos
    nAtributos = PQnfields(res);

    // Percorre todos as tuplas
    for (int i = 0; i < nTuplas; i++) {
        // Percorre todos os atributos
        for (int j = 0; j < nAtributos; j++){
            // Imprime o valor do atributo j da tupla i
            cout << PQgetvalue(res, i, j) << "\t";
        }
        cout << endl;
    }

    // Fecha o acesso ao resultado da consulta
    PQclear(res);
    
}

void UPDATE(PGconn *conn, const char* query){
    char* nTuplas;
    
    PGresult *res;
    res = PQexec(conn, query);
    
    // Verifica a validade da consulta
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        cout << PQerrorMessage(conn);
        PQclear(res);
        PQfinish(conn);
        exit (2);
    }

    // Obtem o numero de tuplas
    nTuplas = PQcmdTuples(res);
    cout << "Número de tuplas alteradas no UPDATE: " << nTuplas << endl;

    // Fecha o acesso ao resultado da consulta
    PQclear(res);
}

void DELETE(PGconn *conn, const char* query){
    char* nTuplas;
    
    PGresult *res;
    res = PQexec(conn, query);
    
    // Verifica a validade da consulta
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        cout << PQerrorMessage(conn);
        PQclear(res);
        PQfinish(conn);
        exit (2);
    }

    // Obtem o numero de tuplas
    nTuplas = PQcmdTuples(res);
    cout << "Número de tuplas alteradas no DELETE: " << nTuplas << endl;
    
    // Fecha o acesso ao resultado da consulta
    PQclear(res);

}