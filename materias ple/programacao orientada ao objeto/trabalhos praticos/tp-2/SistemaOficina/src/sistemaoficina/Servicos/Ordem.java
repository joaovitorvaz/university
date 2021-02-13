package sistemaoficina.Servicos;

import java.util.ArrayList;
import java.util.List;

public class Ordem{
	private String tipo;
	private String motivo;
	private String descricao;
	private double km;
	private boolean aprovacao;
	private double valorFinal;
	private boolean estado;
	private List<Servico> listaServico;
	private int codeOrdem;
	private String cpfCliente;
	
        //Construtos basico da Ordem responsavel por inicializar apenas a lista Servico
	public Ordem(){
            
		List<Servico> listaServico = new ArrayList<Servico>();
	}
        //Construtor complexo da Ordem responsavel por inicializar os campos da Ordem com os parametros recebidos
	public Ordem(String tipo, String motivo, String descricao, double km, boolean aprovacao, boolean estado, int codeOrdem, String cpfCliente){
		setTipo(tipo);
		setMotivo(motivo);
		setDescricao(descricao);
		setKm(km);
		setAprovacao(aprovacao);
		listaServico = new ArrayList<Servico>();
		setCodeOrdem(codeOrdem);
		setCpf(cpfCliente);
                valorFinal = 0;
	}
	
	//Sets e Gets
	
	//Get e Set Tipo
        
	public void setTipo(String tipo){
		this.tipo = tipo;
	}
	
	public String getTipo(){
		return tipo;
	}
	//Get e Set Motivo
	public void setMotivo(String motivo){
		this.motivo = motivo;
	}
	
	public String getMotivo(){
		return motivo;
	}
	
	//Get e Set Descricao
	public void setDescricao(String descricao){
		this.descricao = descricao;
	}
	
	public String getDescricao(){
		return descricao;
	}
	
	//Get e Set Km
	public void setKm(double km){
		this.km = km;
	}
	public double getKm(){
		return km;
	}
	
	//Get e Set Aprovacao
	public void setAprovacao(boolean aprovacao){
            this.aprovacao = aprovacao;
	}
	
	public boolean getAprovacao(){
            return aprovacao;
	}
	
	//Get Valor Final
	public double getValorFinal(){
            Servico servico = new Servico();		
            for(int i = 0; i < listaServico.size(); i++){
                servico = listaServico.get(i);
                valorFinal += servico.getValorTotal();
            }
            return valorFinal;
	}
	
	//Get e Set Estado	
	public void setEstado(boolean estado){
            this.estado = estado;
	}
	
	public boolean getEstado(){
            return estado;
	}
	
	//Get e Set Servico
        public void setServico(Servico servico){
            listaServico.forEach(serv->{ if(serv.getCodeServico() == serv.getCodeServico()) serv = servico; });        
        }
        
	public boolean addServico(Servico servico){
            if(!listaServico.contains(servico)) {
            
                listaServico.add(servico);
           
            return true;
        }
        
        return false;
    }
	
    //Funcao que remove um servico da lista   
    public void removeServico(Servico servico){
        //Verifica se a lista esta vazia ou nao
        if(!listaServico.isEmpty())
           listaServico.remove(servico);
    }
    //Funcao remove um servico da lista baseado no codigo recebido
    public void deleteServico(int codeServico){
        //Loop percorrendo o vetor        
        for(int i = 0; i < listaServico.size(); i++){
            //Caso o servico contenha o codigo identico ao desejado ele e removido da lista servico
            if(listaServico.get(i).getCodeServico() == codeServico){
                //Chamando o metodo para retirar uma lista servico
                removeServico(listaServico.get(i));
            }
            else continue;
        }
    }
                
    public Servico getServico(int codeServico){
        for(Servico servico : listaServico) {
            if(servico.getCodeServico() == codeServico)
                return servico;
        }

            return null;           
              
    }
    public List<Servico> getListaServico(){
    
        return listaServico;
    }
    
	
    //Get e Set Code Ordem
    public void setCodeOrdem(int codeOrdem){
        this.codeOrdem = codeOrdem;
    }
	
    public int getCodeOrdem(){
	return codeOrdem;
    }
	
    //Get e Set Cpf
    public void setCpf(String cpf){
	this.cpfCliente = cpf;
    }
	
    public String getCpf(){
        return cpfCliente;
    }
	
        @Override
    public boolean equals(Object o) {
        if(this == o)
            return true;
        
        if(o == null)
            return false;
        
        if(getClass() != o.getClass())
            return false;

        Ordem ordem = (Ordem)o;
        
        return (this.getCodeOrdem() == ordem.getCodeOrdem() && this.getCpf() == ordem.getCpf());
    }
}