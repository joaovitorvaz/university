/*!
 \file reportscreen.h
 \brief This file contains the screen for the requisition and visualization of reports in the GiroDeGado software.
*/

#ifndef REPORTSCREEN_H
#define REPORTSCREEN_H

#include <QDialog>
#include <iostream>
#include "../../api/includes/farm.h"

/**
 * \brief
 * This screen represents the request for a report.
*/
namespace Ui {
class ReportScreen;
}
class ReportScreen : public QDialog
{
    Q_OBJECT
    friend class TestReportScreenGUI;

public:
    /*!
        This is the default constructor for the Screen ReportScreen.
    */
    explicit ReportScreen(QWidget *parent = nullptr, QWidget* backScreen = nullptr, QWidget* loginScreen = nullptr, Farm* f = nullptr, std::string current_user = "");

    /*!
        This is the default destructor for the Screen ReportScreen.
    */
    ~ReportScreen();

    /*!
        Returns the Farm.
    */
    Farm* getFarm();

private slots:
    /*!
        Function that redirects to the cattle management screen.
    */
    void on_okButton_clicked();

    /*!
        Function that redirects to the cattle management screen.
    */
    void on_backButton_clicked();

private:
    Ui::ReportScreen *ui_; /*!< This attribute contains the ui for the ReportScreen. */
    QWidget* back_screen_; /*!< This attribute contains the reference of the back screen. */
    QWidget* login_screen_; /*!< This attribute contains the reference of the login screen. */
    Farm* farm_; /*!< This attribute contains the the Farm. */
    std::string current_user_; /*!< The nickname of the current user. */
};

#endif // REPORTSCREEN_H
