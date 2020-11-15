package sistemaoficina.Pessoa;

public class Pessoa {
    private String nome;
    private String cpf;
    private String rg;
    private String endereco;
    private String telefone;
    private String email;
    /**
    * Construtor da classe Pessoa
    */
    public Pessoa(String nome, String cpf, String rg, String endereco, String telefone, String email) {
        setNome(nome);
        this.cpf = cpf;
        setRg(rg);
        setEndereco(endereco);
        setTelefone(telefone);
        setEmail(email);
    }

    public Pessoa() {} 

    /**
     * Retorna o valor relacionado ao campo nome
     * @return String nome
     */
    public String getNome() {
        return nome;
    }
    
    /**
     *  Retorna o valor relacionado ao campo cpf
     *  @return String cpf
     */
    public String getCpf() {
        return cpf;
    }
    
    /**
     * Retorna o valor relacionado ao campo rg
     * @return String rg
     */
    public String getRg() {
        return rg;
    } 

    /**
     * Retorna o valor relacionado ao campo endereço
     * @return String endereco
     */
    public String getEndereco() {
        return endereco;
    }

    /**
     * Retorna o valor relacionado ao campo telefone
     * @return String telefone
     */
    public String getTelefone() {
        return telefone;
    }
    
    /**
     * Retorna o valor relacionado ao campo email
     * @return String email
     */
    public String getEmail() {
        return email;
    }
    
    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param nome
     */
    protected void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param cpf
     */
    protected void setCpf(String cpf) {
        this.cpf = cpf;
    }

    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param rg
     */
    protected void setRg(String rg) {
        this.rg = rg;
    }

    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param endereco
     */
    protected void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param telefone
     */
    protected void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    /**
     * Edita o valor da variavel <strong>this</strong> para o valor no parametro
     * @param email
     */
    protected void setEmail(String email) {
        this.email = email;
    }
}