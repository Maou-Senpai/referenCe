//Header Files
#include "pagemodular.h"

// Initializes dictionaries
PageModular::PageModular()
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

void PageModular::showPage()
{
    addHeader("Modular Programming");

    addParagraphTitle("Header File");
    addParagraph("This is used to separate function definitions into a new file.");
    addExampleByFile("Sample Header File (header.h)", ":/cpp/content/header.h");
    addParagraph("To include the header file, use: #include \"headerFileName.h\". The files should be located in the same folder.");
    addExampleByFile("Sample Code Including header.h", ":/cpp/content/header.cpp");
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

void PageModular::getDictionaries(std::vector<std::vector<dictionary *> *> *)
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

void PageModular::sampleSimulation1()
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

int PageModular::add(int x, int y) {
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

int PageModular::subtract(int x, int y) {
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

int PageModular::multiply(int x, int y) {
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

int PageModular::divide(int x, int y) {
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

void PageModular::printMenu(CustomString *collectText) {
    collectText->appendText("Pick An Operation:\n");
    collectText->appendText("1: Addition\n");
    collectText->appendText("2: Subtraction\n");
    collectText->appendText("3: Multiplication\n");
    collectText->appendText("4: Division\n\n");
}
