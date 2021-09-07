/*!
 \file financialrecordscreen.h
 \brief This file contains the screen for the registration of a transaction for the GiroDeGado software.
*/

#ifndef FINANCIALRECORDSCREEN_H
#define FINANCIALRECORDSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents the registration of a transaction.
*/
namespace Ui {
class FinancialRecordScreen;
}

class FinancialRecordScreen : public QDialog
{
    Q_OBJECT
    friend class TestFinancialRecordScreenGUI;

public:
    /*!
        This is the default constructor for the Screen FinancialRecords.
    */
    explicit FinancialRecordScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen FinancialRecords.
    */
    ~FinancialRecordScreen();

    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:
    /*!
        Function that performs the action of going back to the previous screen.
    */
    void on_backButton_clicked();

    /*!
        Function that performs the action of registering a financial record.
    */
    void on_registerButton_clicked();

private:
    Ui::FinancialRecordScreen *ui_; /*!< This attribute contains the ui for the FinancialRecords. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // FINANCIALRECORDSCREEN_H
