#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "./Pessoa.hpp"

#include<string>

using namespace std;

class Funcionario : public Pessoa{
private:
    string user;
    string senha;
    int id;

public:
    Funcionario(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
    ~Funcionario();

    string getUser();
    void setUser(string);

    string getSenha();
    void setSenha(string);

    int getId();
    void setId(int);
};

#endif