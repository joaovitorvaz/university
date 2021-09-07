/*!
 \file signupscreen.h
 \brief This file contains the screen for the registration of a user in the GiroDeGado software.
*/

#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the signup into the program.
*/
namespace Ui {
class SignUpScreen;
}
class SignUpScreen : public QDialog
{
    Q_OBJECT
    friend class TestSignUpScreenGUI;

public:
    /*!
        This is the default constructor for the Screen SignUpScreen.
    */
    explicit SignUpScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen SignScreen.
    */
    ~SignUpScreen();

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
        Function that performs the action of confirming the registration.
    */
    void on_signButton_clicked();

private:
    Ui::SignUpScreen *ui_; /*!< This attribute contains the ui for the SignUpScreen. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_;/*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // SIGNUPSCREEN_H
