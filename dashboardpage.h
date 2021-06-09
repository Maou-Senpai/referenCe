#ifndef DASHBOARDPAGE_H
#define DASHBOARDPAGE_H

#include <QDialog>
#include <QEventLoop>

namespace Ui { class DashboardPage; }

class DashboardPage : public QDialog
{
    Q_OBJECT

public:
    int choice;

    DashboardPage(QWidget *parent = nullptr);
    ~DashboardPage();
    void show();

private slots:
    void on_proceedToMainWindow_pressed();
    void on_proceedToQuiz_pressed();

private:
    Ui::DashboardPage *ui;
    QEventLoop loop;

    void closeEvent(QCloseEvent *);
};

#endif // DASHBOARDPAGE_H
