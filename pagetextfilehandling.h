#ifndef PAGETEXTFILEHANDLING_H
#define PAGETEXTFILEHANDLING_H

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "referencepage.h"

class PageTextFileHandling : public ReferencePage
{
    Q_OBJECT

public:
    PageTextFileHandling();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *fileWriting;
    std::vector<dictionary *> *fileReading;
    QPushButton *oneButtonModify;
    QPushButton *oneButtonClear;
    QLabel *oneOutput;
    QPushButton *twoButtonModify;
    QPushButton *twoButtonClear;
    QLabel *twoOutput;

    void interactive1();
    void interactive2();
    void sample3Simulation();

private slots:
    void changeOneOutput();
    void clearOneOutput();
    void changeTwoOutput();
    void clearTwoOutput();
};

#endif // PAGETEXTFILEHANDLING_H
