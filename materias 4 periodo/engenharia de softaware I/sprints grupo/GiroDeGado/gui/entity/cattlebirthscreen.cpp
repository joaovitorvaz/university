#include "cattlebirthscreen.h"
#include "ui_cattlebirthscreen.h"

CattleBirthScreen::CattleBirthScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleBirthScreen)
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

CattleBirthScreen::~CattleBirthScreen()
{
    delete ui_;
}

void CattleBirthScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void CattleBirthScreen::on_registerButton_clicked()
{
    int earring = farm_->getLastEarringAvailable();

    QString breed = ui_->inputBreed->text();
    std::string breed_2 = breed.toLocal8Bit().constData();

    QString date = ui_->inputDate->text();
    std::string date_2 = date.toLocal8Bit().constData();

    QString father = ui_->inputFather->text();
    int father_2 = father.toInt();

    QString mother = ui_->inputMother->text();
    int mother_2 = mother.toInt();

    QString weight = ui_->inputWeight->text();
    double weight_2 = weight.toDouble();

    if(date != "" && date != "INVALIDO"){
        Farm* f = getFarm();
        f->createCattle(earring, breed_2, date_2, date_2, father_2, mother_2, weight_2, 0.0);

        back_screen_->show();
        this->close();
    }
    else{
        if(breed_2 == "")
            ui_->inputBreed->setText("A DEFINIR");

        if(date_2 == "")
            ui_->inputDate->setText("INVALIDO");

        if(father == "" || father == "0")
            ui_->inputFather->setText("0.0");

        if(mother == "")
            ui_->inputMother->setText("0");

        if(weight == "")
            ui_->inputWeight->setText("0");
    }
}

Farm* CattleBirthScreen::getFarm()
{
    return farm_;
}
