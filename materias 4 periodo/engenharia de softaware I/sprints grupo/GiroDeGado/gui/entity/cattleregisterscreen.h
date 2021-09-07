/*!
 \file cattleregisterscreen.h
 \brief This file contains the screen for the cattle registration options for the GiroDeGado software.
*/

#ifndef CATTLEREGISTERSCREEN_H
#define CATTLEREGISTERSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents the management of cattle registration options.
*/
namespace Ui {
class CattleRegisterScreen;
}

class CattleRegisterScreen : public QDialog
{
    Q_OBJECT
    friend class TestCattleRegisterScreenGUI;

public:
    /*!
        This is the default constructor for the Screen CattleRegister.
    */
    explicit CattleRegisterScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen CattleRegister.
    */
    ~CattleRegisterScreen();

    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:
    /*!
        Function that redirects to the registration screen of cattle from purchase.
    */
    void on_buyButton_clicked();

    /*!
        Function that performs the action of going back to the previous screen.
    */
    void on_backButton_clicked();

    /*!
        Function that redirects to the registration screen of cattle from birth.
    */
    void on_birthButton_clicked();

private:
    Ui::CattleRegisterScreen *ui_; /*!< This attribute contains the ui for the CattleRegister. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // CATTLEREGISTERSCREEN_H
