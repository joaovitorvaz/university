#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/usermanagementscreen.h"
#include "../../../gui/entity/homescreen.h"
#include "../ui_usermanagementscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestUserManagementScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestUserManagementScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    UserManagementScreen d;
    QString msgResult;
    //bool dialogoAberto;
};

TestUserManagementScreenGUI::TestUserManagementScreenGUI(QWidget *parent, Farm* f):QObject(parent){

    d.farm_ = f;
    d.back_screen_ = new HomeScreen();

}

void TestUserManagementScreenGUI::casoDeUsoPrincipal_data(){


    // ENTRADA
    QTest::addColumn<QPushButton*>("botao");   

    // SAIDA
    QTest::newRow("Botao de Registro") << d.ui_->registerButton;
    QTest::newRow("Botao de Consulta") << d.ui_->queryButton;
    QTest::newRow("Botao de Remocao") << d.ui_->removeButton;
    QTest::newRow("Botao de Voltar") << d.ui_->backButton;

}

void TestUserManagementScreenGUI::casoDeUsoPrincipal(){


    QFETCH(QPushButton*, botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d.ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d.ui_->registerButton, "Campo não buildado");
    QVERIFY2(d.ui_->queryButton, "Campo não buildado");
    QVERIFY2(d.ui_->removeButton, "Campo não buildado");
    QVERIFY2(d.ui_->backButton, "Campo não buildado");

    QTest::mouseClick(botao, Qt::LeftButton);

    QCOMPARE(d.isVisible(),false);

}

void TestUserManagementScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != &d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "user_management_unit_test.moc"
