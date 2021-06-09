//Header Files
#include "pagedatatypes.h"

// Initializes dictionaries
PageDataTypes::PageDataTypes()
{
    typeAndFormat = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/typeAndFormat.txt", typeAndFormat);
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

void PageDataTypes::showPage()
{
    addHeader("Data Types");

    addParagraphTitle("Built-In Data Types with Format Specifiers");
    addParagraph("To Declare Variables, use the syntax: <variable type> <name of variable>;");
    addItemInfoTable(typeAndFormat);
    addExampleByFile("Sample Code", ":/cpp/content/typeAndFormat.cpp");
    executeSample1();
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

void PageDataTypes::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(typeAndFormat);
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

// Generally Copied from typeAndFormat.cpp
// Just edited the printf()s to something more appropriate

void PageDataTypes::executeSample1()
{
    CustomString *tempString = new CustomString;

    int sampleInt = 1;
    short sampleShort = 2;
    long sampleLong = 3;
    char sampleChar = 'a';
    float sampleFloat = 4.1;
    double sampleDouble = 5.2;

    tempString->appendText(sampleInt);
    tempString->appendText("\n");
    tempString->appendText(sampleShort);
    tempString->appendText("\n");
    tempString->appendText(sampleLong);
    tempString->appendText("\n");
    tempString->appendChar(sampleChar);
    tempString->appendText("\n");
    tempString->appendText(sampleFloat);
    tempString->appendText("\n");
    tempString->appendText(sampleDouble);
    addExample("Sample Output", tempString->getCustomString());
}
