#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <QRadioButton>
#include <iostream>

#include "../../../gui/entity/financialrecordscreen.h"
#include "../../../gui/entity/financialmanagementscreen.h"
#include "../ui_financialrecordscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestFinancialRecordScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestFinancialRecordScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    FinancialRecordScreen* d;
    QString msgResult;
    //bool dialogoAberto;
};

TestFinancialRecordScreenGUI::TestFinancialRecordScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    d = new FinancialRecordScreen(parent, new FinancialManagementScreen(), nullptr, f, "");
}

void TestFinancialRecordScreenGUI::casoDeUsoPrincipal_data(){
    // ENTRADA
    QTest::addColumn<QString>("Valor");
    QTest::addColumn<QString>("Data");
    QTest::addColumn<QString>("Brinco");
    QTest::addColumn<QString>("Descricao");
    QTest::addColumn<QPushButton*>("Botao");

    // SAIDA
    QTest::newRow("Botao de Voltar") << "" << "" << "" << "" << d->ui_->backButton;
    QTest::newRow("Registro correto") << "2000" << "10/10/20" << "2" << "Compra de alimento" << d->ui_->registerButton;
}

void TestFinancialRecordScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, Valor);
    QFETCH(QString, Data);
    QFETCH(QString, Brinco);
    QFETCH(QString, Descricao);
    QFETCH(QPushButton*, Botao);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d->ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d->ui_->labelTransaction, "Campo não buildado");
    QVERIFY2(d->ui_->labelIdTransaction, "Campo não buildado");
    QVERIFY2(d->ui_->labelPrice, "Campo não buildado");
    QVERIFY2(d->ui_->inputPrice, "Campo não buildado");
    QVERIFY2(d->ui_->labelDate, "Campo não buildado");
    QVERIFY2(d->ui_->inputDate, "Campo não buildado");
    QVERIFY2(d->ui_->labelEarring, "Campo não buildado");
    QVERIFY2(d->ui_->inputEarring, "Campo não buildado");
    QVERIFY2(d->ui_->labelDescription, "Campo não buildado");
    QVERIFY2(d->ui_->inputDescription, "Campo não buildado");
    QVERIFY2(d->ui_->registerButton, "Campo não buildado");
    QVERIFY2(d->ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d->ui_->inputPrice, Valor);
    QTest::keyClicks(d->ui_->inputDate, Data);
    QTest::keyClicks(d->ui_->inputEarring, Brinco);
    QTest::keyClicks(d->ui_->inputDescription, Descricao);
    QTest::mouseClick(Botao, Qt::LeftButton);

    QString id = d->ui_->labelIdTransaction->text();
    id.remove(0,1);

    QCOMPARE(d->farm_->getTransactionCattleEarring(id.toInt()), Brinco);
}

void TestFinancialRecordScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "financial_record_unit_test.moc"
