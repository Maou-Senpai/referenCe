//Header Files
#include "pageoperators.h"
#include <QLabel>
#include <QString>

PageOperators::PageOperators()
{
    arithmeticOperators = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/arithmeticOperators.txt", arithmeticOperators);
    equalityOperators = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/equalityOperators.txt", equalityOperators);
    relationalOperators = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/relationalOperators.txt", relationalOperators);
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

void PageOperators::showPage()
{
    addHeader("Basic Operators in C");

    addParagraphTitle("Arithmetic Operators");
    addParagraph("Mathematics in C follows PEMDAS.");
    addItemInfoTable(arithmeticOperators);
    addExampleTitle("Active Sample Code");
    activeSample1();

    addParagraphTitle("Equality Operators");
    addParagraph("Equality Operators");
    addItemInfoTable(equalityOperators);
    addExampleTitle("Active Sample Code");
    activeSample2();

    addParagraphTitle("Relational Operators");
    addParagraph("Relational Operators");
    addItemInfoTable(relationalOperators);
    addExampleTitle("Active Sample Code");
    activeSample3();
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

void PageOperators::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(arithmeticOperators);
    collectiveDict->push_back(equalityOperators);
    collectiveDict->push_back(relationalOperators);
}

// FUNCTION NAME: activeSample1()
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
// Program for numerical operators

void PageOperators::activeSample1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    oneLine1 = new QLineEdit;
    oneLine1->setPlaceholderText("Enter Digit");
    oneLine1->setMaximumWidth(200);
    widgetLayout->addWidget(oneLine1);

    oneComboBox = new QComboBox;
    oneComboBox->addItem("+");
    oneComboBox->addItem("-");
    oneComboBox->addItem("*");
    oneComboBox->addItem("/");
    oneComboBox->addItem("%");
    oneComboBox->setMaximumWidth(100);
    widgetLayout->addWidget(oneComboBox);

    oneLine2 = new QLineEdit;
    oneLine2->setPlaceholderText("Enter Digit");
    oneLine2->setMaximumWidth(200);
    widgetLayout->addWidget(oneLine2);

    pageLayout->addWidget(widget);
    oneLabel = new QLabel;
    declaredParagraph(oneLabel, "Answer Here");

    connect(oneLine1, &QLineEdit::textChanged, this, &PageOperators::changeOneLabel);
    connect(oneLine2, &QLineEdit::textChanged, this, &PageOperators::changeOneLabel);
    connect(oneComboBox, &QComboBox::textActivated, this, &PageOperators::changeOneLabel);
}

// FUNCTION NAME: activeSample2()
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
// Program for equality operators

void PageOperators::activeSample2()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    twoLine1 = new QLineEdit;
    twoLine1->setPlaceholderText("Enter Digit");
    twoLine1->setMaximumWidth(200);
    widgetLayout->addWidget(twoLine1);

    twoComboBox = new QComboBox;
    twoComboBox->addItem("==");
    twoComboBox->addItem("!=");
    twoComboBox->setMaximumWidth(100);
    widgetLayout->addWidget(twoComboBox);

    twoLine2 = new QLineEdit;
    twoLine2->setPlaceholderText("Enter Digit");
    twoLine2->setMaximumWidth(200);
    widgetLayout->addWidget(twoLine2);

    pageLayout->addWidget(widget);
    twoLabel = new QLabel;
    declaredParagraph(twoLabel, "Answer Here");

    connect(twoLine1, &QLineEdit::textChanged, this, &PageOperators::changeTwoLabel);
    connect(twoLine2, &QLineEdit::textChanged, this, &PageOperators::changeTwoLabel);
    connect(twoComboBox, &QComboBox::textActivated, this, &PageOperators::changeTwoLabel);
}

// FUNCTION NAME: activeSample3()
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
// Program for equality operators

void PageOperators::activeSample3()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    threeLine1 = new QLineEdit;
    threeLine1->setPlaceholderText("Enter Digit");
    threeLine1->setMaximumWidth(200);
    widgetLayout->addWidget(threeLine1);

    threeComboBox = new QComboBox;
    threeComboBox->addItem(">");
    threeComboBox->addItem("<");
    threeComboBox->addItem(">=");
    threeComboBox->addItem("<=");
    threeComboBox->setMaximumWidth(100);
    widgetLayout->addWidget(threeComboBox);

    threeLine2 = new QLineEdit;
    threeLine2->setPlaceholderText("Enter Digit");
    threeLine2->setMaximumWidth(200);
    widgetLayout->addWidget(threeLine2);

    pageLayout->addWidget(widget);
    threeLabel = new QLabel;
    declaredParagraph(threeLabel, "Answer Here");

    connect(threeLine1, &QLineEdit::textChanged, this, &PageOperators::changeThreeLabel);
    connect(threeLine2, &QLineEdit::textChanged, this, &PageOperators::changeThreeLabel);
    connect(threeComboBox, &QComboBox::textActivated, this, &PageOperators::changeThreeLabel);
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
// Mechanism of the program for numerical operators

void PageOperators::changeOneLabel()
{
    double ans = 0;
    std::string actualAns;
    std::string value1 = oneLine1->text().toUtf8().data();
    std::string value2 = oneLine2->text().toUtf8().data();
    std::string operation = oneComboBox->currentText().toUtf8().data();

    if (operation.compare("+") == 0) {
        ans = atof(value1.c_str()) + atof(value2.c_str());
    } else if (operation.compare("-") == 0) {
        ans = atof(value1.c_str()) - atof(value2.c_str());
    } else if (operation.compare("*") == 0) {
        ans = atof(value1.c_str()) * atof(value2.c_str());
    } else if (operation.compare("/") == 0) {
        ans = atof(value1.c_str()) / atof(value2.c_str());
    } else if (operation.compare("%") == 0) {
        if (atoi(value2.c_str()) != 0) ans = atoi(value1.c_str()) % atoi(value2.c_str());
        actualAns += "% Only for Integers.\n";
        actualAns += "0 for Second Value is Not Allowed.\n";
        actualAns += "Program Automatically Removes Values After Decimal\n";
    }
    actualAns += std::to_string(ans);

    oneLabel->setText(actualAns.c_str());
}

// FUNCTION NAME: changeTwoLabel()
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
// Mechanism of the program for equality operators

void PageOperators::changeTwoLabel()
{
    std::string actualAns = "Invalid";
    std::string value1 = twoLine1->text().toUtf8().data();
    std::string value2 = twoLine2->text().toUtf8().data();
    std::string operation = twoComboBox->currentText().toUtf8().data();

    if (operation.compare("==") == 0) {
        atof(value1.c_str()) == atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    } else if (operation.compare("!=") == 0) {
        atof(value1.c_str()) != atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    }

    twoLabel->setText(actualAns.c_str());
}

// FUNCTION NAME: changeThreeLabel()
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
// Mechanism of the program for relational operators

void PageOperators::changeThreeLabel()
{
    std::string actualAns = "Invalid";
    std::string value1 = threeLine1->text().toUtf8().data();
    std::string value2 = threeLine2->text().toUtf8().data();
    std::string operation = threeComboBox->currentText().toUtf8().data();

    if (operation.compare(">") == 0) {
        atof(value1.c_str()) > atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    } else if (operation.compare("<") == 0) {
        atof(value1.c_str()) < atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    } else if (operation.compare(">=") == 0) {
        atof(value1.c_str()) >= atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    } else if (operation.compare("<=") == 0) {
        atof(value1.c_str()) <= atof(value2.c_str()) ? actualAns = "True" : actualAns = "False";
    }

    threeLabel->setText(actualAns.c_str());
}
