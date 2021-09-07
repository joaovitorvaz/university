#include "cattlebuyscreen.h"
#include "ui_cattlebuyscreen.h"

CattleBuyScreen::CattleBuyScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleBuyScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);

    int earring = farm_->getLastEarringAvailable();
    QString earring_str = QString::number(earring);

    ui_->labelCattleEarring->setText("#" + earring_str);
}

CattleBuyScreen::~CattleBuyScreen()
{
    delete ui_;
}

void CattleBuyScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void CattleBuyScreen::on_registerButton_clicked()
{
    int earring = farm_->getLastEarringAvailable();

    QString breed = ui_->inputBreed->text();
    std::string breed_2 = breed.toLocal8Bit().constData();

    QString dateA = ui_->inputDateA->text();
    std::string dateA_2 = dateA.toLocal8Bit().constData();

    QString dateB = ui_->inputDateB->text();
    std::string dateB_2 = dateB.toLocal8Bit().constData();

    QString price = ui_->inputPrice->text();
    double price_2 = price.toDouble();

    QString weight = ui_->inputWeight->text();
    double weight_2 = weight.toDouble();

    if(price != "" && price_2 != 0){
        Farm* f = getFarm();
        f->createCattle(earring, breed_2, dateA_2, dateB_2, 0, 0, weight_2, price_2);

        int number = farm_->getLastNumberAvailable();

        f->createTransaction(number, price_2, "Compra de Gado", dateA_2, earring);

        back_screen_->show();
        this->close();
    }
    else{
        if(breed_2 == "")
            ui_->inputBreed->setText("A DEFINIR");

        if(dateA_2 == "")
            ui_->inputDateA->setText("A DEFINIR");

        if(dateB_2 == "")
            ui_->inputDateB->setText("A DEFINIR");

        if(weight == "" || weight == "0")
            ui_->inputWeight->setText("0.0");
    }
}

Farm* CattleBuyScreen::getFarm()
{
    return farm_;
}
