#ifndef PAGEIFSTATEMENT_H
#define PAGEIFSTATEMENT_H

#include "referencepage.h"

#include <QLineEdit>
#include <QLabel>

class PageIfStatement : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *ifStatement;
    QLabel *oneLabel;
    QLineEdit *oneInput;
    QLabel *oneOutput;

    PageIfStatement();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    void activeCode1();

public slots:
    void changeOneLabel();
};

#endif // PAGEIFSTATEMENT_H
