//Header Files
#include "pageinputoutput.h"

// Initializes dictionaries
PageInputOutput::PageInputOutput()
{
    printfSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/printfSyntax.txt", printfSyntax);
    scanfSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/scanfSyntax.txt", scanfSyntax);
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

void PageInputOutput::showPage()
{
    addHeader("Input and Output");
    addParagraph("There are many ways to do input and output."
                 "\nThis page only focuses on the basic printf() and scanf() of the <stdio.h> library.");
    executeSample1();

    addParagraphTitle("printf() Syntax");
    addParagraph("\\n breaks the line");
    addItemInfoTable(printfSyntax);
    addExampleByFile("Sample Code", ":/cpp/content/printfSyntax.cpp");

    addParagraphTitle("scanf() Syntax");
    addParagraph("Do not forget the ampersand. It's easily forgotten.");
    addItemInfoTable(scanfSyntax);
    addExampleByFile("Sample Code", ":/cpp/content/scanfSyntax.cpp");
    executeSample2();
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

void PageInputOutput::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(printfSyntax);
    collectiveDict->push_back(scanfSyntax);
}

// FUNCTION NAME: executeSample1()
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

// Generally Copied from printfSyntax.cpp
// Just edited the printf()s to something more appropriate
void PageInputOutput::executeSample1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    oneLabel = new QLabel;
    oneLabel->setText("Enter Word (Max. 20)");
    oneLabel->setMaximumWidth(200);
    QFont font;
    font.setPointSize(14);
    oneLabel->setFont(font);
    widgetLayout->addWidget(oneLabel);

    oneInput = new QLineEdit;
    oneInput->setPlaceholderText("Enter Word");
    oneInput->setMaximumWidth(200);
    oneInput->setMaxLength(20);
    widgetLayout->addWidget(oneInput);

    pageLayout->addWidget(widget);
    oneOutput = new QLabel;
    oneOutput->setAlignment(Qt::AlignJustify);
    declaredParagraph(oneOutput, "Input word");

    connect(oneInput, &QLineEdit::textChanged, this, &PageInputOutput::changeOneOutput);
}

// Changes oneOutput from Interactive Code 1
void PageInputOutput::changeOneOutput()
{
    oneOutput->setText(oneInput->text().toUtf8().data());
}

// FUNCTION NAME: executeSample2()
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

// Generally Copied from scanfSyntax.cpp
// Just edited some codes to make it work for Qt

void PageInputOutput::executeSample2()
{
    CustomString *tempString = new CustomString;

    int sampleInt;

    tempString->appendText("Enter Value: 5\n");
    sampleInt = 5;
    tempString->appendText("The Value You Entered Is: ");
    tempString->appendText(sampleInt);

    addExample("Sample Output", tempString->getCustomString());
}

void PageInputOutput::changeOneLabel()
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
