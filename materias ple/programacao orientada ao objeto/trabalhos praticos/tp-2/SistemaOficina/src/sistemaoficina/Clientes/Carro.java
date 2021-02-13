package sistemaoficina.Clientes;

import java.util.ArrayList;
import java.util.List;

public class Carro {
    private String modelo;
    private String placa;
    private String cor;

    //Construtor
    public Carro(String modelo, String placa, String cor){
        setModelo(modelo);
        setPlaca(placa);
        setCor(cor);
    }

    public Carro() {}

    //Gets

    public String getModelo() {
        return modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public String getCor() {
        return cor;
    } 

    /*
    protected Ordem getListaHistorico(int indice){
        // Percorrer historico
    }
    */

    //Sets

    protected void setModelo(String modelo) {
        this.modelo = modelo;
    }

    protected void setPlaca(String placa) {
        this.placa = placa;
    }

    protected void setCor(String cor) {
        this.cor = cor;
    }
}