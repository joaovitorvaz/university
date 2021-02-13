package sistemaoficina.Funcionarios;

import sistemaoficina.Pessoa.Pessoa;

public class Funcionario extends Pessoa{
    private String user;
    private String senha;
    private int id;

    //Construtor
    public Funcionario(String nome, String cpf, String rg, String endereco, String telefone, String email, String user, String senha) {
        super(nome, cpf, rg, endereco, telefone, email);
        setUser(user);
        setSenha(senha);
        this.id = id;
    }

    public Funcionario() {
        this.id = 0;
    }

    //Gets

    public String getUser() {
        return user;
    }

    public String getSenha() {
        return senha;
    }

    public int getId() {
        return id;
    }

    //Sets

    protected void setUser(String user) {
        this.user = user;
    }

    protected void setSenha(String senha) {
        this.senha = senha;
    }
    
    protected void setId(int id) {
        this.id = id;
    }
}