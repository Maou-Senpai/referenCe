//Header Files
#include "pageifstatement.h"

PageIfStatement::PageIfStatement()
{
    ifStatement = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/ifStatement.txt", ifStatement);
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

void PageIfStatement::showPage()
{
    addHeader("If Statement");

    addParagraphTitle("if, else if, else");
    addParagraph("The \"if\" is a necessary part of an if statement. Any amount of \"else if\" can be appended. The \"else\" is optional and limited to one only.");
    addItemInfoTable(ifStatement);
    addExampleTitle("Sample Code with Active Program");
    addExampleByFile("Sample Code", ":/cpp/content/ifStatement.cpp");
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

void PageIfStatement::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(ifStatement);
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
// Function to compares the digit input by the user

void PageIfStatement::activeCode1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    oneLabel = new QLabel;
    oneLabel->setText("Enter Age");
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

    connect(oneInput, &QLineEdit::textChanged, this, &PageIfStatement::changeOneLabel);
}

// FUNCTION NAME: changeOneLabel()
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
// Function to change the label

// Generally Copied from ifStatement.cpp
// Just edited some codes to make it work for Qt
// This is just some sort of simulation

void PageIfStatement::changeOneLabel()
{
    int age = atoi(oneInput->text().toUtf8().data());

    if (age >= 18) {
        oneOutput->setText("Person is an Adult");
    } else if (age >= 13) {
        oneOutput->setText("Person is a Teen");
    } else if (age > 0) {
        oneOutput->setText("Person is a Kid");
    } else {
        oneOutput->setText("Invalid Input");
    }
}
