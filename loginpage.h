#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "customstring.h"

#include <QDialog>
#include <QEventLoop>

namespace Ui { class LoginPage; }

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    void show();
    int userVerify();

private slots:
    void on_ProceedToDashboard_clicked();

private:
    QEventLoop loop;
    Ui::LoginPage *ui;
    CustomString *accountInString;
    char ***accArray;
    int userCount;

    void closeEvent(QCloseEvent *);
};

#endif // LOGINPAGE_H
