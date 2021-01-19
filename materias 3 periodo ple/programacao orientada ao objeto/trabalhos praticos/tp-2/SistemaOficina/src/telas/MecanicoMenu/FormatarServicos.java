/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telas.MecanicoMenu;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import sistemaoficina.Funcionarios.Mecanico;
import sistemaoficina.Servicos.Item;
import sistemaoficina.Servicos.MaoDeObra;
import sistemaoficina.Servicos.Ordem;
import sistemaoficina.Servicos.Servico;

/**
 *
 * @author maceg
 */
public class FormatarServicos extends javax.swing.JDialog {
    //Variavel EditarOrdem para receber o endereco de memoria da tela anterior e permitir a edicao de certos dados
    private EditarOrdem editarOrdem;
    //Variavel Mecanico para receber o endereco de memoria do mecanico anterior e manter as alteracoes feitas a ele nessa tela
    private Mecanico mecani;
    //Numero maximo de telas que podem ser criadas
    private int indice;
    //Contador para o numero de tabas criada
    private int click = 0;
    /**
     * Creates new form FormatarServicos
     */
    //Construtor padrao criado pelo NetBeans
    public FormatarServicos(java.awt.Frame parent, boolean modal) {
        super(parent, modal);
        initComponents();
    }
    //Construtor basico, apenas inicializa os componentes
    public FormatarServicos() {
        
        initComponents();
    
    }
    //Construtor complexo, recebe uma variavel EditarOrdem para permitir tornar a tela anterior visivel novamente
    //Recebe um indice para definir o numero de abas a serem criadas no JTabbedPane
    //Recebe uma variavel mecanico para poder alterar seus campos e ainda manter as alteracoes mesmo com a aba fechada
    public FormatarServicos(EditarOrdem editarOrdem, int indice, Mecanico mecani) {
        this();
        this.editarOrdem = editarOrdem;
        this.indice = indice;
        this.mecani = mecani;
        //Chamando o metodo que ira criar o numero de abas do JTabbedPane
        criarAbas();
    
    }
    //Metodo que cria as abas do JTabbedPane
    private void criarAbas() {       
        
         //As abas estao sendo adicionadas ao painel por meio do metodo inbutido addTab
         //O titulo da aba esta sendo definido como Servico#, a variavel click defini o numero da aba
         //Esta sendo chamada o meotdo criarPaineis que retorna um component que sera adicionado a aba
        jTabbedPane1.addTab("Servico #" + (click+1), criarPaineis()); 
        
        
       
    }
    //Metodo que cria e retorna um JPanel
    //Utilizado na funcao criarAbas para definir a aba do componente jTabbedPane1
    private JPanel criarPaineis(){
        //Painel esta sendo criado
        JPanel panel = new JPanel();
        //Esta sendo definido o layout do painel para a seguir serem inseridos componentes
        javax.swing.GroupLayout panelLayout = new javax.swing.GroupLayout(panel);
        //Settando o layout previamente criado
        panel.setLayout(panelLayout);
        //Metodo que adiciona componentes que irao formar um formulario
        camposServico(panel);
        //Retornar o JPanel criado e configurado, para ser inserido no metodo criarAbas
        return panel;
    }
    
