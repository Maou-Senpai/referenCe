#include "pagelibstdio.h"

// Initializes dictionaries
PageLibStdio::PageLibStdio()
{
    libFunctions = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/libstdio.txt", libFunctions);
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

void PageLibStdio::showPage()
{
    addHeader("stdio.h");

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

void PageLibStdio::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(libFunctions);
}
