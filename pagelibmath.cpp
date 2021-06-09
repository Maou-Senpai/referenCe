#include "pagelibmath.h"

// Initializes dictionaries
PageLibMath::PageLibMath()
{
    libFunctions = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/libmath.txt", libFunctions);
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

void PageLibMath::showPage()
{
    addHeader("math.h");

    addParagraphTitle("Functions");
    addItemInfoTable(libFunctions);
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

void PageLibMath::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(libFunctions);
}
