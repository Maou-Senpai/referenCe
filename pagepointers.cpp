//Header Files
#include "pagepointers.h"

// Initializes dictionaries
PagePointers::PagePointers()
{
    pointerRules = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/pointerRules.txt", pointerRules);
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

void PagePointers::showPage()
{
    addHeader("Pointers");
    addParagraphTitle("Pointers Store Memory Locations");
    addParagraph("To declare a variable as a pointer, \"*\" must be appended in front. To get the memory address of a variable, \"&\" must be appended in front. Pointers are used to store these values. This is convenient when working with functions because a new instance of the object is created every time a value is passed through an argument. To access the value of a pointer, append \"*\" in the front.");
    addExampleByFile("Sample Code", ":/cpp/content/pointers.cpp");
    sampleSimulation1();
    addParagraphTitle("Pointer Rules");
    addParagraph("The following are allowable expressions.");
    addItemInfoTable(pointerRules);
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

void PagePointers::getDictionaries(std::vector<std::vector<dictionary *> *> *collectText)
{
    collectText->push_back(pointerRules);
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

void PagePointers::sampleSimulation1()
{
    CustomString collectText;
    int number = 5;

    withoutPointer(number, &collectText);
    collectText.appendText("Value After withoutPointer Function: ");
    collectText.appendText(number);
    collectText.appendText("\n\n");
    withPointer(&number, &collectText);
    collectText.appendText("Value After withPointer Function: ");
    collectText.appendText(number);

    addExample("Program Run", collectText.getCustomString());
}

void PagePointers::withoutPointer(int tempNumber, CustomString *collectText) {
    tempNumber += 5;
    collectText->appendText("Value Inside withoutPointer Function: ");
    collectText->appendText(tempNumber);
    collectText->appendText("\n");
}

void PagePointers::withPointer(int *tempNumber, CustomString *collectText) {
    *tempNumber += 5;
    collectText->appendText("Value Inside withPointer Function: ");
    collectText->appendText(*tempNumber);
    collectText->appendText("\n");
}
