#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QEventLoop>

#include "referencepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QScrollArea *referenceArea;
    std::vector<std::vector<dictionary *> *> *currentPageDictionaries;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void show();
    ReferencePage *pageFinder(const char *pageName);

private slots:
    void on_sideBar_itemActivated(QListWidgetItem *item);
    void on_actionDashboard_triggered();
    void searchFeature();

private:
    QEventLoop loop;
    Ui::MainWindow *ui;
    ReferencePage *tempPage;

    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
