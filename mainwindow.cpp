//Header Files
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagehome.h"
#include "pagedatatypes.h"
#include "pageoperators.h"
#include "pagemissing.h"
#include "pageinputoutput.h"
#include "pageifstatement.h"
#include "pageswitchcasestatement.h"
#include "pagefunctions.h"
#include "pagemodular.h"
#include "pagepointers.h"
#include "pagestrings.h"
#include "pagetextfilehandling.h"
#include "pagedynamicmemory.h"
#include "pagelooping.h"
#include "pagearrays.h"
#include "pagestructures.h"
#include "pageclass.h"
#include "pageinheritance.h"
#include "pagetry.h"

#include "pagelibstdio.h"
#include "pagelibstdlib.h"
#include "pagelibstring.h"
#include "pagelibtime.h"
#include "pagelibmath.h"
#include "customstring.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>
#include <algorithm>
#include <QMessageBox>

// FUNCTION NAME: void addContents(const char *contentsTxt, QListWidget *widget)
//
// PARAMETERS: const char *contentsTxt, QListWidget *widget
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function is responsible for adding contents to the page
//

void addContents(const char *contentsTxt, QListWidget *widget) {
    QFile contentFile(contentsTxt);
    if (contentFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&contentFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QListWidgetItem *item = new QListWidgetItem(widget);
            item->setText(line.toUtf8().data());

            QFont font;
            font.setPointSize(14);
            item->setFont(font);
        }
        contentFile.close();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // DO NOT TOUCH! This makes the general layout of the program.
    // The general layout should be made up of two objects.
    // 1. An object of QListWidget class on the left side.
    // 2. An object of QScrollArea class on the right side.
    ui->setupUi(this);
    ui->mainLayout->setSpacing(20);

    // This places the contents of sideBar object, a QWidgetClass.
    addContents(":/txt/data/contents.txt", ui->sideBar);

    // DO NOT TOUCH! This adds an object of ScollArea onto the mainLayout.
    // This is where the ReferencePages are shown.
    referenceArea = new QScrollArea(ui->centralwidget);
    referenceArea->setWidgetResizable(true);
    ui->mainLayout->addWidget(referenceArea);
    tempPage = new PageHome;
    tempPage->showPage();
    referenceArea->setWidget(tempPage);

    // Connect the search widget to getcurrentPageDictionaries function
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::searchFeature);
    connect(ui->searchBar, &QLineEdit::returnPressed, this, &MainWindow::searchFeature);
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

MainWindow::~MainWindow()
{
    delete ui;
}

// FUNCTION NAME: show()
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
// Sets the window to a full-screen view
// Executes the page

void MainWindow::show()
{
    this->showMaximized();
    loop.exec();
}

// FUNCTION NAME: pageFinder(const char *pageName)
//
// PARAMETERS: const char *pageName
//
// RETURN VALUE: PageMissing (Depending on which item the user selects)
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: None
//
// METHOD:
//
// Sets the window to a full-screen view
// Executes the page

ReferencePage *MainWindow::pageFinder(const char *pageName)
{
    if (!stricmp(pageName, "Home")) return new PageHome;
    else if (!stricmp(pageName, "Data Types")) return new PageDataTypes;
    else if (!stricmp(pageName, "Basic Operators in C")) return new PageOperators;
    else if (!stricmp(pageName, "Input and Output")) return new PageInputOutput;
    else if (!stricmp(pageName, "If Statement")) return new PageIfStatement;
    else if (!stricmp(pageName, "Switch/Case Statement")) return new PageSwitchCaseStatement;
    else if (!stricmp(pageName, "Looping")) return new PageLooping;
    else if (!stricmp(pageName, "Arrays")) return new PageArrays;
    else if (!stricmp(pageName, "Functions")) return new PageFunctions;
    else if (!stricmp(pageName, "Modular Programming")) return new PageModular;
    else if (!stricmp(pageName, "Pointers")) return new PagePointers;
    else if (!stricmp(pageName, "Strings")) return new PageStrings;
    else if (!stricmp(pageName, "Text File Handling")) return new PageTextFileHandling;
    else if (!stricmp(pageName, "Dynamic Memory Allocation")) return new PageDynamicMemory;
    else if (!stricmp(pageName, "Structures")) return new PageStructures;
    else if (!stricmp(pageName, "Object-Oriented Programming")) return new PageClass;
    else if (!stricmp(pageName, "Inheritance")) return new PageInheritance;
    else if (!stricmp(pageName, "Try-Catch")) return new PageTry;
    else if (!stricmp(pageName, "Library - stdio.h")) return new PageLibStdio;
    else if (!stricmp(pageName, "Library - stdlib.h")) return new PageLibStdlib;
    else if (!stricmp(pageName, "Library - string.h")) return new PageLibString;
    else if (!stricmp(pageName, "Library - time.h")) return new PageLibTime;
    else if (!stricmp(pageName, "Library - math.h")) return new PageLibMath;
    else return new PageMissing;
}

