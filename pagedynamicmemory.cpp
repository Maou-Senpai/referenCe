//Header Files

#include "pagedynamicmemory.h"

#include <QMessageBox>

// Initializes dictionaries
PageDynamicMemory::PageDynamicMemory()
{
    mallocSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/mallocSyntax.txt", mallocSyntax);
    callocSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/callocSyntax.txt", callocSyntax);
    reallocSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/callocSyntax.txt", reallocSyntax);
    newSyntax = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/newSyntax.txt", newSyntax);
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

void PageDynamicMemory::showPage()
{
    addHeader("Dynamic Memory Allocation");
    addParagraph("Don't know how much memory you need for your array? This is the solution coming from the stdlib.h library.");

    addParagraphTitle("malloc()");
    addItemInfoTable(mallocSyntax);
//    addExampleByFile("Sample Code", ":/cpp/content/mallocSyntax.cpp");
    addParagraph("The expression inside the malloc call computes how many memory to allocate. In this case, it literally makes space for the size of an int type * the input for number of elements. The (int *) in front of malloc is a typecast in C. In this case, it makes the contents of the memory be treated as an int value. After allocating the memory, you can now treat the pointer like an array.");
    sample1Simulation();

    addParagraphTitle("calloc()");
    addParagraph("The calloc is just similar to malloc, but this time, instead of leaving the memory uninitialized, calloc initializes all of them to 0.");
    addItemInfoTable(callocSyntax);
    addExampleByFile("Sample Code", ":/cpp/content/callocSyntax.cpp");
    sample2Simulation();

    addParagraphTitle("realloc()");
    addParagraph("The realloc is an additional function if the memory allocated from malloc or calloc is still not enough.");
    addItemInfoTable(reallocSyntax);
    addExampleByFile("Sample Code", ":/cpp/content/reallocSyntax.cpp");
    sample3Simulation();

    addParagraph("Do not forget to use free(pointer) to deallocate memory.");

    addParagraphTitle("new Keyword from C++");
    addItemInfoTable(newSyntax);
    addExampleByFile("Sample Code", ":/cpp/content/newSyntax.cpp");
    sample4Simulation();

    addParagraph("Do not forget to use the delete keyword to deallocate memory made using \"new\". Adding [] on delete deallocates memory for the entire array.");
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

void PageDynamicMemory::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(mallocSyntax);
    collectiveDict->push_back(callocSyntax);
    collectiveDict->push_back(reallocSyntax);
    collectiveDict->push_back(newSyntax);
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

void PageDynamicMemory::sample1Simulation()
{
    CustomString sampleText;

    int arrayElementCount;
    int *ptr;

    sampleText.appendText("Enter How Many Values: 3\n");
    arrayElementCount = 3;
    sampleText.appendText("\n");

    ptr = (int *) malloc(arrayElementCount * 2 * sizeof(int));

    sampleText.appendText("Enter Digit 1: 1\n");
    ptr[0] = 1;
    sampleText.appendText("Enter Digit 2: 2\n");
    ptr[1] = 2;
    sampleText.appendText("Enter Digit 3: 3\n");
    ptr[2] = 3;

    for (int i = 0; i < arrayElementCount; i++) {
        sampleText.appendText("\nDigit ");
        sampleText.appendText(i + 1);
        sampleText.appendText(": ");
        sampleText.appendText(ptr[i]);
    }

    free(ptr);

    addExample("Sample Run", sampleText.getCustomString());
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

void PageDynamicMemory::sample2Simulation()
{
    CustomString sampleText;

    int arrayElementCount;
    int *ptr = NULL;

    sampleText.appendText("Enter How Many Values: 3\n");
    arrayElementCount = 3;
    sampleText.appendText("\n");

    ptr = (int *) calloc(arrayElementCount * 2, sizeof(int));

    for (int i = 0; i < arrayElementCount; i++) {
        sampleText.appendText("Digit ");
        sampleText.appendText(i + 1);
        sampleText.appendText(" After Memory Allocation: ");
        sampleText.appendText(ptr[i]);
        sampleText.appendText("\n");
    }
    sampleText.appendText("\n");

    sampleText.appendText("Enter Digit 1: 1\n");
    ptr[0] = 1;
    sampleText.appendText("Enter Digit 2: 2\n");
    ptr[1] = 2;
    sampleText.appendText("Enter Digit 3: 3\n");
    ptr[2] = 3;

    for (int i = 0; i < arrayElementCount; i++) {
        sampleText.appendText("\nDigit ");
        sampleText.appendText(i + 1);
        sampleText.appendText(": ");
        sampleText.appendText(ptr[i]);
    }

    free(ptr);

    addExample("Sample Run", sampleText.getCustomString());
}

// FUNCTION NAME: sample3Simulation()
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
// This is a sample simulation of the third sample code
// Modified to make it work in Qt

void PageDynamicMemory::sample3Simulation()
{
    CustomString sampleText;

    int arrayElementCount, additionalElementCount;
    int *ptr;

    sampleText.appendText("Enter How Many Values: 3\n");
    arrayElementCount = 3;
    sampleText.appendText("\n");

    ptr = (int *) malloc(arrayElementCount * 2 * sizeof(int));

    sampleText.appendText("Enter Digit 1: 1\n");
    ptr[0] = 1;
    sampleText.appendText("Enter Digit 2: 2\n");
    ptr[1] = 2;
    sampleText.appendText("Enter Digit 3: 3\n");
    ptr[2] = 3;

    for (int i = 0; i < arrayElementCount; i++) {
        sampleText.appendText("\nDigit ");
        sampleText.appendText(i + 1);
        sampleText.appendText(": ");
        sampleText.appendText(ptr[i]);
    }

    sampleText.appendText("\n\nEnter How Many Additional Values: 1");
    additionalElementCount = 1;
    sampleText.appendText("\n");

    // This is causing error in Qt, but it works when pasted in DevC++
//    ptr = (int *) realloc(ptr, additionalElementCount * sizeof(int));

    sampleText.appendText("Enter Digit 4: 6\n");
    ptr[3] = 6;

    for (int i = 0; i < additionalElementCount; i++) {
        sampleText.appendText("\nDigit ");
        sampleText.appendText(i + arrayElementCount + 1);
        sampleText.appendText(": ");
        sampleText.appendText(ptr[i + arrayElementCount]);
    }

    addExample("Sample Run", sampleText.getCustomString());
}

// FUNCTION NAME: sample4Simulation()
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
// This is a sample simulation of the fourth sample code
// Modified to make it work in Qt

void PageDynamicMemory::sample4Simulation()
{
    CustomString sampleText;

    int arrayElementCount;
    int *ptr;

    sampleText.appendText("Enter How Many Values: 3\n");
    arrayElementCount = 3;
    sampleText.appendText("\n");

    ptr = new int[arrayElementCount];

    sampleText.appendText("Enter Digit 1: 1\n");
    ptr[0] = 1;
    sampleText.appendText("Enter Digit 2: 2\n");
    ptr[1] = 2;
    sampleText.appendText("Enter Digit 3: 3\n");
    ptr[2] = 3;

    for (int i = 0; i < arrayElementCount; i++) {
        sampleText.appendText("\nDigit ");
        sampleText.appendText(i + 1);
        sampleText.appendText(": ");
        sampleText.appendText(ptr[i]);
    }

    delete[] ptr;

    addExample("Sample Run", sampleText.getCustomString());
}
