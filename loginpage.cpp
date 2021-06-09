//Header Files
#include "loginpage.h"
#include "ui_loginpage.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

// PURPOSE:
// This cpp file is for the Login Page which checks for validation
// and redirects the user to the Dashboard page
// It contains two slots:
// on_ProceedToDashboard_clicked() - Proceed to Dashboard Page

//Default Constructors
LoginPage::LoginPage(QWidget *parent):
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    //Set up UI
    ui->setupUi(this);
    ui->lineEdit_username->setFocus();
    connect(ui->lineEdit_password, &QLineEdit::returnPressed, this, &LoginPage::on_ProceedToDashboard_clicked);

    QFile qFile(":/txt/data/accounts.txt");
    if (qFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&qFile);
        accountInString = new CustomString(in.readAll());
        qFile.close();
    }
    accArray = accountInString->get3DArray('$');
    userCount = accountInString->getLineCount();
}

// FUNCTION NAME: ~LoginPage()
//
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

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::show()
{
    this->showNormal();
    loop.exec();
}

int LoginPage::userVerify()
{
    int userNumber = -1;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(accArray[0][i], ui->lineEdit_username->text().toUtf8().data()) == 0) {
            userNumber = i;
            break;
        }
    }

    if (userNumber != -1) {
        if (strcmp(accArray[1][userNumber], ui->lineEdit_password->text().toUtf8().data()) == 0) {
            return 1;
        }
    }

    return 0;
}

// FUNCTION NAME: on_ProceedToDashboard_clicked()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: loginpage.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This slot connects to the form "loginpage.ui"
// and this event is responsible for validations
// and routes to the next page

void LoginPage::on_ProceedToDashboard_clicked()
{
    if (userVerify()) {
        //Show QMessageBox
        QMessageBox::information(this, "Login Successful", "You may now proceed to the referenCe Application");
        this->hide();
        loop.quit();
    } else {
        //Show QMessageBox
        QMessageBox::warning(this, "Error with Logging In", "User Does Not Exist" );
    }
}

void LoginPage::closeEvent(QCloseEvent *)
{
    QCoreApplication::quit();
}
