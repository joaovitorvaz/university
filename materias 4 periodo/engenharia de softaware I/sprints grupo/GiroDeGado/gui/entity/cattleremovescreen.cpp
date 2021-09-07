#include "cattleremovescreen.h"
#include "ui_cattleremovescreen.h"

CattleRemoveScreen::CattleRemoveScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleRemoveScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

CattleRemoveScreen::~CattleRemoveScreen()
{
    delete ui_;
}

void CattleRemoveScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void CattleRemoveScreen::on_okButton_clicked()
{
    int cattle_earring = ui_->inputCattleEarring->text().toInt();
    Farm* f = getFarm();
    auto model = ui_->cattleRemoveTable->model();

    QString earring = f->getCattleEarring(cattle_earring);

    if(earring != ""){
        QString breed = f->getCattleBreed(cattle_earring);
        QString acquisition_date = f->getCattleAcquisitionDate(cattle_earring);
        QString birth_date = f->getCattleBirthDate(cattle_earring);
        QString father = f->getCattleFather(cattle_earring);
        QString mother = f->getCattleMother(cattle_earring);
        QString weight = f->getCattleWeight(cattle_earring);
        QString value = f->getCattleValue(cattle_earring);

        model->setData(model->index(0,0),earring);
        model->setData(model->index(0,1),breed);
        model->setData(model->index(0,2),acquisition_date);
        model->setData(model->index(0,3),birth_date);
        model->setData(model->index(0,4),father);
        model->setData(model->index(0,5),mother);
        model->setData(model->index(0,6),weight);
        model->setData(model->index(0,7),value);
    }
    else{
        model->setData(model->index(0,0),QString("INVALIDO"));
        model->setData(model->index(0,1),QString("INVALIDO"));
        model->setData(model->index(0,2),QString("INVALIDO"));
        model->setData(model->index(0,3),QString("INVALIDO"));
        model->setData(model->index(0,4),QString("INVALIDO"));
        model->setData(model->index(0,5),QString("INVALIDO"));
        model->setData(model->index(0,6),QString("INVALIDO"));
        model->setData(model->index(0,7),QString("INVALIDO"));
    }
}


void CattleRemoveScreen::on_removeButton_clicked()
{
    QString cattle_earring = ui_->inputCattleEarring->text();
    auto earring = ui_->cattleRemoveTable->item(0,0)->text();

    if(cattle_earring != "" && earring != "INVALIDO" && earring != ""){
        int earring_2 = earring.toInt();

        Farm* f = getFarm();
        f->deleteCattle(earring_2);

        if(ui_->radioButtonSell->isChecked()){
            int number = farm_->getLastNumberAvailable();

            QString price = ui_->inputPrice->text();
            if(price != ""){
                double price_2 = price.toDouble();

                f->createTransaction(number, price_2, "Venda de Gado", "A DEFINIR", earring_2);
            }
        }

        back_screen_->show();
        this->close();
    }
}

Farm* CattleRemoveScreen::getFarm()
{
    return farm_;
}

void CattleRemoveScreen::on_radioButtonDeath_clicked()
{
    ui_->inputPrice->setText("");
    ui_->labelPrice->setVisible(false);
    ui_->inputPrice->setVisible(false);
}

void CattleRemoveScreen::on_radioButtonSell_clicked()
{
    ui_->inputPrice->setVisible(true);
    ui_->labelPrice->setVisible(true);
    ui_->inputPrice->setText("0");
}
