#ifndef PAGEINPUTOUTPUT_H
#define PAGEINPUTOUTPUT_H

#include "referencepage.h"
#include <QLineEdit>

class PageInputOutput : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *printfSyntax;
    std::vector<dictionary *> *scanfSyntax;
    QLabel *oneLabel;
    QLineEdit *oneInput;
    QLabel *oneOutput;

    PageInputOutput();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    void executeSample1();
    void executeSample2();
private slots:
    void changeOneOutput();
public slots:
    void changeOneLabel();
};

#endif // PAGEINPUTOUTPUT_H
