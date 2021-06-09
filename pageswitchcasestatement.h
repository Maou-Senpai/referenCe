#ifndef PAGESWITCHCASESTATEMENT_H
#define PAGESWITCHCASESTATEMENT_H

#include "referencepage.h"

#include <QLineEdit>
#include <QLabel>

class PageSwitchCaseStatement : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *switchCaseStatement;
    QLabel *oneLabel;
    QLineEdit *oneInput;
    QLabel *oneOutput;

    PageSwitchCaseStatement();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    void activeCode1();

public slots:
    void changeOneLabel();
};

#endif // PAGESWITCHCASESTATEMENT_H
