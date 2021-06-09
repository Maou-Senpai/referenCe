//Header Files
#include "pageswitchcasestatement.h"

PageSwitchCaseStatement::PageSwitchCaseStatement()
{
    switchCaseStatement = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/switchCaseStatement.txt", switchCaseStatement);
}

// FUNCTION NAME: showPage()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// Creates the elements of the page

void PageSwitchCaseStatement::showPage()
{
    addHeader("Switch/Case Statement");

    addParagraphTitle("switch and case");
    addParagraph("This is similar to an if Statement, but instead of stopping when the condition of a case statement is met, the program will execute the code in the succeeding cases. It is possible to remove this feature by putting a break statement in every case.");
    addItemInfoTable(switchCaseStatement);
    addExampleTitle("Sample Code with Active Program");
    addExampleByFile("Sample Code", ":/cpp/content/switchCaseStatement.cpp");
    activeCode1();
}

// FUNCTION NAME: getDictionaries(std::vector<std::vector<dictionary *> *> *)
//
// PARAMETERS: std::vector<std::vector<dictionary *> *> *
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// To be used for the search function
// This will be called by the mainwindow

void PageSwitchCaseStatement::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(switchCaseStatement);
}

// FUNCTION NAME: activeCode1()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This is a sample simulation of the first sample code
// Mostly copied from the actual cpp file

void PageSwitchCaseStatement::activeCode1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    oneLabel = new QLabel;
    oneLabel->setText("What Day Is It (1-7)");
    oneLabel->setMaximumWidth(200);
    QFont font;
    font.setPointSize(14);
    oneLabel->setFont(font);
    widgetLayout->addWidget(oneLabel);

    oneInput = new QLineEdit;
    oneInput->setPlaceholderText("Enter Digit");
    oneInput->setMaximumWidth(200);
    widgetLayout->addWidget(oneInput);

    pageLayout->addWidget(widget);
    oneOutput = new QLabel;
    declaredParagraph(oneOutput, "Answer Here");

    connect(oneInput, &QLineEdit::textChanged, this, &PageSwitchCaseStatement::changeOneLabel);
}

// Generally Copied from switchCaseStatement.cpp
// Just edited some codes to make it work for Qt
// This is just some sort of emulation
void PageSwitchCaseStatement::changeOneLabel()
{
    int choice = atoi(oneInput->text().toUtf8().data());

    switch (choice) {
        case 1:
            oneOutput->setText("Monday");
            break;
        case 2:
            oneOutput->setText("Tuesday");
            break;
        case 3:
            oneOutput->setText("Wednesday");
            break;
        case 4:
            oneOutput->setText("Thursday");
            break;
        case 5:
            oneOutput->setText("Friday");
            break;
        case 6:
            oneOutput->setText("Saturday");
            break;
        case 7:
            oneOutput->setText("Sunday");
            break;
        default:
            oneOutput->setText("Invalid Input");
    }
}
