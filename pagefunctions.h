#ifndef PAGEFUNCTIONS_H
#define PAGEFUNCTIONS_H

#include "referencepage.h"

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
class PageFunctions : public ReferencePage
{
    Q_OBJECT

public:
    PageFunctions();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;
    QLineEdit *oneLine1;
    QLineEdit *oneLine2;
    QComboBox *oneComboBox;
    QLabel *oneLabel;
    QLabel *twoLabel;
    int add(int x, int y);
    int divide(int x, int y);
    int multiply(int x, int y);
    int subtract(int x, int y);
    void printMenu(CustomString *collectText);
private:
    void sampleSimulation1();
public slots:
    void changeOneLabel();
};

#endif // PAGEFUNCTIONS_H
