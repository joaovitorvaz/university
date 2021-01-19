package sistemaoficina.Servicos;

public class Item implements Cloneable{
	private String nome;
	private double valorTotal;
	private int quantidade;
	public int codeItem;
	
	//Constructors
	public Item(){}
	
	public Item(String nome, double valorTotal, int quantidade, int codeItem){
            setNome(nome);
            setValorTotal(valorTotal);
            setQuantidade(quantidade);
            setCodeItem(codeItem);
		
	}
	
	//Gets e setters
	
	//Get e set nome
	public void setNome(String nome){
            this.nome = nome;
	}
	public String getNome(){
            return nome;
	}
	
	//Get e set Valor total
	public void setValorTotal(double valorTotal){
            this.valorTotal = valorTotal;
	}
	public double getValorTotal(){
            setValorTotal(valorTotal * quantidade);
            return (valorTotal * quantidade);
	}
	
	//Get e set quantidade
	public void setQuantidade(int quantidade){
            this.quantidade = quantidade;
	}

	public int getQuatidade(){
            return quantidade;
	}
	
	//Get e set codeItem
	public void setCodeItem(int codeItem){
            this.codeItem = codeItem;
	}

	public int getCodeItem(){
            return codeItem;
	}
	
	//Metodo clone
        
        
        @Override
        public Object clone(){
            try{                
                return super.clone();
                
            }catch(CloneNotSupportedException e){
                return null;
            }
        }
		

}