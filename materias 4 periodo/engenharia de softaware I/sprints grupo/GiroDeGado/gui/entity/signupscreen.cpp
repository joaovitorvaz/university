#include "signupscreen.h"
#include "ui_signupscreen.h"
#include<iostream>

SignUpScreen::SignUpScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::SignUpScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

SignUpScreen::~SignUpScreen()
{
    delete ui_;
}

void SignUpScreen::on_signButton_clicked()
{
    QString nickname = ui_->inputNickname->text();
    QString password = ui_->inputPassword->text();

    if(nickname != "" && nickname != "INVALIDO" && password != ""){
        Farm* f = getFarm();

        std::string nickname_2 = nickname.toUtf8().constData();
        std::string password_2 = password.toUtf8().constData();
        std::string name = ui_->inputName->text().toUtf8().constData();
        std::string birth_date = ui_->dateEdit->text().toUtf8().constData();
        std::string type;

        if(ui_->userType->currentText() == QString::fromStdString("Administrador")){
            type = "Administrador";
        }
        else{
            type = "Funcionario";
        }

        f->createUser(nickname_2, name, password_2, birth_date, type);
        back_screen_->show();
        this->close();
    }
    else{
        if(nickname != "" && nickname != "INVALIDO"){
            ui_->inputNickname->setText("INVALIDO");
        }
    }
}

void SignUpScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* SignUpScreen::getFarm()
{
    return farm_;
}
