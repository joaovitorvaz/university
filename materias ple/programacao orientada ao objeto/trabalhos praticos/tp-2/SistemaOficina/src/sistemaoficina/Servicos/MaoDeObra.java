package sistemaoficina.Servicos;

public class MaoDeObra{
    private String nome;
    private double valor;
	
    public MaoDeObra(){}
    public MaoDeObra(String nome, double valor){
	setNome(nome);
	setValor(valor);
    }
	
    //Getters e Setters
	
    //Get e set nome
    public void setNome(String nome){
	this.nome = nome;
    }
    public String getNome(){
	return nome;
    }
	
    //Get e set valor
    public void setValor(double valor){
	this.valor = valor;
    }
	
    public double getValor(){
        return valor;
    }
	
    @Override
    public Object clone(){
        try{                
           return super.clone();
                
        }catch(CloneNotSupportedException e){
            return null;
        }
   }
}