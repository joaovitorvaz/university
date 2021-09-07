#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/financialremovescreen.h"
#include "../../../gui/entity/financialmanagementscreen.h"
#include "../ui_financialremovescreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestFinancialRemoveScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestFinancialRemoveScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    FinancialRemoveScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestFinancialRemoveScreenGUI::TestFinancialRemoveScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new FinancialManagementScreen();
}

void TestFinancialRemoveScreenGUI::casoDeUsoPrincipal_data(){
    // ENTRADA
    QTest::addColumn<QString>("Id");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << d.ui_->backButton;
    QTest::newRow("Remocao correta") << "2" << d.ui_->okButton;
}

void TestFinancialRemoveScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, Id);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelIdTransaction, "Campo não buildado");
    QVERIFY2(d.ui_->inputIdTransaction, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->removeButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputIdTransaction, Id);
    QTest::mouseClick(Botao, Qt::LeftButton);

    //QCOMPARE(d.farm_->getTransactionNumber(Id.toInt()), "");

}

void TestFinancialRemoveScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "financial_remove_unit_test.moc"
