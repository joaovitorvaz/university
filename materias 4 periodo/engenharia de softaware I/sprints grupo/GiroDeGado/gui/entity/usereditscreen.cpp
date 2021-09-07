#include "usereditscreen.h"
#include "ui_usereditscreen.h"

UserEditScreen::UserEditScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::UserEditScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

UserEditScreen::~UserEditScreen()
{
    delete ui_;
}

void UserEditScreen::on_okButton_clicked()
{
    QString nickname_q = ui_->inputNickname->text();
    std::string nickname = nickname_q.toUtf8().constData();
    Farm* f = getFarm();

    nickname_q = f->getUserNickname(nickname);

    if(nickname_q != ""){
        nickname_q = f->getUserNickname(nickname);
        QString name = f->getUserName(nickname);
        QString password = f->getUserPassword(nickname);
        QString date = f->getUserDate(nickname);
        QString type = f->getUserType(nickname);

        ui_->inputName->setText(name);
        ui_->inputPassword->setText(password);
        ui_->inputNewNickname->setText(nickname_q);

        if(type == "Administrador"){
            ui_->userType->setCurrentIndex(0);
        }
        else{
            ui_->userType->setCurrentIndex(1);
        }

        ui_->dateEdit->setDate(QDate::fromString(date,"dd/MM/yyyy"));

    }
    else{
        ui_->inputNickname->setText("INVALIDO");
        ui_->inputName->setText("INVALIDO");
        ui_->inputPassword->setText("INVALIDO");
        ui_->inputNewNickname->setText("INVALIDO");
    }
}

void UserEditScreen::on_signButton_clicked()
{
    Farm* f = getFarm();

    std::string nickname = ui_->inputNickname->text().toUtf8().constData();
    QString nickname_q = f->getUserNickname(nickname);
    nickname = nickname_q.toUtf8().constData();

    QString name_q = ui_->inputName->text();

    if(nickname != "" && name_q != "INVALIDO" && name_q != ""){
        std::string new_nickname = ui_->inputNewNickname->text().toUtf8().constData();
        std::string name = name_q.toUtf8().constData();
        std::string password = ui_->inputPassword->text().toUtf8().constData();
        std::string birth_date = ui_->dateEdit->text().toUtf8().constData();
        std::string type;

        if(ui_->userType->currentText() == QString::fromStdString("Administrador")){
            type = "Administrador";
        }
        else{
            type = "Funcionario";
        }

        f->setUserNickname(nickname, new_nickname);
        f->setUserName(new_nickname, name);
        f->setUserPassword(new_nickname, password);
        f->setUserDate(new_nickname, birth_date);
        f->setUserType(new_nickname, type);

        current_user_ = new_nickname;
        back_screen_->show();
        this->close();
    }
}

void UserEditScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* UserEditScreen::getFarm()
{
    return farm_;
}
