#include "cattleeditscreen.h"
#include "ui_cattleeditscreen.h"

CattleEditScreen::CattleEditScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleEditScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

CattleEditScreen::~CattleEditScreen()
{
    delete ui_;
}

void CattleEditScreen::on_okButton_clicked()
{
    int cattle_earring = ui_->inputEarring->text().toInt();
    Farm* f = getFarm();

    QString earring = f->getCattleEarring(cattle_earring);

    if(earring != ""){
        QString breed = f->getCattleBreed(cattle_earring);
        QString acquisition_date = f->getCattleAcquisitionDate(cattle_earring);
        QString birth_date = f->getCattleBirthDate(cattle_earring);
        QString father = f->getCattleFather(cattle_earring);
        QString mother = f->getCattleMother(cattle_earring);
        QString weight = f->getCattleWeight(cattle_earring);
        QString value = f->getCattleValue(cattle_earring);

        ui_->inputBreed->setText(breed);
        ui_->inputDateA->setText(acquisition_date);
        ui_->inputDateB->setText(birth_date);
        ui_->inputFather->setText(father);
        ui_->inputMother->setText(mother);
        ui_->inputWeight->setText(weight);
        ui_->inputPrice->setText(value);
    }
    else{
        ui_->inputBreed->setText(QString("INVALIDO"));
        ui_->inputDateA->setText(QString("INVALIDO"));
        ui_->inputDateB->setText(QString("INVALIDO"));
        ui_->inputFather->setText(QString("0"));
        ui_->inputMother->setText(QString("0"));
        ui_->inputWeight->setText(QString("0.0"));
        ui_->inputPrice->setText(QString("0.0"));
    }
}


void CattleEditScreen::on_editButton_clicked()
{
    QString cattle_earring = ui_->inputEarring->text();
    std::string breed = ui_->inputBreed->text().toLocal8Bit().constData();

    if(cattle_earring != "" && breed != "INVALIDO" && breed != ""){
        int earring = cattle_earring.toInt();

        Farm* f = getFarm();

        std::string acquisition_date = ui_->inputDateA->text().toLocal8Bit().constData();
        std::string birth_date = ui_->inputDateB->text().toLocal8Bit().constData();
        int father = ui_->inputFather->text().toInt();
        int mother = ui_->inputMother->text().toInt();
        double weight = ui_->inputWeight->text().toDouble();
        double price = ui_->inputPrice->text().toDouble();

        f->setCattleBreed(earring, breed);
        f->setCattleAcquisitionDate(earring, acquisition_date);
        f->setCattleBirthDate(earring, birth_date);
        f->setCattleFather(earring, father);
        f->setCattleMother(earring, mother);
        f->setCattleWeight(earring, weight);
        f->setCattleValue(earring, price);

        back_screen_->show();
        this->close();
    }
}


void CattleEditScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* CattleEditScreen::getFarm()
{
    return farm_;
}

