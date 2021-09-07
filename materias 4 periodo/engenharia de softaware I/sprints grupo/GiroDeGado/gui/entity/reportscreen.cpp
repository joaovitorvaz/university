#include "reportscreen.h"
#include "ui_reportscreen.h"

ReportScreen::ReportScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::ReportScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

ReportScreen::~ReportScreen()
{
    delete ui_;
}

void ReportScreen::on_okButton_clicked()
{
    Farm* f = getFarm();

    std::string begin = ui_->dateIntervalB->text().toUtf8().constData();
    std::string end = ui_->dateIntervalE->text().toUtf8().constData();

    QString begin_date = QString::fromStdString(begin);
    QString end_date = QString::fromStdString(end);

    auto table = ui_->reportTable;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Reseting the table of transactions in the given date interval (reportTable)
    table->clear();
    table->setHorizontalHeaderLabels({"Nro do Brinco", "Operação", "Descrição", "Valor"});

    while(table->rowCount() != 0){
        table->removeRow(table->rowCount()-1);
    }

    // Adding the transactions the table (reportTable)
    double totalEarnings = 0.0;
    double totalSpending = 0.0;
    int earningsCount = 0;
    int spendingCount = 0;

    f->queryExec("select * from financial where date>='"+begin_date+"'and date<='"+end_date+"'");
    QString value;
    QString cattle_earring;
    QString descricao;
    QString operacao;
    double value_2;

    while(f->queryNext()){
        value = f->queryValue(3);
        cattle_earring = f->queryValue(4);
        descricao = f->queryValue(5);
        value_2 = value.toDouble();

        if(value_2 <= 0){
            operacao = QString::fromStdString("Despesa");
            totalSpending += value_2;
            spendingCount++;
        }
        else{
            operacao = QString::fromStdString("Ganho");
            totalEarnings += value_2;
            earningsCount++;
        }

        table->insertRow(table->rowCount());
        table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(cattle_earring));
        table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(operacao));
        table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(descricao));
        table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(value));
    }

    // Updating the profit, total and average earnings and spending
    ui_->labelValueTotalEarnings->setText("R$ "+QString::number(totalEarnings));
    ui_->labelValueTotalSpending->setText("R$ "+QString::number(totalSpending));
    ui_->labelValueProfit->setText("R$ "+QString::number(totalEarnings + totalSpending));

    if(earningsCount == 0)
        earningsCount++;
    if(spendingCount == 0)
        spendingCount++;

    ui_->labelValueAverageEarnings->setText("R$ "+QString::number(totalEarnings/earningsCount));
    ui_->labelValueAverageSpending->setText("R$ "+QString::number(totalSpending/spendingCount));

}


void ReportScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* ReportScreen::getFarm()
{
    return farm_;
}

