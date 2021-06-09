//Header Files
#include "pagelibstdlib.h"

// Initializes dictionaries
PageLibStdlib::PageLibStdlib()
{
    libFunctions = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/libstdlib.txt", libFunctions);
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

void PageLibStdlib::showPage()
{
    addHeader("stdlib.h");

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

void PageLibStdlib::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(libFunctions);
}
