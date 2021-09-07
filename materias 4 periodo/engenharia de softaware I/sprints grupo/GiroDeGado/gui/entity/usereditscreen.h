/*!
 \file usereditscreen.h
 \brief This file contains the screen for the update of a user in the GiroDeGado software.
*/

#ifndef USEREDITSCREEN_H
#define USEREDITSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the edit of a selected user.
*/
namespace Ui {
class UserEditScreen;
}
class UserEditScreen : public QDialog
{
    Q_OBJECT
    friend class TestUserEditScreenGUI;

public:
    /*!
        This is the default constructor for the Screen UserEditScreen.
    */
    explicit UserEditScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");
    /*!
        This is the default destructor for the Screen UserEditScreen.
    */
    ~UserEditScreen();
    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:

    /*!
        Function that performs the action of confirming the user survey.
    */
    void on_okButton_clicked();

    /*!
        Function that performs the action of updating users.
    */
    void on_signButton_clicked();

    /*!
        Function that performs the action of going back to the previous screen.
    */
    void on_backButton_clicked();

private:
    Ui::UserEditScreen *ui_; /*!< This attribute contains the ui for the UserEditScreen. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_;/*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // USEREDITSCREEN_H
