//Header Files
#include "pagemissing.h"

PageMissing::PageMissing()
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

void PageMissing::showPage()
{
    pageLayout->setAlignment(Qt::AlignCenter);
    addHeader("Page Is Missing");
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

void PageMissing::getDictionaries(std::vector<std::vector<dictionary *> *> *)
{
    // No Dictionaries Here
}
