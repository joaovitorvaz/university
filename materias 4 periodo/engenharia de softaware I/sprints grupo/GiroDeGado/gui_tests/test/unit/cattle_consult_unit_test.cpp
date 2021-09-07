#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/cattleconsultscreen.h"
#include "../../../gui/entity/cattlemanagementscreen.h"
#include "../ui_cattleconsultscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestCattleConsultScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestCattleConsultScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    CattleConsultScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestCattleConsultScreenGUI::TestCattleConsultScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new CattleManagementScreen();
}

void TestCattleConsultScreenGUI::casoDeUsoPrincipal_data(){
    // ENTRADA
    QTest::addColumn<QString>("Brinco");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << d.ui_->backButton;
    QTest::newRow("Consulta correta") << "1" << d.ui_->okButton;
}

void TestCattleConsultScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, Brinco);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelCattleEarring, "Campo não buildado");
    QVERIFY2(d.ui_->inputCattleEarring, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->cattleConsultTable, "Campo não buildado");
    QVERIFY2(d.ui_->cattleTransactionTable, "Campo não buildado");
    QVERIFY2(d.ui_->labelAverageSpending,"Campo não buildado");
    QVERIFY2(d.ui_->labelValueAverageSpending, "Campo não buildado");
    QVERIFY2(d.ui_->labelAverageEarnings, "Campo não buildado");
    QVERIFY2(d.ui_->labelValueAverageEarnings, "Campo não buildado");
    QVERIFY2(d.ui_->labelTotalSpending, "Campo não buildado");
    QVERIFY2(d.ui_->labelValueTotalSpending, "Campo não buildado");
    QVERIFY2(d.ui_->labelTotalEarnings, "Campo não buildado");
    QVERIFY2(d.ui_->labelValueTotalEarnings, "Campo não buildado");
    QVERIFY2(d.ui_->labelProfit, "Campo não buildado");
    QVERIFY2(d.ui_->labelValueProfit, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputCattleEarring, Brinco);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString earring = d.ui_->cattleConsultTable->item(0,0)->text();
    QCOMPARE(d.farm_->getCattleEarring(earring.toInt()), Brinco);
}

void TestCattleConsultScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "cattle_consult_unit_test.moc"
