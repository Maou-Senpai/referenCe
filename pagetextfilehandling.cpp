//Header Files
#include "pagetextfilehandling.h"
#include <QFile>
#include <QTextStream>

// Initializes dictionaries
PageTextFileHandling::PageTextFileHandling()
{
    fileWriting = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/textFileWriting.txt", fileWriting);
    fileReading = new std::vector<dictionary *>;
    dictionaryFiller(":/txt/content/textFileReading.txt", fileReading);
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

void PageTextFileHandling::showPage()
{
    addHeader("Text File Handling");
    addParagraph("The built-in functions to use with file I/O are included in stdio.h.");

    addParagraphTitle("File Writing and Appending");
    addParagraph("Use \"w\" for file writing. Use \"a\" for file appending.");
    addItemInfoTable(fileWriting);
    addExampleTitle("Sample Code and Interactive for Writing");
    addExampleByFile("Sample Code", ":/cpp/content/textFilesWriting.cpp");
    addExampleTitle("Sample Text File Content");
    interactive1();
    addExampleTitle("Sample Code and Interactive for Appending");
    addExampleByFile("Sample Code", ":/cpp/content/textFilesAppending.cpp");
    addExampleTitle("Sample Text File Content");
    interactive2();

    addParagraphTitle("File Reading");
    addParagraph("Use \"r\" for file reading.");
    addItemInfoTable(fileReading);
    addExampleTitle("Sample Code and Output for Reading");
    addExampleByFile("Sample Code", ":/cpp/content/textFilesReading.cpp");
    addParagraph("feof() means end of file. It's purpose on the code is to stop the while-loop when the opened file ends.");
    sample3Simulation();
    addParagraph("Do not forget to use fclose(FILE *stream).");
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

void PageTextFileHandling::getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict)
{
    collectiveDict->push_back(fileWriting);
    collectiveDict->push_back(fileReading);
}

// Interactive Code 1
void PageTextFileHandling::interactive1()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    QFont font;
    font.setPointSize(14);

    oneButtonModify = new QPushButton;
    oneButtonModify->setText("Write on Text File");
    oneButtonModify->setMaximumWidth(400);
    oneButtonModify->setFont(font);
    widgetLayout->addWidget(oneButtonModify);

    oneButtonClear = new QPushButton;
    oneButtonClear->setText("Clear");
    oneButtonClear->setMaximumWidth(400);
    oneButtonClear->setFont(font);
    widgetLayout->addWidget(oneButtonClear);

    pageLayout->addWidget(widget);
    oneOutput = new QLabel;
    oneOutput->setAlignment(Qt::AlignCenter);
    declaredParagraph(oneOutput, "Sample File Content Here");

    connect(oneButtonModify, &QPushButton::pressed, this, &PageTextFileHandling::changeOneOutput);
    connect(oneButtonClear, &QPushButton::pressed, this, &PageTextFileHandling::clearOneOutput);
}

// Changes oneOutput from Interactive Code 1
void PageTextFileHandling::changeOneOutput()
{
    CustomString newOneOutput;

    newOneOutput.appendText("Test One\n");
    newOneOutput.appendText("a");
    newOneOutput.appendText("\nTest Two");

    oneOutput->setText(newOneOutput.getCustomString());
}

// Clears oneOutput from Interactive Code 1
void PageTextFileHandling::clearOneOutput()
{
    oneOutput->setText("File Content Here");
}

// Interactive Code 2
void PageTextFileHandling::interactive2()
{
    auto widget = new QWidget;
    auto widgetLayout = new QHBoxLayout;
    widget->setLayout(widgetLayout);

    QFont font;
    font.setPointSize(14);

    twoButtonModify = new QPushButton;
    twoButtonModify->setText("Append on Text File");
    twoButtonModify->setMaximumWidth(400);
    twoButtonModify->setFont(font);
    widgetLayout->addWidget(twoButtonModify);

    twoButtonClear = new QPushButton;
    twoButtonClear->setText("Clear");
    twoButtonClear->setMaximumWidth(400);
    twoButtonClear->setFont(font);
    widgetLayout->addWidget(twoButtonClear);

    pageLayout->addWidget(widget);
    twoOutput = new QLabel;
    twoOutput->setAlignment(Qt::AlignCenter);
    declaredParagraph(twoOutput, "Sample File Content Here");

    connect(twoButtonModify, &QPushButton::pressed, this, &PageTextFileHandling::changeTwoOutput);
    connect(twoButtonClear, &QPushButton::pressed, this, &PageTextFileHandling::clearTwoOutput);
}

// Changes twoOutput from Interactive Code 2
void PageTextFileHandling::changeTwoOutput()
{
    CustomString *newOutput = new CustomString;

    if (stricmp(twoOutput->text().toUtf8().data(), "Sample File Content Here") != 0) {
        newOutput->appendText(twoOutput->text().toUtf8().data());
    }
    newOutput->appendText("Test One\n");
    newOutput->appendText("a");
    newOutput->appendText("\nTest Two\n");

    twoOutput->setText(newOutput->getCustomString());
}

// Clears twoOutput from Interactive Code 2
void PageTextFileHandling::clearTwoOutput()
{
    twoOutput->setText("File Content Here");
}

// This is a sample simulation of the third sample code
// Modified to make it work in Qt
void PageTextFileHandling::sample3Simulation()
{
    CustomString sampleText;

    QFile contentFile(":/cpp/content/sampleText.txt");
    if (contentFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&contentFile);
        sampleText.appendText(in.readAll().toUtf8().data());
        contentFile.close();
    }

    addExample("Sample Output (This is the Exact Content of sampleText.txt)", sampleText.getCustomString());
}
