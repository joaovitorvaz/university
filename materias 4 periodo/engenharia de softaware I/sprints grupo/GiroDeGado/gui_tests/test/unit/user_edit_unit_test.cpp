#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/usereditscreen.h"
#include "../../../gui/entity/usermanagementscreen.h"
#include "../ui_usereditscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestUserEditScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestUserEditScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    UserEditScreen d;
    QString msgResult;
};

TestUserEditScreenGUI::TestUserEditScreenGUI(QWidget *parent, Farm* f):QObject(parent){

    d.farm_ = f;
    d.back_screen_ = new UserManagementScreen();

}

void TestUserEditScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QString>("Usuario");
    QTest::addColumn<QPushButton*>("Botao");
    QTest::addColumn<QString>("Nome");
    QTest::addColumn<QString>("DataB");
    QTest::addColumn<QString>("NovoUsuario");
    QTest::addColumn<QString>("Senha");
    QTest::addColumn<QPushButton*>("Confirmar");

    // SAIDA
    QTest::newRow("Edicao correta") << "user1" << d.ui_->okButton << "Mateus" << "02/10/20" << "user2" << "1234" << d.ui_->signButton;

}

void TestUserEditScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QString, Usuario);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelNickname, "Campo não buildado");
    QVERIFY2(d.ui_->inputNickname, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->labelName, "Campo não buildado");
    QVERIFY2(d.ui_->inputName, "Campo não buildado");
    QVERIFY2(d.ui_->labelBirthDate, "Campo não buildado");
    QVERIFY2(d.ui_->dateEdit, "Campo não buildado");
    QVERIFY2(d.ui_->labelUserType, "Campo não buildado");
    QVERIFY2(d.ui_->userType, "Campo não buildado");
    QVERIFY2(d.ui_->labelNewNickname, "Campo não buildado");
    QVERIFY2(d.ui_->inputNewNickname, "Campo não buildado");
    QVERIFY2(d.ui_->labelPassword, "Campo não buildado");
    QVERIFY2(d.ui_->inputPassword, "Campo não buildado");
    QVERIFY2(d.ui_->signButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputNickname, Usuario);
    QTest::mouseClick(Botao, Qt::LeftButton);

    d.ui_->inputName->clear();
    d.ui_->dateEdit->clear();
    d.ui_->inputNewNickname->clear();
    d.ui_->inputPassword->clear();

    QFETCH(QString, Nome);
    QFETCH(QString, DataB);
    QFETCH(QString, NovoUsuario);
    QFETCH(QString, Senha);

    QFETCH(QPushButton*, Confirmar);
    QTest::keyClicks(d.ui_->inputName, Nome);
    QTest::keyClicks(d.ui_->dateEdit, DataB);
    QTest::keyClicks(d.ui_->inputNewNickname, NovoUsuario);
    QTest::keyClicks(d.ui_->inputPassword, Senha);
    QTest::mouseClick(Confirmar, Qt::LeftButton);


    QCOMPARE(d.farm_->getUserName(NovoUsuario.toUtf8().toStdString()), Nome);
}

void TestUserEditScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "user_edit_unit_test.moc"
