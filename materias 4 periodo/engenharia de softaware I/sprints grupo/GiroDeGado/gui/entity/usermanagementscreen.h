/*!
 \file usermanagementscreen.h
 \brief This file contains the screen for management of all features related to the users for the
 GiroDeGado software.
*/

#ifndef USERMANAGEMENTSCREEN_H
#define USERMANAGEMENTSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the management of all features related to the user.
*/
namespace Ui {
class UserManagementScreen;
}
class UserManagementScreen : public QDialog
{
    Q_OBJECT
    friend class TestUserManagementScreenGUI;

public:
    /*!
        This is the default constructor for the Screen UserManagementScreen.
    */
    explicit UserManagementScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");
    /*!
        This is the default destructor for the Screen UserManagementScreen.
    */
    ~UserManagementScreen();
    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:
    /*!
        Function that redirects to the user registration screen.
    */
    void on_registerButton_clicked();

    /*!
        Function that redirects to the user consult screen.
    */
    void on_queryButton_clicked();

    /*!
        Function that redirects to the user edit screen.
    */
    void on_updateButton_clicked();

    /*!
        Function that redirects to the user removal screen.
    */
    void on_removeButton_clicked();

    /*!
        Function that performs the action of going back to the previous screen.
    */
    void on_backButton_clicked();

private:
    Ui::UserManagementScreen *ui_; /*!< This attribute contains the ui for the UserManagementScreen. */
    QWidget* back_screen_;/*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_;/*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // USERMANAGEMENTSCREEN_H
