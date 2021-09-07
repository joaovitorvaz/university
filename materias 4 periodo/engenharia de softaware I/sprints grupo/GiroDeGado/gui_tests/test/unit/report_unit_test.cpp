#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <iostream>

#include "../../../gui/entity/reportscreen.h"
#include "../../../gui/entity/financialmanagementscreen.h"
#include "../ui_reportscreen.h"

// TESTE UNITARIO COMPORTAMENTAL (funcionalidade + transicoes)
class TestReportScreenGUI: public QObject
{
    Q_OBJECT

public:
  explicit TestReportScreenGUI(QWidget *parent = nullptr, Farm* f = nullptr);

private slots:

    void casoDeUsoPrincipal_data();
    void casoDeUsoPrincipal();    

    void timeOut();

private:
    ReportScreen* d;
    QString msgResult;
    //bool dialogoAberto;
};

TestReportScreenGUI::TestReportScreenGUI(QWidget *parent, Farm* f):QObject(parent){
    f->createTransaction(1, 200, "Venda", "01/10/20", 1);
    f->createTransaction(2, -200, "Compra", "01/10/20", 2);
    d = new ReportScreen(parent, new FinancialManagementScreen(), nullptr, f, "");
}

void TestReportScreenGUI::casoDeUsoPrincipal_data(){

    // ENTRADA
    QTest::addColumn<QString>("DataB");
    QTest::addColumn<QString>("DataE");
    QTest::addColumn<QPushButton*>("Ok");
    QTest::addColumn<QPushButton*>("Voltar");

    // SAIDA
    QTest::newRow("Consulta correta") << "01/10/20" << "01/10/20" << d->ui_->okButton << d->ui_->backButton;

}

void TestReportScreenGUI::casoDeUsoPrincipal(){

    QFETCH(QString, DataB);
    QFETCH(QString, DataE);
    QFETCH(QPushButton*, Ok);
    QFETCH(QPushButton*, Voltar);

    QTimer::singleShot(500, this, SLOT(timeOut()));

    // Verifica se os componentes da tela estao sendo buildados corretamente.
    QVERIFY2(d->ui_->labelTitle, "Campo não buildado");
    QVERIFY2(d->ui_->labelIntervalB, "Campo não buildado");
    QVERIFY2(d->ui_->dateIntervalB, "Campo não buildado");
    QVERIFY2(d->ui_->labelIntervalE, "Campo não buildado");
    QVERIFY2(d->ui_->dateIntervalE, "Campo não buildado");
    QVERIFY2(d->ui_->okButton, "Campo não buildado");
    QVERIFY2(d->ui_->reportTable, "Campo não buildado");
    QVERIFY2(d->ui_->backButton, "Campo não buildado");

    QTest::keyClicks(d->ui_->dateIntervalB, DataB);
    QTest::keyClicks(d->ui_->dateIntervalE, DataE);
    QTest::mouseClick(Ok, Qt::LeftButton);
    QTest::mouseClick(Voltar, Qt::LeftButton);

    QString earring = d->ui_->reportTable->item(0,0)->text();
    //std::cout << earring.toStdString() << std::endl;
    QCOMPARE(d->farm_->getTransactionCattleEarring(earring.toInt()), "1");
}

void TestReportScreenGUI::timeOut(){
    // Verificar e fechar message box
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QDialog") && w != d) {
            QDialog *mb = qobject_cast<QDialog*>(w);
            QTest::keyClick(mb, Qt::Key_Escape);
        }
    }
}

#include "report_unit_test.moc"
