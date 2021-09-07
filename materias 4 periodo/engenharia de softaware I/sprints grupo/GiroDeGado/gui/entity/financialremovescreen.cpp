#include "financialremovescreen.h"
#include "ui_financialremovescreen.h"

FinancialRemoveScreen::FinancialRemoveScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::FinancialRemoveScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

FinancialRemoveScreen::~FinancialRemoveScreen()
{
    delete ui_;
}

void FinancialRemoveScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}


void FinancialRemoveScreen::on_okButton_clicked()
{
    int transaction_id = ui_->inputIdTransaction->text().toInt();
    Farm* f = getFarm();
    auto model = ui_->transactionRemoveTable->model();

    QString number = f->getTransactionNumber(transaction_id);

    if(number != ""){
        QString date = f->getTransactionDate(transaction_id);
        QString value = f->getTransactionValue(transaction_id);
        QString cattle_earring = f->getTransactionCattleEarring(transaction_id);
        QString description = f->getTransactionDescription(transaction_id);

        model->setData(model->index(0,0),number);
        model->setData(model->index(0,1),date);
        model->setData(model->index(0,2),value);
        model->setData(model->index(0,3),cattle_earring);
        model->setData(model->index(0,4),description);
    }
    else{
        model->setData(model->index(0,0),QString("INVALIDO"));
        model->setData(model->index(0,1),QString("INVALIDO"));
        model->setData(model->index(0,2),QString("INVALIDO"));
        model->setData(model->index(0,3),QString("INVALIDO"));
        model->setData(model->index(0,4),QString("INVALIDO"));
    }
}


void FinancialRemoveScreen::on_removeButton_clicked()
{
    QString transaction_id = ui_->inputIdTransaction->text();
    auto number = ui_->transactionRemoveTable->item(0,0)->text();

    if(transaction_id != "" && number != "INVALIDO" && number != ""){
        int number_2 = number.toInt();

        Farm* f = getFarm();
        f->deleteTransaction(number_2);

        back_screen_->show();
        this->close();
    }

}

Farm* FinancialRemoveScreen::getFarm()
{
    return farm_;
}
