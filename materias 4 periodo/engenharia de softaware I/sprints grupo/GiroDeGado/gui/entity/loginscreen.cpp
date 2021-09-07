#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "homescreen.h"

LoginScreen::LoginScreen(QWidget *parent, Farm* f) :
    QMainWindow(parent),
    ui_(new Ui::LoginScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    ui_->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui_;
}

void LoginScreen::on_loginButton_clicked()
{
    Farm* f = getFarm();
    std::string login = ui_->inputUser->text().toUtf8().constData();
    std::string password = ui_->inputPassword->text().toUtf8().constData();

    QString login_q = f->getUserNickname(login);
    QString password_q = f->getUserPassword(login);

    if(login_q == QString::fromStdString(login) && login_q != "" &&
        password_q == QString::fromStdString(password) && password_q != ""){
        HomeScreen* home = new HomeScreen(nullptr, this, this, getFarm(), login);
        this->hide();
        home->exec();
    }
    else{
        QMessageBox msg(msg.Warning, "Aviso: Usuario nao cadastrado",
        QString("Este usuario nao foi cadastrado no sistema ou suas credenciais nao foram digitadas corretamente."));
        msg.setStandardButtons(msg.Ok);
        msg.exec();
    }

}

void LoginScreen::on_exitButton_clicked()
{
    this->close();
}

Farm* LoginScreen::getFarm()
{
    return farm_;
}
