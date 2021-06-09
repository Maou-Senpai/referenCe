//Header Files
#include "pageclass.h"

// Initializes dictionaries
PageClass::PageClass()
{
    objectOriented = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/objectOriented.txt", objectOriented);
    accessLevels = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/accessLevels.txt", accessLevels);
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

void PageClass::showPage()
{
    addHeader("Object-Oriented Programming");
    addParagraphTitle("Classes and Objects");
    addItemInfoTable(objectOriented);
    addExampleByFile("Sample Code", ":/cpp/content/class.cpp");
    sample1Simulation();
    addParagraph("In this case, movie1 and movie2 are considered as objects. There are also different access levels. We used public in the Sample Code.");
    addItemInfoTable(accessLevels);
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

void PageClass::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(objectOriented);
    collectiveDict->push_back(accessLevels);
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

void PageClass::sample1Simulation()
{
    CustomString sampleText;

    class Movie {
        public:
            const char *title;
            int releasedYear;

            // This is a Constructor
            Movie (const char *passedTitle, int passedReleasedYear) {
                title = passedTitle;
                releasedYear = passedReleasedYear;
            }

            int yearsSinceReleased(int currentYear) {
                return currentYear - releasedYear;
            }
    };

    Movie movie1("Good Will Hunting", 1997);
    Movie *movie2 = new Movie("Lost in Translation", 2003);

    int currentYear = 2020;
    sampleText.appendText("Years Since ");
    sampleText.appendText(movie1.title);
    sampleText.appendText(" Released: ");
    sampleText.appendText(movie1.yearsSinceReleased(currentYear));
    sampleText.appendText("\n");
    sampleText.appendText("Years Since ");
    sampleText.appendText(movie2->title);
    sampleText.appendText(" Released: ");
    sampleText.appendText(movie2->yearsSinceReleased(currentYear));

    addExample("Output", sampleText.getCustomString());
}
