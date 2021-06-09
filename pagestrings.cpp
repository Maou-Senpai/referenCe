#include "pagestrings.h"

// Initializes dictionaries
PageStrings::PageStrings()
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

void PageStrings::showPage()
{
    addHeader("Strings");

    addParagraphTitle("Character Array");
    addParagraph("Strings in C are just one-dimensional arrays of char. We can use index to get a certain character. Strings are accompanied by a null character \"\\0\" to signify the end of a string. It is automatically added by the compiler.");
    addExampleTitle("Interactive Code");
    interactive1();

    addParagraphTitle("Sample Code and Run");
    addParagraph("Array size is not required if the declaration is joined with the initialization.");
    addExampleByFile("Sample Code", ":/cpp/content/strings.cpp");
    sample1Simulation();
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

void PageStrings::getDictionaries(std::vector<std::vector<dictionary *> *> *)
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
// Mostly copied from the actual cpp file

void PageStrings::sample1Simulation()
{
    CustomString sampleText;
    char word[] = "hello";
    sampleText.appendText(word);
    sampleText.appendText("\n\n");

    sampleText.appendText("Input Word: goodbye\n");
    sampleText.appendText("Scanned Word: goodbye");

    addExample("Sample Run", sampleText.getCustomString());
}

// Interactive Code 1
void PageStrings::interactive1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    oneLabel = new QLabel;
    oneLabel->setText("Enter Word (Max. 10)");
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
    declaredParagraph(oneOutput, "Array Here");

    connect(oneInput, &QLineEdit::textChanged, this, &PageStrings::changeOneOutput);
}

// Changes oneOutput from Interactive Code 1
void PageStrings::changeOneOutput()
{
    CustomString newOneOutput;
    CustomString *oneInputText = new CustomString(oneInput->text());

    newOneOutput.appendText("{");
    for (int i = 0; i < oneInputText->getCustomStringSize(); i++) {
        if (i != 0) newOneOutput.appendText(", ");
        newOneOutput.appendChar(oneInputText->charAt(i));
    }
    newOneOutput.appendText(", \\0}");

    oneOutput->setText(newOneOutput.getCustomString());
}
