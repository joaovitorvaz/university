#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/userqueryscreen.h"
#include "../../../gui/entity/usermanagementscreen.h"
#include "../ui_userqueryscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestUserConsultScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestUserConsultScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    UserQueryScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestUserConsultScreenGUI::TestUserConsultScreenGUI(QWidget *parent, Farm* f):QObject(parent){

    d.farm_ = f;
    d.back_screen_ = new UserManagementScreen();

}

void TestUserConsultScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QString>("Usuario");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << d.ui_->backButton;
    QTest::newRow("Consulta correta") << "user1" << d.ui_->okButton;

}

void TestUserConsultScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QString, Usuario);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->labelNickname, "Campo não buildado");
    QVERIFY2(d.ui_->inputNickname, "Campo não buildado");
    QVERIFY2(d.ui_->okButton, "Campo não buildado");
    QVERIFY2(d.ui_->userQueryTable, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d.ui_->inputNickname, Usuario);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString user = d.ui_->userQueryTable->item(0,0)->text();
    QCOMPARE(d.farm_->getUserNickname(user.toUtf8().toStdString()), Usuario);

}

void TestUserConsultScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "user_consult_unit_test.moc"
