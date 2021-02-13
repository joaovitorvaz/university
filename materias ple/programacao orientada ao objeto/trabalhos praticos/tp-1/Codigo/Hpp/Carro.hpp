#ifndef CARRO_HPP
#define CARRO_HPP

#include "./Ordem.hpp"

#include<list>
#include<string>

using namespace std;

class Carro {
private:
    string modelo;
    string placa;
    string cor;
    list<Ordem> historico;
   
public:
    int id;
    Carro(string modelo = "", string placa = "", string cor = "", int id = 0);
    ~Carro();

    string getModelo();
    void setModelo(string modelo);

    string getPlaca();
    void setPlaca(string placa);

    string getCor();
    void setCor(string cor);
   
    Ordem getListaHistorico(int indice);

    int getId();
    void setId(int id);
};

#endif