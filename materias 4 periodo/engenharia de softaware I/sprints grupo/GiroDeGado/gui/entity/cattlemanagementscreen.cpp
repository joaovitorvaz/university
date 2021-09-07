#include "cattlemanagementscreen.h"
#include "cattleregisterscreen.h"
#include "cattleconsultscreen.h"
#include "cattleeditscreen.h"
#include "cattleremovescreen.h"
#include "ui_cattlemanagementscreen.h"

CattleManagementScreen::CattleManagementScreen(QWidget* parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleManagementScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

CattleManagementScreen::~CattleManagementScreen()
{
    delete ui_;
}

void CattleManagementScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void CattleManagementScreen::on_registerButton_clicked()
{
    CattleRegisterScreen* cattleRegister = new CattleRegisterScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    cattleRegister->show();
}

void CattleManagementScreen::on_queryButton_clicked()
{
    CattleConsultScreen* cattleConsult = new CattleConsultScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    cattleConsult->show();
}

void CattleManagementScreen::on_updateButton_clicked()
{
    CattleEditScreen* cattleEdit = new CattleEditScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    cattleEdit->show();
}

void CattleManagementScreen::on_removeButton_clicked()
{
    CattleRemoveScreen* remove = new CattleRemoveScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    remove->show();
}

Farm* CattleManagementScreen::getFarm()
{
    return farm_;
}
