#include "userqueryscreen.h"
#include "ui_userqueryscreen.h"

UserQueryScreen::UserQueryScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::UserQueryScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

UserQueryScreen::~UserQueryScreen()
{
    delete ui_;
}

void UserQueryScreen::on_okButton_clicked()
{
    QString nickname_q = ui_->inputNickname->text();
    std::string nickname = nickname_q.toUtf8().constData();
    Farm* f = getFarm();
    auto model = ui_->userQueryTable->model();

    nickname_q = f->getUserNickname(nickname);

    if(nickname_q != ""){
        QString name = f->getUserName(nickname);
        QString date = f->getUserDate(nickname);
        QString type = f->getUserType(nickname);

        model->setData(model->index(0,0),nickname_q);
        model->setData(model->index(0,1),name);
        model->setData(model->index(0,2),date);
        model->setData(model->index(0,3),type);
    }
    else{
        model->setData(model->index(0,0),QString("INVALIDO"));
        model->setData(model->index(0,1),QString("INVALIDO"));
        model->setData(model->index(0,2),QString("INVALIDO"));
        model->setData(model->index(0,3),QString("INVALIDO"));
    }
}


void UserQueryScreen::on_backButton_clicked()
{
    this->close();
    back_screen_->show();
}

Farm* UserQueryScreen::getFarm()
{
    return farm_;
}