    //Metodo que recebe um JPanel e define campos que serao adicionados ao mesmo
    private void camposServico(JPanel panel){
            //Esta sendo definida a variavel space que ira indicar a posicao Y de cada componente no JPanel
            /*Estao sendo criados 6 JLabels e 6 JTextFields que serao adicionados ao JPanel que foi recebido, 
            a fim de criar uma interface sem a um formulario*/
            int space = -30;
            //Esta sendo adicionado +20 para definir a distancia do painel
            space+=20;
            //Criando o JLabel para mao de obra
            JLabel nomeMaodeObra = new javax.swing.JLabel();           
            nomeMaodeObra.setVisible(true);
            nomeMaodeObra.setText("Mão de obra");
            nomeMaodeObra.setSize(160, 40);
            nomeMaodeObra.setLocation(20, space);
            //Label sendo adicionado ao painel passado
            panel.add(nomeMaodeObra);
            
            //Adiciona mais espaco, para evitar que o componente se sobreponha aos demais
            space+=25;
            JTextField inputNomeMaodeObra = new JTextField();
            inputNomeMaodeObra.setVisible(true);
            inputNomeMaodeObra.setSize(160,20);
            inputNomeMaodeObra.setLocation(20, space);
            //Campo de texto sendo adicionado ao painel
            panel.add(inputNomeMaodeObra);       
            
            
            space+=20;
            JLabel precoMaodeObra = new javax.swing.JLabel();           
            precoMaodeObra.setVisible(true);
            precoMaodeObra.setText("Valor da mão de obra");
            precoMaodeObra.setSize(160, 40);
            precoMaodeObra.setLocation(20, space);
            panel.add(precoMaodeObra);
            
            space+=25;
            JTextField inputPrecoMaodeObra = new JTextField();
            inputPrecoMaodeObra.setVisible(true);
            inputPrecoMaodeObra.setSize(160,20);
            inputPrecoMaodeObra.setLocation(20, space);
            panel.add(inputPrecoMaodeObra);
            
            space+=20;
            JLabel nomeItem = new javax.swing.JLabel();           
            nomeItem.setVisible(true);
            nomeItem.setText("Item");
            nomeItem.setSize(160, 40);
            nomeItem.setLocation(20, space);
            panel.add(nomeItem);
            
            space+=25;
            JTextField inputNomeItem = new JTextField();
            inputNomeItem.setVisible(true);
            inputNomeItem.setSize(160,20);
            inputNomeItem.setLocation(20, space);
            panel.add(inputNomeItem);
            
            space+=20;
            JLabel quantItem = new javax.swing.JLabel();           
            quantItem.setVisible(true);
            quantItem.setText("Quantidade de itens");
            quantItem.setSize(160, 40);
            quantItem.setLocation(20, space);
            panel.add(quantItem);
            
            space+=25;
            JTextField inputQuantItem = new JTextField();
            inputQuantItem.setVisible(true);
            inputQuantItem.setSize(160,20);
            inputQuantItem.setLocation(20, space);
            panel.add(inputQuantItem);           
            
            space+=20;
            JLabel valorItem = new javax.swing.JLabel();           
            valorItem.setVisible(true);
            valorItem.setText("Valor do item");
            valorItem.setSize(160, 40);
            valorItem.setLocation(20, space);
            panel.add(valorItem);
            
            space+=25;
            JTextField inputValorItem = new JTextField();
            inputValorItem.setVisible(true);
            inputValorItem.setSize(160,20);
            inputValorItem.setLocation(20, space);
            panel.add(inputValorItem);            
            
            space+=20;
            JLabel codigoItem = new javax.swing.JLabel();           
            codigoItem.setVisible(true);
            codigoItem.setText("Codigo do Item");
            codigoItem.setSize(160, 40);
            codigoItem.setLocation(20, space);
            panel.add(codigoItem);
            
            space+=25;
            JTextField inputCodigoItem = new JTextField();
            inputCodigoItem.setVisible(true);
            inputCodigoItem.setSize(160,20);
            inputCodigoItem.setLocation(20, space);
            panel.add(inputCodigoItem);            
            
            
    }
    
