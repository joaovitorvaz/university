#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <list>
#include "Pessoa.hpp"
#include "Ordem.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"

class Vendedor : public Funcionario {
private:
    int static idOrdem;
    list<Ordem> static ordens;
    list<Cliente> static clientes;
public:
    Vendedor(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
    ~Vendedor();
    Cliente criaCadastro();
    Ordem criaOrdem();

    void addOrdem(Ordem*);
    void deleteOrdem(Ordem);
    Ordem getOrdem(int);
    list<Ordem> getListaOrdem();
    void setOrdem(Ordem);

    void addCliente(Cliente);
    Cliente getCliente(string);
    void setCliente(Cliente);

    bool confirmaOrdem(Ordem);
    list<int> printaOrdens(int);
    void printaOrdem(int);
    void printaClientes();
    void printaCliente(string);
};

#endif