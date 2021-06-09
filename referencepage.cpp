#include "pagedatatypes.h"
#include "referencepage.h"
#include "customstring.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

// This is a template for all the pages
ReferencePage::ReferencePage() {
    pageLayout = new QVBoxLayout;
    this->setLayout(pageLayout);
    this->setAutoFillBackground(true);
    QPalette pallete = palette();
    pallete.setColor(QPalette::Background, Qt::white);
    this->setPalette(pallete);
    pageLayout->setAlignment(Qt::AlignTop);
    pageLayout->setSpacing(20);
    pageLayout->setContentsMargins(30, 20, 30, 20);
}

// Adds a text fitting for a title using a given string
void ReferencePage::addHeader(const char *text) {
    QLabel *header = new QLabel(this);
    header->setAlignment(Qt::AlignCenter);
    header->setText(text);
    header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    QFont font;
    font.setPointSize(36);
    header->setFont(font);

    pageLayout->addWidget(header);
}

// Adds a text fitting for a paragraph title using a given string
void ReferencePage::addParagraphTitle(const char *text)
{
    QLabel *parag = new QLabel(this);
    parag->setAlignment(Qt::AlignCenter);
    parag->setText(text);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);
    parag->setContentsMargins(16, 20, 16, 8);
    parag->setStyleSheet("border-top: 3px solid black");

    QFont font;
    font.setPointSize(18);
    font.setBold(true);
    parag->setFont(font);

    pageLayout->addWidget(parag);
}

// Adds a text fitting for a paragraph using a given string
void ReferencePage::addParagraph(const char *text)
{
    QLabel *parag = new QLabel(this);
    parag->setAlignment(Qt::AlignCenter);
    parag->setText(text);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);
    parag->setContentsMargins(50, 0, 50, 0);

    QFont font;
    font.setPointSize(14);
    parag->setFont(font);

    pageLayout->addWidget(parag);
}

// Adds a text fitting for an example title using a given string
void ReferencePage::addExampleTitle(const char *text)
{
    QLabel *parag = new QLabel(this);
    parag->setAlignment(Qt::AlignCenter);
    parag->setText(text);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);

    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    parag->setFont(font);

    pageLayout->addWidget(parag);
}

// Adds a text fitting for an example using a given string
void ReferencePage::addExample(const char *label, const char *text)
{
    QWidget *example = new QWidget;
    QVBoxLayout *exampleLayout = new QVBoxLayout;
    example->setLayout(exampleLayout);
    exampleLayout->setContentsMargins(50, 0, 50, 0);

    QLabel *parag = new QLabel(this);
    parag->setAlignment(Qt::AlignVCenter);
    parag->setText(label);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);

    QFont font;
    font.setPointSize(14);
    parag->setFont(font);

    exampleLayout->addWidget(parag);

    parag = new QLabel(this);
    parag->setAlignment(Qt::AlignVCenter);
    parag->setText(text);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);
    parag->setContentsMargins(0, 10, 0, 10);
    parag->setStyleSheet("border: 2px solid black");
    parag->setTextInteractionFlags(Qt::TextSelectableByMouse);

    font.setPointSize(12);
    parag->setFont(font);

    exampleLayout->addWidget(parag);
    pageLayout->addWidget(example);
}

// Adds an image
void ReferencePage::addImage(const char *fileName, int scaleToWidth)
{
    QPixmap image;
    QLabel *imageContainer = new QLabel;
    image.load(fileName);
    imageContainer->setPixmap(image.scaledToWidth(scaleToWidth));
    imageContainer->setAlignment(Qt::AlignCenter);
    pageLayout->addWidget(imageContainer);
}

// Similar with addParagraph but this accepts an object of QLabel
void ReferencePage::declaredParagraph(QLabel *emptyQLabel, const char *tempText)
{
    QWidget *labelContainer = new QWidget;
    QHBoxLayout *containerLayout = new QHBoxLayout;
    labelContainer->setLayout(containerLayout);
    labelContainer->setContentsMargins(200, 0, 200, 0);

    emptyQLabel->setAlignment(Qt::AlignCenter);
    emptyQLabel->setText(tempText);
    emptyQLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    emptyQLabel->setWordWrap(true);
    emptyQLabel->setStyleSheet("border: 3px solid border");
    emptyQLabel->setContentsMargins(0, 10, 0, 10);

    QFont font;
    font.setPointSize(14);
    emptyQLabel->setFont(font);

    containerLayout->addWidget(emptyQLabel);
    pageLayout->addWidget(labelContainer);
}

// Adds a text fitting for an example using a given string
void ReferencePage::addExampleByFile(const char *label, const char *textFile)
{
    QWidget *example = new QWidget;
    QVBoxLayout *exampleLayout = new QVBoxLayout;
    example->setLayout(exampleLayout);
    exampleLayout->setContentsMargins(50, 0, 50, 0);

    QLabel *parag = new QLabel(this);
    parag->setAlignment(Qt::AlignVCenter);
    parag->setText(label);
    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);

    QFont font;
    font.setPointSize(14);
    parag->setFont(font);

    exampleLayout->addWidget(parag);

    parag = new QLabel(this);
    parag->setAlignment(Qt::AlignVCenter);

    QFile contentFile(textFile);
    if (contentFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&contentFile);
        CustomString *content = new CustomString(in.readAll());
        parag->setText(content->getCustomString());
        contentFile.close();
    }

    parag->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    parag->setWordWrap(true);
    parag->setContentsMargins(0, 10, 0, 10);
    parag->setStyleSheet("border: 2px solid black");
    parag->setTextInteractionFlags(Qt::TextSelectableByMouse);

    font.setPointSize(12);
    parag->setFont(font);

    exampleLayout->addWidget(parag);
    pageLayout->addWidget(example);
}

// Adds a table based on the contents of a dictionary vector
void ReferencePage::addItemInfoTable(std::vector<dictionary *> *tempDict)
{
    QWidget *table = new QWidget;
    QGridLayout *tableLayout = new QGridLayout;
    table->setLayout(tableLayout);
    tableLayout->setSpacing(20);

    QFont font;
    font.setPointSize(16);

    QLabel *temp;
    for (std::size_t i = 0; i < tempDict->size(); i++) {
        if (i == 0) font.setBold(true);
        else font.setBold(false);

        temp = new QLabel(tempDict->at(i)->item);
        temp->setFont(font);
        temp->setAlignment(Qt::AlignCenter);
        temp->setWordWrap(true);
        tableLayout->addWidget(temp, i, 0);

        temp = new QLabel(tempDict->at(i)->info);
        temp->setFont(font);
        temp->setAlignment(Qt::AlignCenter);
        temp->setWordWrap(true);
        tableLayout->addWidget(temp, i, 1);
    }

    pageLayout->addWidget(table);
}

// Fills a vector of dictionary using the contents of a text file
void ReferencePage::dictionaryFiller(const char *txtFile, std::vector<dictionary *> *tempDictVector)
{
    QFile contentFile(txtFile);
    if (contentFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&contentFile);
        while (!in.atEnd())
        {
            tempDictVector->push_back(new dictionary);
            tempDictVector->back()->item = in.readLine();
            tempDictVector->back()->info = in.readLine();
        }
        contentFile.close();
    }
}
