#include "userremovescreen.h"
#include "ui_userremovescreen.h"

UserRemoveScreen::UserRemoveScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::UserRemoveScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

UserRemoveScreen::~UserRemoveScreen()
{
    delete ui_;
}

void UserRemoveScreen::on_okButton_clicked()
{
    QString nickname_q = ui_->inputNickname->text();
    std::string nickname = nickname_q.toUtf8().constData();
    Farm* f = getFarm();
    auto model = ui_->userRemoveTable->model();

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

void UserRemoveScreen::on_removeButton_clicked()
{
    Farm* f = getFarm();

    std::string nickname = ui_->inputNickname->text().toUtf8().constData();
    QString nickname_q = f->getUserNickname(nickname);
    nickname = nickname_q.toUtf8().constData();

    QString type = ui_->userRemoveTable->item(0,3)->text();

    if(nickname != "" && type != "INVALIDO" && type != ""){

        // Last admin can't be deleted
        f->queryExec("select * from users where type='Administrador'");
        int count = 0;
        if(f->queryFirst()){
            count++;
            while(f->queryNext()){
                count++;
            }
        }

        if(count == 1 && type == QString::fromStdString("Administrador")){
            QMessageBox msg = QMessageBox(msg.Warning, "Aviso: Ultimo Administrador restante",
            QString("O usuario a ser excluido e o ultimo administrador do sistema, e portanto, nao pode ser excluido."));
            msg.setStandardButtons(msg.Ok);
            msg.exec();
        }
        else{
            f->deleteUser(nickname);

            // Admin is deleting itself
            if(nickname == current_user_){
                login_screen_->show();
                this->close();
            }
            // Admin is deleting another user
            else{
                back_screen_->show();
                this->close();
            }
        }

    }

}

void UserRemoveScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* UserRemoveScreen::getFarm()
{
    return farm_;
}