    //Metodo que adiciona os campos digitados previamente a ordem que o mecanico esta responsavel
    public void updateOrdem(JPanel panel){        
        //Recebendo a String referente ao nome da mao de obra
        //O metodo getComponente retorna um component generico,portanto e necessario dar um cast para o componente desejado
        
        //Esta sendo pego o componente na posicao 1, pois todos os JTextFields foram adicionados em posicoes impares
        String nomeMaoDeObra = (((JTextField)panel.getComponent(1)).getText());
       
        
        double precoMaoDeObra = Double.parseDouble(((JTextField)panel.getComponent(3)).getText());
       
       
        String nomeItem = (((JTextField)panel.getComponent(5)).getText());
        
        
        int quantItem = Integer.parseInt(((JTextField)panel.getComponent(7)).getText());
       
       
        double precoItem = Double.parseDouble(((JTextField)panel.getComponent(9)).getText());
        
        
        int codigoItem = Integer.parseInt(((JTextField)panel.getComponent(11)).getText());
        
        
        //Criando variaveis MaoDeObra e Item de forma a tornar mais clara a leitura
        //As variaveis estao sendo criadas baseado nas informacoes passadas nos JTextField anteriores
        //Visto que quando foram criados dentro do construtor do servico, se tornou muito confusa a leitura
        MaoDeObra mao = new MaoDeObra(nomeMaoDeObra, precoMaoDeObra);
        Item item = new Item(nomeItem, precoItem, quantItem, codigoItem);
        
        
        //Criando um servico para ser adicionado a ordem a qual o mecanico e responsavel
        //A variavel click esta sendo adicionado como Codigo dos servicos, visto que torna sua adicao e remocao da lista de servicos na ordem mais facil
        mecani.setOrdemServico(new Servico(mao, item, (mecani.getOrdem().getListaServico().size()+click)));
    
    }
    public boolean verificaCampos(JPanel painel){
        try{
            updateOrdem(painel);
        }
        catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Campo invalido.", "Erro", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        catch(NullPointerException e ){
            JOptionPane.showMessageDialog(null, "Não há uma ordem adicionada", "Erro", JOptionPane.ERROR_MESSAGE);
        }        
        return true;
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTabbedPane1 = new javax.swing.JTabbedPane();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Formulário Serviço");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
        });

        jButton1.setText("Voltar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Próximo");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.TRAILING)
            .addGroup(layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 103, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 152, Short.MAX_VALUE)
                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(38, 38, 38))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 298, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    //Acao para quando a janela for fechada
    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        // TODO add your handling code here:
        //Torna a janela anterior visivel
        editarOrdem.setVisible(true);
        
    }//GEN-LAST:event_formWindowClosed
    //Botao criado para quando o usuario quiser retornar a aba anterior
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        //Reduzindo o contador quando o usuario clicar no botao, de forma a manter um padrao para o titulo das abas
        //Alem disso torna mais facil a remocao de servicos,visto que seu Codigo e definido 
        click -=1;
        if(click<0){
            //Torna a tela invisivel quando o usuario aperta o botao voltar multiplas vezes
            this.setVisible(false);
            //Torna a tela anterior visivel
            editarOrdem.setVisible(true);
        }
        else{
            //Cria nova aba para simular passagem de uma aba para outra
            criarAbas();
            //Deletando a aba atual, a fim de evitar que o usuario altere seus dados
            jTabbedPane1.remove(jTabbedPane1.getSelectedIndex());
        }
        
        
        
    }//GEN-LAST:event_jButton1ActionPerformed
    //Botao confirmar que leva a "proxima" aba
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        if(verificaCampos(((JPanel)jTabbedPane1.getComponentAt(jTabbedPane1.getSelectedIndex()))) == true){
            // TODO add your handling code here:
            //Incrementando o contador de forma a criar o titulo das listas em ordem
            //Alem disso cria as o codigo dos servico em ordem que sao adicionadas
            click+=1;
            //Caso o contador seja maior ou igual ao indice(numero de abas maximo, significa que o usuario criou o numero de abas maximo
            if(click >= indice){
                //A tela se torna invisivel
                this.setVisible(false);
                //Chamado o metodo que adiciona um servico a ordem
                //Esta sendo passado o Panel da aba em que o usuario esta atualmente
                updateOrdem(((JPanel)jTabbedPane1.getComponentAt(jTabbedPane1.getSelectedIndex())));
                //Mostrando que a ordem foi concluida apos a adicao de todos os servicos possiveis
                mecani.getOrdem().setEstado(true);
                //Aba e removida para simular passagem 
                jTabbedPane1.remove(jTabbedPane1.getSelectedIndex());
                //Tela anterior se torna visivel
                editarOrdem.setVisible(true);
                JOptionPane.showMessageDialog(null, "Serviços Cadastrados.", "Message", JOptionPane.INFORMATION_MESSAGE);
            }        
            else {
                //Semelhante ao processo feito anteriormente, no entanto a tela anterior nao esta sendo chamada
                criarAbas();
                updateOrdem(((JPanel)jTabbedPane1.getComponentAt(jTabbedPane1.getSelectedIndex())));
                jTabbedPane1.remove(jTabbedPane1.getSelectedIndex());
            }
            
        }
       
    }//GEN-LAST:event_jButton2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(FormatarServicos.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(FormatarServicos.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(FormatarServicos.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(FormatarServicos.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the dialog */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                FormatarServicos dialog = new FormatarServicos(new javax.swing.JFrame(), true);
                dialog.addWindowListener(new java.awt.event.WindowAdapter() {
                    @Override
                    public void windowClosing(java.awt.event.WindowEvent e) {
                        System.exit(0);
                    }
                });
                dialog.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JTabbedPane jTabbedPane1;
    // End of variables declaration//GEN-END:variables
}
