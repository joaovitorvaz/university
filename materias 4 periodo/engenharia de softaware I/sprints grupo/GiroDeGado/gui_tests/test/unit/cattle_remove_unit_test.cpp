#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <QRadioButton>
#include <iostream>

#include "../../../gui/entity/cattleremovescreen.h"
#include "../../../gui/entity/cattlemanagementscreen.h"
#include "../ui_cattleremovescreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestCattleRemoveScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestCattleRemoveScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    CattleRemoveScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestCattleRemoveScreenGUI::TestCattleRemoveScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new CattleManagementScreen();
}

void TestCattleRemoveScreenGUI::casoDeUsoPrincipal_data(){
    // ENTRADA
    QTest::addColumn<QString>("Brinco");
    QTest::addColumn<QRadioButton*>("Venda");
    QTest::addColumn<QString>("Valor");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << d.ui_->radioButtonSell << "" << d.ui_->backButton;
    QTest::newRow("Remocao correto") << "1" << d.ui_->radioButtonSell << "10000" << d.ui_->okButton;
}

void TestCattleRemoveScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, Brinco);
    QFETCH(QRadioButton*, Venda);
    QFETCH(QString, Valor);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelCattleEarring, "Campo não buildado");
    QVERIFY2(d.ui_->inputCattleEarring, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->cattleRemoveTable, "Campo não buildado");
    QVERIFY2(d.ui_->labelReason, "Campo não buildado");
    QVERIFY2(d.ui_->radioButtonDeath, "Campo não buildado");
    QVERIFY2(d.ui_->radioButtonSell, "Campo não buildado");
    QVERIFY2(d.ui_->labelPrice, "Campo não buildado");
    QVERIFY2(d.ui_->inputPrice, "Campo não buildado");
    QVERIFY2(d.ui_->removeButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputCattleEarring, Brinco);
    QTest::mouseClick(Venda, Qt::LeftButton);
    QTest::keyClicks(d.ui_->inputPrice, Valor);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString earring = d.ui_->labelCattleEarring->text();
    earring.remove(0,1);
    QCOMPARE(d.farm_->getCattleEarring(earring.toInt()), "");
}

void TestCattleRemoveScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "cattle_remove_unit_test.moc"
