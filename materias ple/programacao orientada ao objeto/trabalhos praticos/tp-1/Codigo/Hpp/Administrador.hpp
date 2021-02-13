#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "Funcionario.hpp"
#include "Vendedor.hpp"
#include "Mecanico.hpp"

class Administrador : public Funcionario {
private:
    int static idFunc;
    list<Vendedor> vendedores;
    list<Mecanico> mecanicos;
public:
    Administrador(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "admin", string senha = "admin", int id = 0);
    ~Administrador();

    Vendedor criaVendedor(); //Implementar
    void addVendedor(Vendedor);
    void removeVendedor(Vendedor);
    Vendedor getVendedorUser(string);
    Vendedor getVendedorId(int);
    void setVendedor(Vendedor, int);

    Mecanico criaMecanico(); //Implementar
    void addMecanico(Mecanico);
    void removeMecanico(Mecanico);
    Mecanico getMecanicoUser(string);
    Mecanico getMecanicoId(int);
    void setMecanico(Mecanico, int);

    void printaVendedores();
    void printaVendedor(Vendedor);
    void printaMecanicos();
    void printaMecanico(Mecanico);
    
    int verificaUser(string,string);
    
};

#endif 