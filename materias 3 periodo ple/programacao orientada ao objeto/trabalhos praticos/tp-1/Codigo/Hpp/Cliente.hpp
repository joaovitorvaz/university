#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "./Pessoa.hpp"
#include "./Carro.hpp"
#include<string>
#include<list>
#include <iostream>

using namespace std;

class Cliente : public Pessoa{
private:
    list<Carro> carros;

public:
    Cliente(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "");
    ~Cliente();
    void setNomeCliente(string);
    void setTelefoneCliente(string);
    void setEmailCliente(string);
    void setEnderecoCliente(string);
    void addCarro(Carro carro);
    void popCarro(int id);
    void printaCarro();
};

#endif

