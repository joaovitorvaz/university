/*!
 \file userquerycreen.h
 \brief This file contains the screen for the consultation of a user in the GiroDeGado software.
*/

#ifndef USERQUERYSCREEN_H
#define USERQUERYSCREEN_H

#include <QDialog>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the consultation of a requested user.
*/
namespace Ui {
class UserQueryScreen;
}
class UserQueryScreen : public QDialog
{
    Q_OBJECT
    friend class TestUserConsultScreenGUI;

public:
    /*!
        This is the default constructor for the Screen UserQueryScreen.
    */
    explicit UserQueryScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");
    /*!
        This is the default destructor for the Screen UserQueryScreen.
    */
    ~UserQueryScreen();
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
        Function that performs the action of going back to the previous screen.
    */
    void on_backButton_clicked();

private:
    Ui::UserQueryScreen *ui_; /*!< This attribute contains the ui for the UserQueryScreen. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_;/*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // USERQUERYSCREEN_H
