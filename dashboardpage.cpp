//Header Files
#include "dashboardpage.h"
#include "ui_dashboardpage.h"
#include "mainwindow.h"

// PURPOSE:
// This cpp file is for the Dashboard Page and implements a simple connection to each page
// It contains three slots:
// on_proceedToMainWindow_pressed() - Proceed to MainWindow Page
// on_proceedToQuiz_pressed() - Proceed to Quiz Page
// on_dashboardQuit_pressed() - Exit the GUI Application


DashboardPage::DashboardPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DashboardPage)
{
    //Setup UI
    ui->setupUi(this);
    this->choice = 0;
}

// FUNCTION NAME: ~DashboardPage()

// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: main()
//
// CALLED FROM: None
//
// METHOD:
//
// This function deletes the UI

DashboardPage::~DashboardPage()
{
    delete ui;
}

// FUNCTION NAME: show()

// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: none
//
// CALLED FROM: main()
//
// METHOD:
//
// This function shows the page, which is used in the main.cpp

void DashboardPage::show()
{
    this->showNormal();
    loop.exec();
}

// FUNCTION NAME: on_proceedToMainWindow_pressed()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: dashboardpage.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This slot connects to the form "dashboardpage.ui"
// and this event is responsible for hiding the dashboard page
// and shows the MainWindow Page

void DashboardPage::on_proceedToMainWindow_pressed()
{
    choice = 1;
    loop.quit();
    this->hide();
}

// FUNCTION NAME: closeEvent(QCloseEvent *)
//
// PARAMETERS: QCloseEvent *
//
// RETURN VALUE: None
//
// CALLS TO: dashboardpage.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function closes the event and quits the looop

void DashboardPage::closeEvent(QCloseEvent *)
{
    choice = 0;
    loop.quit();
}

// FUNCTION NAME: on_proceedToQuiz_pressed()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: dashboardpage.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This slot connects to the form "dashboardpage.ui"
// and this event is responsible for hiding the dashboard page
// and shows the Quiz Page

void DashboardPage::on_proceedToQuiz_pressed()
{
    choice = 2;
    loop.quit();
    this->hide();
}
