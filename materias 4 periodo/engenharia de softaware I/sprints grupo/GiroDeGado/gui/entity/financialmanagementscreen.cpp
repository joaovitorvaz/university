#include "financialmanagementscreen.h"
#include "financialrecordscreen.h"
#include "financialconsultscreen.h"
#include "financialremovescreen.h"
#include "reportscreen.h"
#include "ui_financialmanagementscreen.h"

FinancialManagementScreen::FinancialManagementScreen(QWidget *parent, QWidget *backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::FinancialManagementScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

FinancialManagementScreen::~FinancialManagementScreen()
{
    delete ui_;
}

void FinancialManagementScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

void FinancialManagementScreen::on_registerButton_clicked()
{
    FinancialRecordScreen* record = new FinancialRecordScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    record->show();
}

void FinancialManagementScreen::on_queryButton_clicked()
{
    FinancialConsultScreen* consult = new FinancialConsultScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    consult->show();
}

void FinancialManagementScreen::on_removeButton_clicked()
{
    FinancialRemoveScreen* remove = new FinancialRemoveScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    remove->show();
}

void FinancialManagementScreen::on_reportButton_clicked()
{
    ReportScreen* report = new ReportScreen(nullptr, this, login_screen_, getFarm(), current_user_);
    this->hide();
    report->show();
}

Farm* FinancialManagementScreen::getFarm()
{
    return farm_;
}
