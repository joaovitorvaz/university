package sistemaoficina.Funcionarios;

import java.util.List;
import java.util.ArrayList;
import sistemaoficina.Clientes.Cliente;
import sistemaoficina.Servicos.Ordem;

public class Vendedor extends Funcionario {
    private static int idOrdem = 1;
    private static List<Cliente> clientes;
    private static List<Ordem> ordens;

    /**
    * Construtor da classe Vendedor com todos os campos preechidos
    */
    public Vendedor(String nome, String cpf, String rg, String endereco, String telefone, String email, String user, String senha) {
        super(nome, cpf, rg, endereco, telefone, email, user, senha);
        clientes = new ArrayList<>();
        ordens = new ArrayList<>();
    }

    public Vendedor() {
        super();
        clientes = new ArrayList<>();
        ordens = new ArrayList<>();
    }
    
    /**
    * Atualiza os atributos de acordo com novos dados, visto que não é possivel altera-lo fora da herança
    * @param vend1 é a variavel que será alterada
    * @param vend2 é a valerivel com os campos altualizados
    */
    public void setAtributos(Vendedor vend1, Vendedor vend2){
        vend1.setNome(vend2.getNome());
        vend1.setCpf(vend2.getCpf());
        vend1.setRg(vend2.getRg());
        vend1.setEndereco(vend2.getEndereco());
        vend1.setTelefone(vend2.getTelefone());
        vend1.setEmail(vend2.getEmail());
        vend1.setUser(vend2.getUser());
        vend1.setSenha(vend2.getSenha());
    }

    /**
    * Retorna o valor atual dado às ordens
    * @return int IdOrdem
    */
    public int getIdOrdem() {
        return idOrdem;
    }

    /**
    * Incrementa 1 ao valor atual do id das ordens
    */
    public static void setIdOrdem() {
        idOrdem++;
    }

    /**
    * Adiciona ao final da lista o cliente desejado
    * @param cliente é o cliente que será adicionado
    * @return Caso seja true o cliente foi adicionado com sucesso, caso seja false o cliente já foi adicionado antes
    */
    public boolean addCliente(Cliente cliente) {
        if(!clientes.contains(cliente)) {
            clientes.add(cliente);
            return true;
        }
        
        return false;
    }
    
    /**
    * Remove o cliente desejado
    * @param cliente é o cliente que será excluido
    * @return Caso seja true o cliente foi excluido com sucesso, caso seja false a lista em questão esta vazia
    */
    public boolean removeCliente(Cliente cliente) {
        if(!clientes.isEmpty()) {
            clientes.remove(cliente);
            return true;
        }
        
        return false;
    }

    /**
    * Retorna da lista o cliente desejado
    * @param cpf - Referente ao cliente que deseja retornar
    * @return Cliente - Caso o cliente seja encontrado, null - Caso o cliente não seja encontrado
    */
    public Cliente getCliente(String cpf) {
        for(Cliente cliente : clientes) {
            if(cpf.equals(cliente.getCpf()))
                return cliente;
        }
        
        return null;
    }
    
    /**
    * Retorna a Lista completa dos clientes
    * @return clientes
    */
    public List<Cliente> getListaClientes() {
        return clientes;
    }
    
    /**
    * Seta o cliente da lista com o cliente inserido nos parametros
    * @param cliente - Cliente que será adicionado novamente a lista, caso o cliente não exista não acontecerá nada
    */
    public void setCliente(Cliente cliente) {
        for(Cliente client : clientes) {
            if(cliente.getCpf().equals(client.getCpf()))
                client = cliente;
        }
    }
    
    /**
    * Adiciona ao final da lista a ordem desejado
    * @param ordem é a ordem que será adicionado
    * @return Caso seja true a ordem foi adicionado com sucesso, caso seja false a ordem já foi adicionado antes
    */
    public boolean addOrdem(Ordem ordem) {
        if(!ordens.contains(ordem)) {
            ordens.add(ordem);
            Vendedor.idOrdem++;
            return true;
        }
        
        return false;
    }
    
    /**
    * Remove a ordem desejada
    * @param ordem é a ordem que será excluida
    * @return Caso seja true a ordem foi excluida com sucesso, caso seja false a lista em questão esta vazia
    */
    public boolean removeOrdem(Ordem ordem) {
        if(!ordens.isEmpty()) {
            ordens.remove(ordem);
            return true;
        }
        
        return false;
    }
    
    /**
    * Retorna da lista a ordem desejada
    * @param codeOrdem - Referente a ordem que deseja retornar
    * @return Ordem - Caso a ordem seja encontrada, null - Caso a ordem não seja encontrada
    */
    public Ordem getOrdem(int codeOrdem) {
        for(Ordem ord : ordens) {
            if(ord.getCodeOrdem() == codeOrdem)
                return ord;
        }
        
        return null;
    }
    
    /**
    * Seta a ordem da lista com a ordem inserida nos parametros
    * @param ordem - Ordem que será adicionada novamente a lista, caso a ordem não exista não acontecerá nada
    */
    public void setOrdem(Ordem ordem) {
        for(Ordem ord : ordens) {
            if(ord.equals(ordem))
                ord = ordem;
        }
    }
    
    /**
    * Retorna a Lista completa das ordens
    * @return ordens
    */
    public List<Ordem> getListaOrdens() {
        return ordens;
    }
    
    /**
    * Seta o campo de aprovação da ordem passado no param
    * @param ordem - É a ordem que será alterada
    */
    public void confirmaOrdem(Ordem ordem) {
        ordem.setAprovacao(true);
    }
    
    @Override
    /**
    * Compara se o objeto em questão possui os campos iguais ao objeto this
    * @param o - Objeto usado na comparação
    */
    public boolean equals(Object o) {
        if(this == o)
            return true;
        
        if(o == null)
            return false;
        
        if(getClass() != o.getClass())
            return false;

        Vendedor vend = (Vendedor)o;
        
        return (this.getCpf().equals(vend.getCpf()));
    }
}
