package sistemaoficina.Servicos;

import sistemaoficina.Servicos.MaoDeObra;
import sistemaoficina.Servicos.Item;
import java.util.ArrayList;
import java.util.List;

public class Servico{
    private MaoDeObra mao_de_obra;	
    private Item item;
    private double valorTotal;
    public int codeServico;

    public Servico() {
        // Implementar o restante dps
	item = new Item();
	mao_de_obra = new MaoDeObra();
    }
    
    public Servico(MaoDeObra mao_de_obra,Item item, int codeServico) {
	setMaoDeObra(mao_de_obra);
	setItem(item);
        valorTotal = 0;
        setCodeServico(codeServico);
    }

    //Set e get
    //Set e get MaoDeObra
    public void setMaoDeObra(MaoDeObra mao_de_obra){
	this.mao_de_obra = mao_de_obra;
    }

    public MaoDeObra getMaoDeObra(){
	return mao_de_obra;
    }
                
    //Set e get Itens
    public void setItem(Item item){
        this.item = item;
    }

    public Item getItem(){            
            
        return item;
       
    }	

    //Set e get Code Servico
    public void setCodeServico(int codeServico){
	this.codeServico = codeServico;
    }

    public int getCodeServico(){
	return codeServico;
    }

    //Get custo de um servico
    public void setValorTotal(){
	this.valorTotal += this.item.getValorTotal();
        this.valorTotal += this.mao_de_obra.getValor();
    }
        
    //Retornando o valor total
    public double getValorTotal(){
        //Chamando o set ValorTotal para recalcular o valor total do getValorTotal
        setValorTotal();
        return valorTotal;
    }
	
}