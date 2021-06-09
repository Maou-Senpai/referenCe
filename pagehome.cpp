//Header Files
#include "pagehome.h"
#include <QLabel>

PageHome::PageHome()
{
    // No Dictionaries Here
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

void PageHome::showPage()
{
    pageLayout->setAlignment(Qt::AlignCenter);
    addImage(":/img/data/profile.png", 200);

    addHeader("Welcome to referenCe");
    addParagraphTitle("A Reference for Basic C and C++");
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

void PageHome::getDictionaries(std::vector<std::vector<dictionary *> *> *)
{
    // No Dictionaries Here
}
