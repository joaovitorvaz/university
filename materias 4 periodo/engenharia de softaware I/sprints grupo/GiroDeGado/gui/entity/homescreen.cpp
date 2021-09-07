#include "homescreen.h"
#include "cattlemanagementscreen.h"
#include "financialmanagementscreen.h"
#include "usermanagementscreen.h"
#include "ui_homescreen.h"

HomeScreen::HomeScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user)
    : QDialog(parent)
    , ui_(new Ui::HomeScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

HomeScreen::~HomeScreen()
{
    delete ui_;
}

void HomeScreen::on_cattleButton_clicked()
{
    CattleManagementScreen* cattleManagement = new CattleManagementScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    cattleManagement->exec();
}

void HomeScreen::on_financialButton_clicked()
{
    FinancialManagementScreen* financialManagement = new FinancialManagementScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    financialManagement->exec();
}

void HomeScreen::on_logoutButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* HomeScreen::getFarm()
{
    return farm_;
}

void HomeScreen::on_userButton_clicked()
{
    Farm* f = getFarm();
    QString type = f->getUserType(current_user_);

    //std::cout << "botao usuarios - current_user_: " << current_user_ << std::endl;
    //std::cout << "botao usuarios - type: " << type.toUtf8().constData() << std::endl;

    if(type == QString::fromStdString("Administrador")){
        UserManagementScreen* userManagement = new UserManagementScreen(nullptr, this, login_screen_, getFarm(), current_user_);
        this->hide();
        userManagement->show();
    }
    else{
        QMessageBox msg = QMessageBox(msg.Warning, "Aviso: Usuario nao e um Administrador",
        QString("Este usuario nao e um administrador do sistema, e portanto, nao pode gerir Usuarios."));
        msg.setStandardButtons(msg.Ok);
        msg.exec();
    }

}

