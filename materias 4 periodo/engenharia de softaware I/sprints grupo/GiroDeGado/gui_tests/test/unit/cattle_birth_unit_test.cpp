#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/cattlebirthscreen.h"
#include "../../../gui/entity/cattleregisterscreen.h"
#include "../ui_cattlebirthscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestCattleBirthScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestCattleBirthScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    CattleBirthScreen* d;
    QString msgResult;
    //bool dialogoAberto;
};

TestCattleBirthScreenGUI::TestCattleBirthScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d = new CattleBirthScreen(parent, new CattleRegisterScreen(), nullptr, f, "");
}

void TestCattleBirthScreenGUI::casoDeUsoPrincipal_data(){
    // ENTRADA
    QTest::addColumn<QString>("Raca");
    QTest::addColumn<QString>("Pai");
    QTest::addColumn<QString>("Mae");
    QTest::addColumn<QString>("Data");
    QTest::addColumn<QString>("Peso");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << "" << "" << "" << "" << d->ui_->backButton;
    QTest::newRow("Cadastro correto") << "Brangus" << "1" << "2" << "10/10/20" << "200" << d->ui_->registerButton;
}

void TestCattleBirthScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, Raca);
    QFETCH(QString, Pai);
    QFETCH(QString, Mae);
    QFETCH(QString, Data);
    QFETCH(QString, Peso);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d->ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d->ui_->labelEarring, "Campo não buildado");
    QVERIFY2(d->ui_->labelCattleEarring, "Campo não buildado");
    QVERIFY2(d->ui_->labelBreed, "Campo não buildado");
    QVERIFY2(d->ui_->inputBreed, "Campo não buildado");
    QVERIFY2(d->ui_->labelFather, "Campo não buildado");
    QVERIFY2(d->ui_->inputFather, "Campo não buildado");
    QVERIFY2(d->ui_->labelMother, "Campo não buildado");
    QVERIFY2(d->ui_->inputMother, "Campo não buildado");
    QVERIFY2(d->ui_->labelDate, "Campo não buildado");
    QVERIFY2(d->ui_->inputDate, "Campo não buildado");
    QVERIFY2(d->ui_->labelWeight, "Campo não buildado");
    QVERIFY2(d->ui_->inputWeight, "Campo não buildado");
    QVERIFY2(d->ui_->registerButton, "Campo não buildado");
    QVERIFY2(d->ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d->ui_->inputBreed, Raca);
    QTest::keyClicks(d->ui_->inputFather, Pai);
    QTest::keyClicks(d->ui_->inputMother, Mae);
    QTest::keyClicks(d->ui_->inputDate, Data);
    QTest::keyClicks(d->ui_->inputWeight, Peso);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString earring = d->ui_->labelCattleEarring->text();
    earring.remove(0,1);
    QCOMPARE(d->farm_->getCattleBreed(earring.toInt()), Raca);
}

void TestCattleBirthScreenGUI::timeOut(){

    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }

}

#include "cattle_birth_unit_test.moc"
