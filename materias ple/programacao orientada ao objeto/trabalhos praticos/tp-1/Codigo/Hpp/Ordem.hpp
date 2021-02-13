#ifndef ORDEM_HPP
#define ORDEM_HPP

//Adicionar set e get para o ponteiro do cliente
#include "./Servico.hpp"

#include<string>
#include<list>

using namespace std;

class Ordem{
    private:
        string tipo;
        string motivo;
        string descricao;
        double km;
        bool aprovacao;
        double valorFinal;
        bool estado;
        list<Servico> listaServico;  
        int codeOrdem;            
        string cpfCliente;
        
    
    public:
        Ordem(string tipo = "", string motivo = "", string descricao = "", string cpfCliente = "",double km = 0.0, bool aprovacao = false, double valorFinal = 0.0, bool estado = false, int codeOrdem = 0000);
        ~Ordem();

        string getTipo();
        void setTipo(string tipo);

        string getMotivo();
        void setMotivo(string motivo);

        string getDescricao();
        void setDescricao(string descricao);

        double getKm();
        void setKm(double Km);

        bool getAprovacao();
        void setAprovacao(bool aprovacao);

        double getValorFinal();        

        bool getEstado();
        void setEstado(bool estado);

        list<Servico> getListaServico();
        void setListaServico(Servico servico);
        bool removeServico(int codeServico);
        

        int getCodeOrdem();
        void setCodeOrdem(int code);
        
        string getCpfCliente();
        void setCpfCliente(string);

};

#endif