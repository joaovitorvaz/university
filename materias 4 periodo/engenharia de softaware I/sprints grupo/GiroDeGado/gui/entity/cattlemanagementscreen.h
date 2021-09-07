/*!
 \file cattlemanagementscreen.h
 \brief This file contains the screen for management of all features related to the cattle for the
 GiroDeGado software.
*/

#ifndef CATTLEMANAGEMENTSCREEN_H
#define CATTLEMANAGEMENTSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents the management of all features related to the cattle.
*/
namespace Ui {
class CattleManagementScreen;
}

class CattleManagementScreen : public QDialog
{
    Q_OBJECT
    friend class TestCattleManagementScreenGUI;

public:
    /*!
        This is the default constructor for the Screen CattleManagement.
    */
    explicit CattleManagementScreen(QWidget* parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen CattleManagement.
    */
    ~CattleManagementScreen();

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
        Function that redirects to the cattle registration screen.
    */
    void on_registerButton_clicked();

    /*!
        Function that redirects to the cattle query screen.
    */
    void on_queryButton_clicked();

    /*!
        Function that redirects to cattle update screen.
    */
    void on_updateButton_clicked();

    /*!
        Function that redirects to the cattle removal screen.
    */
    void on_removeButton_clicked();

private:
    Ui::CattleManagementScreen* ui_; /*!< This attribute contains the ui for the CattleManagement. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // CATTLEMANAGEMENTSCREEN_H
