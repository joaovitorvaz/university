#include "cattleregisterscreen.h"
#include "cattlebuyscreen.h"
#include "cattlebirthscreen.h"
#include "ui_cattleregisterscreen.h"

CattleRegisterScreen::CattleRegisterScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleRegisterScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

CattleRegisterScreen::~CattleRegisterScreen()
{
    delete ui_;
}

void CattleRegisterScreen::on_buyButton_clicked()
{
    CattleBuyScreen* buy = new CattleBuyScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    buy->show();
}

void CattleRegisterScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void CattleRegisterScreen::on_birthButton_clicked()
{
    CattleBirthScreen* birth = new CattleBirthScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    birth->show();
}

Farm* CattleRegisterScreen::getFarm()
{
    return farm_;
}
