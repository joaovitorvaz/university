#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    string cpf;
    string rg;
    string endereco;
    string telefone;
    string email;

protected:
    void setNome(string);
    void setCpf(string);
    void setRg(string);
    void setEndereco(string);
    void setTelefone(string);
    void setEmail(string);

public:
    Pessoa(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "");
    ~Pessoa();
    string getNome();
    string getCpf();
    string getRg();
    string getEndereco();
    string getTelefone();
    string getEmail();
    friend istream& operator>>(istream&, Pessoa&); 
};

#endif