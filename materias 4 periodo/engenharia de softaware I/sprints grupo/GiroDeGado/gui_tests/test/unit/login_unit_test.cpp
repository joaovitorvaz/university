#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/loginscreen.h"
#include "../../../gui/entity/loginscreen.h"
#include "../ui_loginscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestLoginScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestLoginScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    LoginScreen* d;
    QString msgResult;
    //bool dialogoAberto;
};

TestLoginScreenGUI::TestLoginScreenGUI(QWidget* parent, Farm* f):QObject(parent){
    d = new LoginScreen(parent, f);
}

void TestLoginScreenGUI::casoDeUsoPrincipal_data(){


    // ENTRADA
    QTest::addColumn<QString>("Usuario");
    QTest::addColumn<QString>("Senha");
    QTest::addColumn<QPushButton*>("Button");
    // SAIDA

    QTest::newRow("login correto") << "admin" << "123" << d->ui_->loginButton;
    QTest::newRow("login errado")  << "Hello" << "HELLO" << d->ui_->loginButton;
    QTest::newRow("botão sair") << "" << "" << d->ui_->exitButton;

}

void TestLoginScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QString, Usuario);
    QFETCH(QString, Senha);
    QFETCH(QPushButton*, Button);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d->ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d->ui_->labelUser, "Campo não buildado");
    QVERIFY2(d->ui_->inputUser, "Campo não buildado");
    QVERIFY2(d->ui_->labelPassword, "Campo não buildado");
    QVERIFY2(d->ui_->inputPassword, "Campo não buildado");
    QVERIFY2(d->ui_->loginButton, "Campo não buildado");
    QVERIFY2(d->ui_->exitButton, "Campo não buildado");

    QTest::keyClicks(d->ui_->inputUser, Usuario);
    QTest::keyClicks(d->ui_->inputPassword, Senha);
    QTest::mouseClick(Button, Qt::LeftButton);

    QCOMPARE(d->isVisible(),false);


}

void TestLoginScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "login_unit_test.moc"
