/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telas.VendedorMenu;

import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import sistemaoficina.Funcionarios.Vendedor;
import sistemaoficina.Servicos.Ordem;

/**
 *
 * @author Daniel
 */
public class VisualizarOrdensPendentes extends javax.swing.JFrame {
    private Vendedor vendedor;
    private MenuVendedor menuVendedor;
    /**
     * Creates new form VisualizarOrdensPendentes
     */
    public VisualizarOrdensPendentes() {
        initComponents();
    }
    
    /**
    * Responsavel por montar e adicionar os campos da tabela de visualização de ordens
    */
    public void showOrdensPendentes(){
        int count = 0;
        List<Ordem> ordens = vendedor.getListaOrdens();
        DefaultTableModel model = (DefaultTableModel)TabelaOrdens.getModel();
        for(Ordem ordem : ordens){
            if(!ordem.getEstado()) {
                Object[] rowData = {ordem.getCodeOrdem(), ordem.getCpf(), ordem.getMotivo(), ordem.getKm(), ordem.getAprovacao() ? "Aprovado" : "Em analise", ordem.getAprovacao() ? "Em andamento" : "Aguardando aprovação"};
                model.addRow(rowData);
                count++;
            }
        }
    }
    
    /**
    * Transfere para a tela Visualizar Ordens Pendentes a referencia da tela MenuVendedor
    * e a variavel Vendedor utilizada no menu
    * @param menuVendedor - Referente a tela anterior
    * @param vendedor - Variavel utilizada
    */
    public void enviaVendedor(MenuVendedor menuVendedor, Vendedor vendedor) {
        this.vendedor = vendedor;
        this.menuVendedor = menuVendedor;
        showOrdensPendentes();
    } 

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        OrdensPendentes = new javax.swing.JScrollPane();
        TabelaOrdens = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        Voltar = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        TabelaOrdens.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Codigo", "CPF do Cliente", "Motivo", "Km do Carro", "Aprovação", "Estado"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, true, true, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        TabelaOrdens.setColumnSelectionAllowed(true);
        TabelaOrdens.getTableHeader().setReorderingAllowed(false);
        TabelaOrdens.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                TabelaOrdensMouseClicked(evt);
            }
        });
        OrdensPendentes.setViewportView(TabelaOrdens);
        TabelaOrdens.getColumnModel().getSelectionModel().setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);

        jLabel1.setText("ORDENS PENDENTES");

        Voltar.setText("Voltar ao Menu");
        Voltar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                VoltarActionPerformed(evt);
            }
        });

        jLabel2.setText("OBS: Para alterar o campo aprovação para aprovado basta clicar nele");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap(599, Short.MAX_VALUE)
                .addComponent(Voltar)
                .addGap(18, 18, 18))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(305, 305, 305)
                        .addComponent(jLabel1))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel2)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(OrdensPendentes)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addComponent(OrdensPendentes, javax.swing.GroupLayout.PREFERRED_SIZE, 350, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jLabel2)
                .addGap(58, 58, 58)
                .addComponent(Voltar)
                .addGap(19, 19, 19))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
    * Retorna a tela anterior e atualiza os campos alterados 
    */
    private void VoltarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_VoltarActionPerformed
        this.setVisible(false);
        for(int i = 0; i < TabelaOrdens.getRowCount(); i++) {
            try {
                vendedor.getOrdem((int)TabelaOrdens.getValueAt(i, 0)).setMotivo((String)TabelaOrdens.getValueAt(i, 2));
                vendedor.getOrdem((int)TabelaOrdens.getValueAt(i, 0)).setKm(Double.parseDouble((String)TabelaOrdens.getValueAt(i, 3)));

            } catch(ClassCastException e) {
                vendedor.getOrdem((int)TabelaOrdens.getValueAt(i, 0)).setMotivo((String)TabelaOrdens.getValueAt(i, 2));
         
            }
        }
        menuVendedor.setVendedor(vendedor);
        menuVendedor.setVisible(true);
    }//GEN-LAST:event_VoltarActionPerformed

    /**
    * Função responsavel por acompanhar os clicks que a tabela recebe, em especial 
    * no campo de aprovação para altera-lo
    */
    private void TabelaOrdensMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_TabelaOrdensMouseClicked
        for(int i = 0; i < TabelaOrdens.getRowCount(); i++) {
            if(TabelaOrdens.isCellSelected(i, 4)) {
                String mensage = "Deseja aprovar a ordem? Uma vez aprovado não é possivel alterar";
                String title = "Confirmação";
                int reply = JOptionPane.showConfirmDialog(null, mensage, title, JOptionPane.YES_NO_OPTION);
                if(reply == JOptionPane.YES_OPTION) {
                    vendedor.getOrdem((int)TabelaOrdens.getValueAt(i, 0)).setAprovacao(true);
                    TabelaOrdens.setValueAt("Aprovado", i, 4);
                    TabelaOrdens.setValueAt("Em andamento", i, 5);
                }
            }
        }
    }//GEN-LAST:event_TabelaOrdensMouseClicked

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
            java.util.logging.Logger.getLogger(VisualizarOrdensPendentes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VisualizarOrdensPendentes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VisualizarOrdensPendentes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VisualizarOrdensPendentes.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VisualizarOrdensPendentes().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane OrdensPendentes;
    private javax.swing.JTable TabelaOrdens;
    private javax.swing.JButton Voltar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
