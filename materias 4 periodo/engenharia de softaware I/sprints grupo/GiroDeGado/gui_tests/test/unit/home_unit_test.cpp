#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/homescreen.h"
#include "../../../gui/entity/loginscreen.h"
#include "../ui_homescreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestHomeScreenGUI: public QObject
{
    Q_OBJECT

public:
    explicit TestHomeScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    HomeScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestHomeScreenGUI::TestHomeScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d.farm_ = f;
    d.back_screen_ = new LoginScreen(parent, f);
}

void TestHomeScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QPushButton*>("botao");    

    // SAIDA
    QTest::newRow("Botao de Gado") << d.ui_->cattleButton;
    QTest::newRow("Botao de Financeiro") << d.ui_->financialButton;
    //QTest::newRow("Botao de Usuario") << d.ui_->userButton;
    //QTest::newRow("Botao de Saida") << d.ui_->logoutButton;

}

void TestHomeScreenGUI::casoDeUsoPrincipal(){
        QFETCH(QPushButton*, botao);

        QTimer::singleShot(500, this, SLOT(timeOut()));

        // Verifica se os componentes da tela estao sendo buildados corretamente.
        QVERIFY2(d.ui_->label, "Campo não buildado");
        QVERIFY2(d.ui_->cattleButton, "Campo não buildado");
        QVERIFY2(d.ui_->financialButton, "Campo não buildado");
        QVERIFY2(d.ui_->userButton, "Campo não buildado");
        QVERIFY2(d.ui_->logoutButton, "Campo não buildado");


        QTest::mouseClick(botao, Qt::LeftButton);

}

void TestHomeScreenGUI::timeOut(){

    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "home_unit_test.moc"
