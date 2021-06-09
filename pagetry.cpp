#include "pagetry.h"

// Initializes dictionaries
PageTry::PageTry()
{
    exceptionTerms = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/exceptionTerms.txt", exceptionTerms);
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

void PageTry::showPage()
{
    addHeader("Exception Handling");

    addParagraphTitle("Try, Throw, and Catch");
    addItemInfoTable(exceptionTerms);
    addExampleByFile("Syntax", ":/txt/content/tryThrowCatchSyntax.txt");
    addParagraph("Throw is optional if you want to make your own exceptions. We won't focus on it though in this page. To capture all errors, use triple dots \"...\" in catch.");
    addExampleByFile("Sample Code", ":/cpp/content/tryCatch.cpp");
    sample1Simulation();
    addParagraph("The example above inputs -5 for array size. Since this will cause an error, the program proceeds to execute the block inside catch instead of doing printf(\"Success\").");
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

void PageTry::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(exceptionTerms);
}

// This is a sample simulation of the first sample code
// Modified to make it work in Qt
void PageTry::sample1Simulation()
{
    CustomString sampleText;

    int arraySize;

    sampleText.appendText("Enter Array Size: -5\n");
    arraySize = -5;

    try {
        new int[arraySize];
        sampleText.appendText("Success");
    }
    catch (...) {
        sampleText.appendText("Fail");
    }

    addExample("Sample Output", sampleText.getCustomString());
}