// FUNCTION NAME: searchFeature()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: MainWindow.ui
//
// CALLED FROM: None
//
// METHOD:
//
// Responsible for going through the user's input and finding an occurence
// based on the currentPageDictionaries

void MainWindow::searchFeature()
{
    // Initialization for searching
    int currentRow = ui->sideBar->currentRow();
    int rowCounter = 0;
    CustomString *searchText = new CustomString(ui->searchBar->text());
    searchText->trimEnd();
    std::string toSearch = searchText->getCustomString();
    std::string msgText = "Found an Occurence in ";
    QMessageBox msg;

    if (currentRow == -1) ui->sideBar->setCurrentRow(0);
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    // End Init

    QFile contentFile(":/txt/data/contents.txt");
    if (contentFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&contentFile);
        while (!in.atEnd())
        {
            // Fills up currentPageDictionaries with dictionaries of a page
            currentPageDictionaries = new std::vector<std::vector<dictionary *> *>;
            ReferencePage *tempPage = pageFinder(in.readLine().toUtf8().data());
            tempPage->getDictionaries(currentPageDictionaries);

            // Actual part of the search engine
            std::string currentStr = ui->sideBar->item(rowCounter)->text().toUtf8().data();
            std::transform(currentStr.begin(), currentStr.end(), currentStr.begin(), ::tolower);
            if (currentStr.find(toSearch) != std::string::npos && rowCounter > currentRow) {
                ui->sideBar->setCurrentRow(rowCounter);
                on_sideBar_itemActivated(ui->sideBar->item(rowCounter));
                msgText += ui->sideBar->item(rowCounter)->text().toUtf8().data();
                msg.setText(msgText.c_str());
                msg.exec();
                return;
            }

            for (size_t i = 0; i < currentPageDictionaries->size(); i++) {
                for (size_t j = 0; j < currentPageDictionaries->at(i)->size(); j++) {
                    currentStr = currentPageDictionaries->at(i)->at(j)->item.toUtf8().data();
                    std::transform(currentStr.begin(), currentStr.end(), currentStr.begin(), ::tolower);
                    if (currentStr.find(toSearch) != std::string::npos && rowCounter > currentRow) {
                        ui->sideBar->setCurrentRow(rowCounter);
                        on_sideBar_itemActivated(ui->sideBar->item(rowCounter));
                        msgText += ui->sideBar->item(rowCounter)->text().toUtf8().data();
                        msg.setText(msgText.c_str());
                        msg.exec();
                        return;
                    }
                    currentStr = currentPageDictionaries->at(i)->at(j)->info.toUtf8().data();
                    std::transform(currentStr.begin(), currentStr.end(), currentStr.begin(), ::tolower);
                    // Include this if you want to also search description
                    if (currentStr.find(toSearch) != std::string::npos && rowCounter > currentRow) {
                        ui->sideBar->setCurrentRow(rowCounter);
                        on_sideBar_itemActivated(ui->sideBar->item(rowCounter));
                        msgText += ui->sideBar->item(rowCounter)->text().toUtf8().data();
                        msg.setText(msgText.c_str());
                        msg.exec();
                        return;
                    }
                }
            }
            rowCounter++;
        }
        msg.setText("Search is Empty. Possible Reasons: \n1. Try highlighting the highest item in the Side Bar. The search works from top to bottom.\n2. The function you tried to search just doesn't exist.");
        msg.exec();
        contentFile.close();
    }
}

// FUNCTION NAME: on_sideBar_itemActivated(QListWidgetItem *item)
//
// PARAMETERS: QListWidgetItem *item
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: None
//
// METHOD:
//
// This slot goes through the pageFinder function and shows the page to the
// referenceArea

void MainWindow::on_sideBar_itemActivated(QListWidgetItem *item)
{
    delete tempPage;
    tempPage = this->pageFinder(item->text().toUtf8().data());
    tempPage->showPage();
    referenceArea->setWidget(tempPage);
}

// FUNCTION NAME: on_sideBar_itemActivated(QListWidgetItem *item)
//
// PARAMETERS: QListWidgetItem *item
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: None
//
// METHOD:
//
// This slot is responsible for closing/hiding the main window page

void MainWindow::on_actionDashboard_triggered()
{
    loop.quit();
    this->hide();
}

// FUNCTION NAME: :closeEvent(QCloseEvent *)
//
// PARAMETERS: QCloseEvent *
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: None
//
// METHOD:
//
// This slot is responsible exiting the GUI application

void MainWindow::closeEvent(QCloseEvent *) {
    loop.quit();
}
