package sistemaoficina.Clientes;
import sistemaoficina.Clientes.Carro;
import sistemaoficina.Pessoa.Pessoa;
import java.util.ArrayList;
import java.util.List;

public class Cliente extends Pessoa{
    private List<Carro> carros;
    
    //Construtor
    public Cliente(String nome, String cpf, String rg, String endereco, String telefone, String email) {
        super(nome, cpf, rg, endereco, telefone, email);
        carros = new ArrayList<>();
    }

    public Cliente() {}

    public void setAtributos(Cliente envia) {
        this.setNome(envia.getNome());
        this.setCpf(envia.getCpf());
        this.setRg(envia.getRg());
        this.setEndereco(envia.getEndereco());
        this.setTelefone(envia.getTelefone());
        this.setEmail(envia.getEmail());
    }
    
    //Interacaoes com carro

    //Adicionar carro
    public void addCarro(Carro carro) {
        if(!carros.isEmpty())
            carros.add(carro);
    }
    
    //Remover Carro
    protected void popCarro(Carro carro) {
        if(!carros.isEmpty())
            carros.remove(carros);
    }
    
    //Comparação
    @Override
    public boolean equals(Object o) {
        if(this == o)
            return true;
        
        if(o == null)
            return false;
        
        if(getClass() != o.getClass())
            return false;

        Cliente cliente = (Cliente)o;
        
        return ((this.getCpf()).equals(cliente.getCpf()) && (this.getRg()).equals(cliente.getRg()));
    }
}