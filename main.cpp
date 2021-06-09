#include "mainwindow.h"
#include "loginpage.h"
#include "dashboardpage.h"
#include "quizpage.h"

#include <QApplication>


// FUNCTION NAME: main
// CONSTRUCTORS:
//    argc - int
//    *argv[] - char pointer
//
// METHOD:
//
// This function executes the landing page (Login page)
// Also contains logic for routing through the Dashboard Page

int main(int argc, char *argv[])
{
    //Object a as a QApplication with default constructors
    QApplication a(argc, argv);

    //Set logo to the window icon
    a.setWindowIcon(QIcon(":/img/data/profile.png"));

    //Create LoginPage object "login"
    LoginPage *login = new LoginPage;

    //Set WindowTitle to "referenCe"
    login->setWindowTitle("referenCe");

    //Execute the login object
//    login->show();

    //For Dashboard
    //Instantiate a pointer to the DashboardPage object
    DashboardPage *dashboard = new DashboardPage;
    //Set WindowTitle to "referenCe"
    dashboard->setWindowTitle("referenCe");

    //For Study
    //Instantiate a pointer to the MainWindow object
    MainWindow *mainWindow = new MainWindow;
    //Set WindowTitle to "referenCe"
    mainWindow->setWindowTitle("referenCe");

    //For Quiz
    //Instantiate a pointer to the QuizPage object
    QuizPage *quizPage = new QuizPage;
    //Set WindowTitle to "referenCe"
    quizPage->setWindowTitle("referenCe");

    //Logic for connecting each page
    do {
        //Show dashboard page
        dashboard->show();

        if (dashboard->choice == 1) {
            //Show mainWindow (Study) page
            mainWindow->show();

        } else if (dashboard->choice == 2) {
            //Show Quiz page
            quizPage->show();
        }
    } while (dashboard->choice != 0);

   return 0;
}
