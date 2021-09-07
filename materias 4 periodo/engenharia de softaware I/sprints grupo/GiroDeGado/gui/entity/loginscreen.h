/*!
 \file loginscreen.h
 \brief This file contains the screen for the login in the GiroDeGado software.
*/

#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include <QMessageBox>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the login into the program.
*/
QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE
class LoginScreen : public QMainWindow
{
    Q_OBJECT
    friend class TestLoginScreenGUI;

public:
    /*!
        This is the default constructor for the Screen Login.
    */
    explicit LoginScreen(QWidget *parent = nullptr, Farm* f = nullptr);

    /*!
        This is the default destructor for the Screen Login.
    */
    ~LoginScreen();

    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:
    /*!
        Function that redirects to the HomeScreen.
    */
    void on_loginButton_clicked();

    /*!
        Function that closes the program.
    */
    void on_exitButton_clicked();

private:
    Ui::LoginScreen *ui_; /*!< This attribute contains the ui for the LoginScreen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
};

#endif // LOGINSCREEN_H
