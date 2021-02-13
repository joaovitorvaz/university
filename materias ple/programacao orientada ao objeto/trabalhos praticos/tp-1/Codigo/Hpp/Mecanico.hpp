#ifndef MECANICO_HPP
#define MECANICO_HPP

#include "./Ordem.hpp"
#include "./Funcionario.hpp"

using namespace std;

class Mecanico : public Funcionario{
private:
   Ordem ordem;

public:
    Mecanico(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
    ~Mecanico();
    void setOrdem(Ordem ordem);
    Ordem getOrdem();
    void setServicoOrdem(Servico servico);
};

#endif