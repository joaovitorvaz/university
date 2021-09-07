#include "cattleconsultscreen.h"
#include "ui_cattleconsultscreen.h"

CattleConsultScreen::CattleConsultScreen(QWidget *parent, QWidget* backScreen, QWidget* loginScreen, Farm* f, std::string current_user) :
    QDialog(parent),
    ui_(new Ui::CattleConsultScreen)
{
    setFixedSize(900, 600);
    farm_ = f;
    back_screen_ = backScreen;
    login_screen_ = loginScreen;
    current_user_ = current_user;
    ui_->setupUi(this);
}

CattleConsultScreen::~CattleConsultScreen()
{
    delete ui_;
}

void CattleConsultScreen::on_okButton_clicked()
{
    Farm* f = getFarm();

    int cattle_earring = ui_->inputCattleEarring->text().toInt();
    QString earring = f->getCattleEarring(cattle_earring);

    auto model = ui_->cattleConsultTable->model();
    auto table = ui_->cattleTransactionTable;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Reseting the table of transactions related to a cattle (cattleTransactionTable)
    table->clear();
    table->setHorizontalHeaderLabels({"Operação","Valor"});

    while(table->rowCount() != 0){
        table->removeRow(table->rowCount()-1);
    }

    // Setting the information of a cattle (cattleConsultTable)
    if(earring != ""){
        QString breed = f->getCattleBreed(cattle_earring);
        QString acquisition_date = f->getCattleAcquisitionDate(cattle_earring);
        QString birth_date = f->getCattleBirthDate(cattle_earring);
        QString father = f->getCattleFather(cattle_earring);
        QString mother = f->getCattleMother(cattle_earring);
        QString weight = f->getCattleWeight(cattle_earring);
        QString value = f->getCattleValue(cattle_earring);

        model->setData(model->index(0,0),earring);
        model->setData(model->index(0,1),breed);
        model->setData(model->index(0,2),acquisition_date);
        model->setData(model->index(0,3),birth_date);
        model->setData(model->index(0,4),father);
        model->setData(model->index(0,5),mother);
        model->setData(model->index(0,6),weight);
        model->setData(model->index(0,7),value);
    }
    else{
        model->setData(model->index(0,0),QString("INVALIDO"));
        model->setData(model->index(0,1),QString("INVALIDO"));
        model->setData(model->index(0,2),QString("INVALIDO"));
        model->setData(model->index(0,3),QString("INVALIDO"));
        model->setData(model->index(0,4),QString("INVALIDO"));
        model->setData(model->index(0,5),QString("INVALIDO"));
        model->setData(model->index(0,6),QString("INVALIDO"));
        model->setData(model->index(0,7),QString("INVALIDO"));
    }

    // Adding the transactions related to that cattle (cattleTransactionTable)
    auto earring_2 = ui_->cattleConsultTable->item(0,0)->text();

    double totalEarnings = 0.0;
    double totalSpending = 0.0;
    int earningsCount = 0;
    int spendingCount = 0;

    if(earring_2 != "INVALIDO"){
        f->queryExec("select * from financial where cattle_earring="+earring_2);
        QString value;
        QString operacao;
        double value_2;

        while(f->queryNext()){
            value = f->queryValue(3);
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
            table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(operacao));
            table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(value));
        }
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


void CattleConsultScreen::on_backButton_clicked()
{
    back_screen_->show();
    this->close();
}

Farm* CattleConsultScreen::getFarm()
{
    return farm_;
}

