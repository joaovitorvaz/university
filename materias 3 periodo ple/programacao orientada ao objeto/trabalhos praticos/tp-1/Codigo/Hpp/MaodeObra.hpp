#ifndef MAODEOBRA_HPP
#define MAODEOBRA_HPP

#include <string>

using namespace std;
class MaoDeObra {

private:
    string nome;
    double valor;

public:
    MaoDeObra(string nome = "", double valor = 0.0);
    ~MaoDeObra();
    string getNome();
    double getValor();
    void setNome(string);
    void setValor(double);
};

#endif