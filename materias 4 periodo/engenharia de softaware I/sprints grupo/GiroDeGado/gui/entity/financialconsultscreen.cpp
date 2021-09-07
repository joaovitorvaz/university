#include "financialconsultscreen.h"
#include "ui_financialconsultscreen.h"

FinancialConsultScreen::FinancialConsultScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::FinancialConsultScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

FinancialConsultScreen::~FinancialConsultScreen()
{
    delete ui_;
}

void FinancialConsultScreen::on_okButton_clicked()
{
    Farm* f = getFarm();

    QString transaction_date = ui_->inputTransactionDate->text();
    auto table = ui_->transactionConsultTable;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Reseting the table of transactions (transactionConsultTable)
    table->clear();
    table->setHorizontalHeaderLabels({"ID", "Operação", "Valor", "Descrição", "Brinco do gado"});

    while(table->rowCount() != 0){
        table->removeRow(table->rowCount()-1);
    }

    // Adding the transactions that have the same date as the input to the table (transactionConsultTable)
    if(transaction_date != ""){
        f->queryExec("select * from financial where date='"+transaction_date+"'");
        QString number;
        QString value;
        double value_2;
        QString description;
        QString cattle_earring;
        QString operacao;

        while(f->queryNext()){
            number = f->queryValue(1);
            value = f->queryValue(3);
            cattle_earring = f->queryValue(4);
            description = f->queryValue(5);
            value_2 = value.toDouble();

            if(value_2 <= 0)
                operacao = QString::fromStdString("Despesa");
            else
                operacao = QString::fromStdString("Ganho");

            table->insertRow(table->rowCount());
            table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(number));
            table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(operacao));
            table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(value));
            table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(description));
            table->setItem(table->rowCount()-1, 4, new QTableWidgetItem(cattle_earring));
        }
    }
}

void FinancialConsultScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* FinancialConsultScreen::getFarm()
{
    return farm_;
}
