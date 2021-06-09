//Header Files
#include "pagelooping.h"

// Initializes dictionaries
PageLooping::PageLooping()
{
    loopingTypes = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/loopingTypes.txt", loopingTypes);
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

void PageLooping::showPage()
{
    addHeader("Looping");

    addParagraphTitle("For, While, and Do-While");
    addItemInfoTable(loopingTypes);
    addExampleByFile("For Syntax", ":/txt/content/forSyntax.txt");
    addExampleByFile("While Syntax", ":/txt/content/whileSyntax.txt");
    addExampleByFile("Do-While Syntax", ":/txt/content/doWhileSyntax.txt");

    addExampleByFile("For Sample Code", ":/cpp/content/loopFor.cpp");
    sample1Simulation();
    addExampleByFile("While vs Do-While Sample Code", ":/cpp/content/loopWhileVsDoWhile.cpp");
    sample2Simulation();

    addParagraph("The while didn't print because it didn't meet the condition. The do-while is guaranteed to execute at least once.");
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

void PageLooping::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(loopingTypes);
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

void PageLooping::sample1Simulation()
{
    CustomString *sampleText = new CustomString;

    sampleText->appendText("Count 1 to 10\n");

    for (int i = 0; i < 10; i++) {
        sampleText->appendText("\nCount ");
        sampleText->appendText(i + 1);
    }

    addExample("Output", sampleText->getCustomString());
}

// FUNCTION NAME: sample2Simulation()
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
// This is a sample simulation of the second sample code
// Modified to make it work in Qt

void PageLooping::sample2Simulation()
{
    CustomString *sampleText = new CustomString;

    int i;

    sampleText->appendText("Print Loop Counter\n");

    i = 1;
    sampleText->appendText("\nFor While:");
    while (i < 1)
    {
        sampleText->appendText("\nThis is Loop ");
        sampleText->appendText(i);
        i++;
    }
    sampleText->appendText("\n");

    i = 1;
    sampleText->appendText("\nFor Do-While:");
    do
    {
        sampleText->appendText("\nThis is Loop ");
        sampleText->appendText(i);
        i++;
    } while (i < 1);

    addExample("Output", sampleText->getCustomString());
}
