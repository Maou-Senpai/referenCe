//Header Files
#include "pagefunctions.h"
#include <QLabel>
#include <QString>
// Initializes dictionaries
PageFunctions::PageFunctions()
{

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

void PageFunctions::showPage()
{
    addHeader("Functions");

    addParagraphTitle("Functions as Subprograms");
    addExample("Syntax", "Datatype function_name (parameter variables)\n{\n   Variable declarations;\n   Statements;\n   Return\n}");
    addExampleByFile("Sample Code", ":/cpp/content/functions.cpp");
    sampleSimulation1();
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

void PageFunctions::getDictionaries(std::vector<std::vector<dictionary *> *> *)
{
    // No Dictionaries Here
}

// FUNCTION NAME: sample1Simulation()
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
// Modified to make it work in Qt

void PageFunctions::sampleSimulation1()
{
    CustomString collectText;
    int choice, num1, num2, ans = 0;

    printMenu(&collectText);
    collectText.appendText("Input Choice: 2\n");
    choice = 2;
    collectText.appendText("Input First Number: 5\n");
    num1 = 5;
    collectText.appendText("Input Second Number: 3\n");
    num2 = 3;

    if (choice == 1) ans = add(num1, num2);
    else if (choice == 2) ans = subtract(num1, num2);
    else if (choice == 3) ans = multiply(num1, num2);
    else if (choice == 4) ans = divide(num1, num2);

    collectText.appendText("\nAnswer: ");
    collectText.appendText(ans);
    addExample("Sample Simulation", collectText.getCustomString());


    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    twoLabel = new QLabel;
    declaredParagraph(twoLabel, "Pick an Operation");

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

    connect(oneLine1, &QLineEdit::textChanged, this, &PageFunctions::changeOneLabel);
    connect(oneLine2, &QLineEdit::textChanged, this, &PageFunctions::changeOneLabel);
    connect(oneComboBox, &QComboBox::textActivated, this, &PageFunctions::changeOneLabel);
}

// FUNCTION NAME: add(int x, int y)
//
// PARAMETERS: int x - operand 1
//             int y - operand 2
//
// RETURN VALUE: sum of x and y
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function adds the user input.

int PageFunctions::add(int x, int y) {
    int tempAns = x + y;
    return tempAns;
}

// FUNCTION NAME: subtract(int x, int y)
//
// PARAMETERS: int x - operand 1
//             int y - operand 2
//
// RETURN VALUE: difference of x and y
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function computes the difference of the user input.

int PageFunctions::subtract(int x, int y) {
    int tempAns = x - y;
    return tempAns;
}

// FUNCTION NAME: multiply(int x, int y)
//
// PARAMETERS: int x - operand 1
//             int y - operand 2
//
// RETURN VALUE: multiplication of x and y
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function computes the multiplication of the user input.

int PageFunctions::multiply(int x, int y) {
    int tempAns = x * y;
    return tempAns;
}

// FUNCTION NAME: divide(int x, int y)
//
// PARAMETERS: int x - operand 1
//             int y - operand 2
//
// RETURN VALUE: division of x and y
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function computes the division of the user input.

int PageFunctions::divide(int x, int y) {
    int tempAns = x / y;
    return tempAns;
}

// FUNCTION NAME: printMenu(CustomString *collectText)
//
// PARAMETERS: CustomString *collectText
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This function shows a menu for the user to pick an operation


void PageFunctions::printMenu(CustomString *collectText) {
    collectText->appendText("Pick An Operation:\n");
    collectText->appendText("1: Addition\n");
    collectText->appendText("2: Subtraction\n");
    collectText->appendText("3: Multiplication\n");
    collectText->appendText("4: Division\n\n");
}

void PageFunctions::changeOneLabel()
{
    double ans = 0;
    CustomString actualAns;
    CustomString *value1 = new CustomString(oneLine1->text());
    CustomString *value2 = new CustomString(oneLine2->text());
    CustomString *operation = new CustomString(oneComboBox->currentText());

    if (operation->compare("+") == 0) {
        ans = atof(value1->getCustomString()) + atof(value2->getCustomString());
    } else if (operation->compare("-") == 0) {
        ans = atof(value1->getCustomString()) - atof(value2->getCustomString());
    } else if (operation->compare("*") == 0) {
        ans = atof(value1->getCustomString()) * atof(value2->getCustomString());
    } else if (operation->compare("/") == 0) {
        ans = atof(value1->getCustomString()) / atof(value2->getCustomString());
    } else if (operation->compare("%") == 0) {
        if (atoi(value2->getCustomString()) != 0) ans = atoi(value1->getCustomString()) % atoi(value2->getCustomString());
        actualAns.appendText("% Only for Integers.\n");
        actualAns.appendText("0 for Second Value is Not Allowed.\n");
        actualAns.appendText("Program Automatically Removes Values After Decimal\n");
    }
    actualAns.appendText(ans);

    oneLabel->setText(actualAns.getCustomString());
}
