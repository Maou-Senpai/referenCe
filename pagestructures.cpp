#include "pagestructures.h"

// Initializes dictionaries
PageStructures::PageStructures()
{
    structuresKeywords = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/structuresKeywords.txt", structuresKeywords);
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

void PageStructures::showPage()
{
    addHeader("Structures");
    addParagraph("Allows grouping of different data types under one name.");

    addParagraphTitle("struct and typedef");
    addItemInfoTable(structuresKeywords);
    addExampleByFile("struct Syntax", ":/txt/content/structWord.txt");
    addExampleByFile("typedef Syntax", ":/txt/content/typedefWord.txt");

    addParagraph("To access data, use \".\". You can also use pointers with structures. For pointers, use \"->\" to access data.");
    addExampleByFile("Sample Code", ":/cpp/content/structures.cpp");
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

void PageStructures::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(structuresKeywords);
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

void PageStructures::sample1Simulation()
{
    CustomString sampleText;

    typedef struct movie {
        const char *title;
        int releasedYear;
    } Movie;

    Movie movie1;
    Movie *movie2 = new Movie;

    movie1.title = "Good Will Hunting";
    movie1.releasedYear = 1997;
    movie2->title = "Lost in Translation";
    movie2->releasedYear = 2003;

    sampleText.appendText(movie1.title);
    sampleText.appendText("\n");
    sampleText.appendText(movie1.releasedYear);
    sampleText.appendText("\n");
    sampleText.appendText(movie2->title);
    sampleText.appendText("\n");
    sampleText.appendText(movie2->releasedYear);

    addExample("Output", sampleText.getCustomString());
}
