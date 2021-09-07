/*!
 \file financialmanagementscreen.h
 \brief This file contains the screen for the management of all features related to the transactions for
 the GiroDeGado software.
*/

#ifndef FINANCIALMANAGEMENTSCREEN_H
#define FINANCIALMANAGEMENTSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents the management of all features related to the transactions.
*/
namespace Ui {
class FinancialManagementScreen;
}

class FinancialManagementScreen : public QDialog
{
    Q_OBJECT
    friend class TestFinancialManagementScreenGUI;

public:
    /*!
        This is the default constructor for the FinancialManagement.
    */
    explicit FinancialManagementScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the FinancialManagement.
    */
    ~FinancialManagementScreen();

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
        Function that redirects to the financial registration screen.
    */
    void on_registerButton_clicked();

    /*!
        Function that redirects to the financial query screen.
    */
    void on_queryButton_clicked();

    /*!
        Function that redirects to the financial remove screen.
    */
    void on_removeButton_clicked();

    /*!
        Function that redirects to the financial reports screen.
    */
    void on_reportButton_clicked();

private:
    Ui::FinancialManagementScreen *ui_; /*!< This attribute contains the ui for the FinancialManagement. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // FINANCIALMANAGEMENTSCREEN_H
