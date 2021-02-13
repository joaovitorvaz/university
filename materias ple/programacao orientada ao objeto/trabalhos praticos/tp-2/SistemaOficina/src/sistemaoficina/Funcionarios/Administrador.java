package sistemaoficina.Funcionarios;
import java.util.List;
import java.util.ArrayList;

public class Administrador extends Funcionario {
    private static int idFunc = 1001;
    private List<Vendedor> vendedores;
    private List<Mecanico> mecanicos;

    /**
    * Construtor da classe Administrador com todos os parametros preenchidos
    */
    public Administrador(String nome, String cpf, String rg, String endereco, String telefone, String email) {
        super(nome, cpf, rg, endereco, telefone, email, "admin", "admin");
        setId(0);
        vendedores = new ArrayList<>();
        mecanicos = new ArrayList<>();
    }

    public Administrador() {}

    /**
    * Retorna o campo vendedores da classe Administrador
    * @return vendedores - Campo que armazena os vendedores cadastrados
    */
    public List<Vendedor> getListaVendedores() {
        return vendedores;
    }
    
    /**
    * Retorna o campo mecanicos da classe Administrador
    * @return mecanicos - Campo que armazena os mecanicos cadastrados
    */
    public List<Mecanico> getListaMecanicos() {
        return mecanicos;
    }
    
    //Verifica se um funcionário existe de acordo com o ID
    public int existFunc(int op, int id){
        //Vendedor 1
        if(op == 1){
            for(Vendedor vend : vendedores) {
                if(vend.getId() == id){
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        //Mecanico 2
        else{
            for(Mecanico meca : mecanicos) {
                if(meca.getId() == id){
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        return 0;
    }

    /**
    * Retorna o campo idFunc da classe Administrador
    * @return idFunc - Campo responsavel pela contagem de funcionarios e para atribuir Id's unicos
    */
    public int getIdFunc() {
        return idFunc;
    }

    /**
    * Incrementa 1 ao campo idFunc
    */
    public static void setIdFunc() {
        idFunc++;
    }

    /**
    * Adiciona o vendedor passado nos parametros a lista de vendedores
    * @param vendedor - Objeto que será adicionado
    * @return Caso seja true o vendedor foi adicionado com sucesso,
    * caso contrario o vendedor em questão já foi adicionado em algum momento
    */
    public boolean addVendedor(Vendedor vendedor) {
        if(!vendedores.contains(vendedor)) {
            vendedor.setId(idFunc);
            vendedores.add(vendedor);
            Administrador.idFunc++;
            return true;
        }
        
        return false;
    }

    /**
    * Remove o vendedor passado nos parametros da lista de vendedores
    * @param vendedor - Objeto que será removido
    */
    public void removeVendedor(Vendedor vendedor) {
        if(!vendedores.isEmpty()) {
            vendedores.remove(vendedor);
        }
    }

    /**
    * Retorna da lista de vendedores o vendedor que tenha o id igual ao passado nos parametros
    * @param id - Referente ao vendedor que será retornado
    * @return Caso o vendedor seja encontrado retorna o vendedor, caso contrario
    * será retornado null
    */
    public Vendedor getVendedor(int id) {
        for(Vendedor vend : vendedores) {
            if(vend.getId() == id)
                return vend;
        }

        return null;
    }
    
    /**
    * Retorna da lista de vendedores o vendedor que tenha o user igual ao passado nos parametros
    * @param user - Referente ao vendedor que será retornado
    * @return Caso o vendedor seja encontrado retorna o vendedor, caso contrario
    * será retornado null
    */
    public Vendedor getVendedorUser(String user) {
        for(Vendedor vend : vendedores) {
            if(user.equals(vend.getUser()))
                return vend;
        }
        
        return null;
    }

    /**
    * Atualiza o vendedor já contido na lista, caso não exista o vendedor na lista, não acontecerá nada
    * @param vendedor - Objeto com os campos atualizados
    */
    public void setVendedor(Vendedor vendedor) {
        for(Vendedor vend : vendedores) {
            if(vend.equals(vendedor)){
                vend.setAtributos(vend, vendedor);
            }
        }
    }
    
    /**
    * Adiciona o mecanico passado nos parametros a lista de mecanicos
    * @param mecanico - Objeto que será adicionado
    * @return Caso seja true o mecanico foi adicionado com sucesso,
    * caso contrario o mecanico em questão já foi adicionado em algum momento
    */
    public boolean addMecanico(Mecanico mecanico) {
        if(!mecanicos.contains(mecanico)) {
            mecanico.setId(idFunc);
            mecanicos.add(mecanico);
            Administrador.idFunc++;
            return true;
        }
        
        return false;
    }
    
    /**
    * Remove o mecanico passado nos parametros da lista de mecanicos
    * @param mecanico - Objeto que será removido
    */
    public void removeMecanico(Mecanico mecanico) {
        if(!mecanicos.isEmpty()) {
            mecanicos.remove(mecanico);
        }
    }

    /**
    * Retorna da lista de mecanicos o mecanico que tenha o id igual ao passado nos parametros
    * @param id - Referente ao mecanico que será retornado
    * @return Caso o mecanico seja encontrado retorna o mecanico, caso contrario
    * será retornado null
    */
    public Mecanico getMecanico(int id) {
        for(Mecanico meca : mecanicos) {
            if(meca.getId() == id)
                return meca;
        }

        return null;
    }
    
    /**
    * Retorna da lista de mecanicos o mecanico que tenha o user igual ao passado nos parametros
    * @param user - Referente ao mecanico que será retornado
    * @return Caso o mecanico seja encontrado retorna o mecanico, caso contrario
    * será retornado null
    */
    public Mecanico getMecanicoUser(String user) {
        for(Mecanico meca : mecanicos) {
            if(user.equals(meca.getUser()))
                return meca;
        }
        
        return null;
    }
    
    /**
    * Atualiza o mecanico já contido na lista, caso não exista o mecanico na lista, não acontecerá nada
    * @param mecanico - Objeto com os campos atualizados
    */
    public void setMecanico(Mecanico mecanico) {
        for(Mecanico meca : mecanicos) {
            if(meca.equals(mecanico))
                meca.setAtributos(meca, mecanico);
        }
    }
    
    /**
    * Função responsavel pela verificação dos campos user e senha inseridos no login
    * @param user - User do usuario
    * @param senha - Senha do usuario
    * @return Caso o retorno seja 1 foi encontrado um vendedor, caso seja 2 foi encontrado um mecanico,
    * caso seja 3 foi encontrado um administrador e caso seja 0 não foi encontrado nenhum objeto
    */
    public int VerificaUsuario(String user, String senha) {
        if(user.contains("vende")) {
            String id = user.substring(5);
            int i = Integer.parseInt(id);
            
            Vendedor vend = getVendedor(i);
            if(vend != null) {
                if(senha.equals(vend.getSenha()))
                    return 1;
                
                else
                    return 0;
            }
            
            else
                return 0;
        }
        
        else if(user.contains("mecan")) {
            String id = user.substring(5);
            int i = Integer.parseInt(id);
            
            Mecanico meca = getMecanico(i);
            if(meca != null) {
                if(senha.equals(meca.getSenha()))
                    return 2;
                
                else
                    return 0;
            }
            
            else
                return 0;
        }
        
        else if(user.contains("admin")) {
            if(senha.equals("admin"))
                return 3;
            
            else
                return 0;
        }

        return 0;
    }

}
