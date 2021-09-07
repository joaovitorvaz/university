/*!
 \file cattlebuyscreen.h
 \brief This file contains the screen for the registration of cattle from purchase for the GiroDeGado software.
*/

#ifndef CATTLEBUYSCREEN_H
#define CATTLEBUYSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents the registration of cattle from purchase.
*/
namespace Ui {
class CattleBuyScreen;
}

class CattleBuyScreen : public QDialog
{
    Q_OBJECT
    friend class TestCattleBuyScreenGUI;

public:
    /*!
        This is the default constructor for the Screen CattleBuy.
    */
    explicit CattleBuyScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen CattleBuy.
    */
    ~CattleBuyScreen();

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
        Function that performs the action of registering cattle.
    */
    void on_registerButton_clicked();

private:
    Ui::CattleBuyScreen *ui_; /*!< This attribute contains the ui for the CattleBuy. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // CATTLEBUYSCREEN_H
