package sistemaoficina.Funcionarios;

import java.util.ArrayList;
import java.util.List;
import sistemaoficina.Servicos.Ordem;
import sistemaoficina.Servicos.Servico;

public class Mecanico extends Funcionario {
    private Ordem ordem;
    
    //Construtor
    public Mecanico(String nome, String cpf, String rg, String endereco, String telefone, String email, String user, String senha) {
        super(nome, cpf, rg, endereco, telefone, email, user, senha);
    }

    public Mecanico() {}
    
    //Settando atributos apartir de novas informações inseridas
    public void setAtributos(Mecanico meca1, Mecanico meca2){
        meca1.setNome(meca2.getNome());
        meca1.setCpf(meca2.getCpf());
        meca1.setRg(meca2.getRg());
        meca1.setEndereco(meca2.getEndereco());
        meca1.setTelefone(meca2.getTelefone());
        meca1.setEmail(meca2.getEmail());
        meca1.setUser(meca2.getUser());
        meca1.setSenha(meca2.getSenha());
    }

    //Gets
    
    public Ordem getOrdem() {
        return ordem;
    }

    //Sets
    
    public void setOrdem(Ordem ordem) {
        this.ordem = ordem;
    }

    public void setOrdemServico(Servico servico) {
       this.ordem.addServico(servico);
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

        Mecanico meca = (Mecanico)o;
        
        return (this.getCpf()).equals(meca.getCpf());
    }
}