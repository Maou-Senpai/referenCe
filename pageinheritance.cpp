//Header Files
#include "pageinheritance.h"

// Initializes dictionaries
PageInheritance::PageInheritance()
{
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

void PageInheritance::showPage()
{
    addHeader("Inheritance");
    addItemInfoTable(accessLevels);
    addParagraph("You can derive from an existing class by adding \":\". It is easier to understand by looking at the code below.");
    addExampleByFile("Sample Code", ":/cpp/content/inheritance.cpp");
    addParagraph("In this example, let us assume that the only type of movies that have moral lessons are documentaries. The Documentary class is a subclass of Movie. It inherits the public properties of the Movie class. This means that an object of Documentary class will also have its own title and releasedYear. It can also use the yearsSinceReleased function.");
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

void PageInheritance::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
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

void PageInheritance::sample1Simulation()
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

    class Documentary : public Movie {
        public:
            // This is a constructor that calls a constructor from the parent class
            Documentary(const char *title, int year, const char *passedLesson) : Movie(title, year) {
                lesson = passedLesson;
            }

            const char *getLesson() {
                return lesson;
            }

        private:
            const char *lesson;
    };

    Documentary *doc = new Documentary("Sample Documentary", 2012, "Time is Gold");

    sampleText.appendText(doc->title);
    sampleText.appendText("\n");
    sampleText.appendText(doc->releasedYear);
    sampleText.appendText("\n");
    sampleText.appendText(doc->getLesson());
    sampleText.appendText("\n");
    sampleText.appendText(doc->yearsSinceReleased(2020));
    sampleText.appendText(" Years Since Released");

    addExample("Output", sampleText.getCustomString());
}
