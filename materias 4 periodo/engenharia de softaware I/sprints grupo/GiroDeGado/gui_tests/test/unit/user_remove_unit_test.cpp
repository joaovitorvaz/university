#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/userremovescreen.h"
#include "../../../gui/entity/usermanagementscreen.h"
#include "../ui_userremovescreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestUserRemoveScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestUserRemoveScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    UserRemoveScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestUserRemoveScreenGUI::TestUserRemoveScreenGUI(QWidget *parent, Farm* f):QObject(parent){

    d.farm_ = f;
    d.back_screen_ = new UserManagementScreen();

}

void TestUserRemoveScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QString>("Usuario");
    QTest::addColumn<QPushButton*>("Botao");
    QTest::addColumn<QPushButton*>("Remover");

    // SAIDA
    QTest::newRow("Botao de Voltar") <<  "" << d.ui_->backButton << d.ui_->backButton;
    QTest::newRow("Remocao correta") << "user1" << d.ui_->okButton << d.ui_->removeButton;


}

void TestUserRemoveScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QString, Usuario);
    QFETCH(QPushButton*, Botao);
    QFETCH(QPushButton*, Remover);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelNickname, "Campo não buildado");
    QVERIFY2(d.ui_->inputNickname, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->removeButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputNickname, Usuario);
    QTest::mouseClick(Botao, Qt::LeftButton);    
    QTest::mouseClick(Remover, Qt::LeftButton);


    QCOMPARE(d.farm_->getUserNickname(Usuario.toUtf8().toStdString()), "");
}

void TestUserRemoveScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "user_remove_unit_test.moc"
