#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/financialmanagementscreen.h"
#include "../../../gui/entity/homescreen.h"
#include "ui_financialmanagementscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestFinancialManagementScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestFinancialManagementScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    FinancialManagementScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

 TestFinancialManagementScreenGUI::TestFinancialManagementScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new HomeScreen();
}

void TestFinancialManagementScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QPushButton*>("botao");

    // SAIDA
    QTest::newRow("Botao de Cadastro") << d.ui_->registerButton;
    QTest::newRow("Botao de Consulta") << d.ui_->queryButton;
    QTest::newRow("Botao de Remocao") << d.ui_->removeButton;
    QTest::newRow("Botao de Voltar") << d.ui_->backButton;

}

void TestFinancialManagementScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QPushButton*, botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "label GiroDeGado não buildado");
    QVERIFY2(d.ui_->registerButton, "botao Registro não buildado");
    QVERIFY2(d.ui_->queryButton, "botao Consultar não buildado");
    QVERIFY2(d.ui_->reportButton, "botao Relatorio não buildado");
    QVERIFY2(d.ui_->removeButton, "botao Consultar Transação não buildado");
    QVERIFY2(d.ui_->backButton, "botao voltar não buildado");

    QTest::mouseClick(botao, Qt::LeftButton);

    QCOMPARE(d.isVisible(), false);
}

void TestFinancialManagementScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "financial_management_unit_test.moc"
