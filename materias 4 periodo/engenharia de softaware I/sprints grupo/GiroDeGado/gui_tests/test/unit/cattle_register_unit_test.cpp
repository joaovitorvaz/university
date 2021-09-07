#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/cattleregisterscreen.h"
#include "../../../gui/entity/cattlemanagementscreen.h"
#include "../ui_cattleregisterscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestCattleRegisterScreenGUI: public QObject
{
    Q_OBJECT

public:
    explicit TestCattleRegisterScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    CattleRegisterScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestCattleRegisterScreenGUI::TestCattleRegisterScreenGUI(QWidget *parent,Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new CattleManagementScreen();
}

void TestCattleRegisterScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QPushButton*>("botao");

    // SAIDA
    QTest::newRow("Botao de Compra") << d.ui_->buyButton;
    QTest::newRow("Botao de Parto") << d.ui_->birthButton;
    QTest::newRow("Botao de Voltar") << d.ui_->backButton;

}

void TestCattleRegisterScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QPushButton*, botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->buyButton, "Campo não buildado");
    QVERIFY2(d.ui_->birthButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::mouseClick(botao, Qt::LeftButton);
}

void TestCattleRegisterScreenGUI::timeOut(){

    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }

}

#include "cattle_register_unit_test.moc"
