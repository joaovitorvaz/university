#include "usermanagementscreen.h"
#include "signupscreen.h"
#include "userremovescreen.h"
#include "usereditscreen.h"
#include "userqueryscreen.h"
#include "ui_usermanagementscreen.h"

UserManagementScreen::UserManagementScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::UserManagementScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

UserManagementScreen::~UserManagementScreen()
{
    delete ui_;
}

void UserManagementScreen::on_registerButton_clicked()
{
    SignUpScreen* sign_ = new SignUpScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    sign_->show();
}


void UserManagementScreen::on_queryButton_clicked()
{
    UserQueryScreen* query_ = new UserQueryScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    query_->show();
}


void UserManagementScreen::on_updateButton_clicked()
{
    UserEditScreen* update_ = new UserEditScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    update_->show();
}


void UserManagementScreen::on_removeButton_clicked()
{
    UserRemoveScreen* remove_ = new UserRemoveScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    remove_->show();
}

Farm* UserManagementScreen::getFarm()
{
    return farm_;
}

void UserManagementScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

