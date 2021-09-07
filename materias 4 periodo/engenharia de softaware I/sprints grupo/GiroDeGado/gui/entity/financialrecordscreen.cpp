#include "financialrecordscreen.h"
#include "ui_financialrecordscreen.h"

FinancialRecordScreen::FinancialRecordScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::FinancialRecordScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);

    int number = farm_->getLastNumberAvailable();
    QString number_str = QString::number(number);

    ui_->labelIdTransaction->setText("#" + number_str);
}

FinancialRecordScreen::~FinancialRecordScreen()
{
    delete ui_;
}

void FinancialRecordScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void FinancialRecordScreen::on_registerButton_clicked()
{
    int number = farm_->getLastNumberAvailable();

    QString price = ui_->inputPrice->text();
    double price_2 = price.toDouble();

    QString description = ui_->inputDescription->toPlainText();
    std::string description_2 = description.toLocal8Bit().constData();

    QString date = ui_->inputDate->text();
    std::string date_2 = date.toLocal8Bit().constData();

    QString earring = ui_->inputEarring->text();
    int earring_2 = earring.toInt();

    if(price_2 != 0){
        Farm* f = getFarm();
        f->createTransaction(number, price_2, description_2, date_2, earring_2);
        back_screen_->show();
        this->close();
    }
    else{
        ui_->inputPrice->setText("0.0");

        if(description_2 == "")
            ui_->inputDescription->setText("A DEFINIR");

        if(date_2 == "")
            ui_->inputDate->setText("A DEFINIR");

        if(earring_2 == 0)
            ui_->inputEarring->setText("A DEFINIR");
    }

}

Farm* FinancialRecordScreen::getFarm()
{
    return farm_;
}
