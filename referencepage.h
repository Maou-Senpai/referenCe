#ifndef REFERENCEPAGE_H
#define REFERENCEPAGE_H

#include "dictionary.h"
#include <customstring.h>

#include <QMessageBox>
#include <iostream>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class ReferencePage : public QWidget, dictionary
{
    Q_OBJECT

public:
    QVBoxLayout *pageLayout;

    ReferencePage();
    void addHeader(const char *text);
    void addParagraphTitle(const char *text);
    void addParagraph(const char *text);
    void addItemInfoTable(std::vector<dictionary *> *tempDict);
    void dictionaryFiller(const char *txtFile, std::vector<dictionary *> *tempDictVector);
    void addExampleTitle(const char *text);
    void addExampleByFile(const char *label, const char *textFile);
    void addExample(const char *label, const char *text);
    void addImage(const char *fileName, int scaleToWidth);
    void declaredParagraph(QLabel *emptyQLabel, const char *tempText);

    // This two functions should vary per page
    virtual void showPage() = 0;
    virtual void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) = 0;
};

#endif // REFERENCEPAGE_H
