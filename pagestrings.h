#ifndef PAGESTRINGS_H
#define PAGESTRINGS_H

#include <QLineEdit>
#include <QLabel>

#include "referencepage.h"

class PageStrings : public ReferencePage
{
    Q_OBJECT

public:
    PageStrings();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    QLabel *oneLabel;
    QLineEdit *oneInput;
    QLabel *oneOutput;

    void sample1Simulation();
    void interactive1();

private slots:
    void changeOneOutput();
};

#endif // PAGESTRINGS_H
