#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/signupscreen.h"
#include "../../../gui/entity/usermanagementscreen.h"
#include "../ui_signupscreen.h"
#include<iostream>

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestSignUpScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestSignUpScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    SignUpScreen* d;
    QString msgResult;
    //bool dialogoAberto;
};

TestSignUpScreenGUI::TestSignUpScreenGUI(QWidget *parent, Farm* f):QObject(parent){

   d = new SignUpScreen(parent, new UserManagementScreen(), nullptr, f, "");

}

void TestSignUpScreenGUI::casoDeUsoPrincipal_data(){


    // ENTRADA
    QTest::addColumn<QString>("Nome");
    QTest::addColumn<QString>("DataB");
    QTest::addColumn<QString>("Usuario");
    QTest::addColumn<QString>("Senha");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << "" << "" << "" << d->ui_->backButton;
    QTest::newRow("Registro correto") << "Brangus" << "01/12/2001" << "user1" << "123" << d->ui_->signButton;
}

void TestSignUpScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QString, Nome);
    QFETCH(QString, DataB);
    QFETCH(QString, Usuario);
    QFETCH(QString, Senha);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d->ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d->ui_->labelSearchUser, "Campo não buildado");
    QVERIFY2(d->ui_->inputName, "Campo não buildado");
    QVERIFY2(d->ui_->labelBirthDate, "Campo não buildado");
    QVERIFY2(d->ui_->dateEdit, "Campo não buildado");
    QVERIFY2(d->ui_->labelUserType, "Campo não buildado");
    QVERIFY2(d->ui_->userType, "Campo não buildado");
    QVERIFY2(d->ui_->labelNickname, "Campo não buildado");
    QVERIFY2(d->ui_->inputNickname, "Campo não buildado");
    QVERIFY2(d->ui_->labelPassword, "Campo não buildado");
    QVERIFY2(d->ui_->inputPassword, "Campo não buildado");
    QVERIFY2(d->ui_->signButton, "Campo não buildado");
    QVERIFY2(d->ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d->ui_->inputName, Nome);
    QTest::keyClicks(d->ui_->dateEdit, DataB);
    QTest::keyClicks(d->ui_->inputNickname, Usuario);
    QTest::keyClicks(d->ui_->inputPassword, Senha);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString user = d->ui_->inputNickname->text();
    QCOMPARE(d->farm_->getUserNickname(user.toUtf8().constData()), Usuario);

}

void TestSignUpScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "signup_unit_test.moc"
