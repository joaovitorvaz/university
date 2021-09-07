/*!
 \file cattleremovescreen.h
 \brief This file contains the screen for the removal of a registered cattle for the GiroDeGado software.
*/

#ifndef CATTLEREMOVESCREEN_H
#define CATTLEREMOVESCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/** 
 * \brief
 * This screen represents cattle removals.
*/
namespace Ui {
class CattleRemoveScreen;
}

class CattleRemoveScreen : public QDialog
{
    Q_OBJECT
    friend class TestCattleRemoveScreenGUI;

public:
    /*!
        This is the default constructor for the Screen CattleRemove.
    */
    explicit CattleRemoveScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen CattleRemove.
    */
    ~CattleRemoveScreen();

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
        Function that performs the action of removing a cattle.
    */
    void on_removeButton_clicked();

    /*!
        Function that performs the selection action of the reason for the removal of cattle by death.
    */
    void on_radioButtonDeath_clicked();

    /*!
        Function that performs the action of confirming the cattle survey.
    */
    void on_okButton_clicked();

    /*!
        Function that performs the selection action of the reason for removing the cattle by sale.
    */
    void on_radioButtonSell_clicked();

private:
    Ui::CattleRemoveScreen *ui_; /*!< This attribute contains the ui for the CattleRemove. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // CATTLEREMOVESCREEN_H
