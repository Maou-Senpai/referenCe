#ifndef PAGEMODULAR_H
#define PAGEMODULAR_H

#include "referencepage.h"

#include <QLineEdit>
#include <QLabel>

class PageModular : public ReferencePage
{
    Q_OBJECT

public:
    PageModular();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

    int add(int x, int y);
    int divide(int x, int y);
    int multiply(int x, int y);
    int subtract(int x, int y);
    void printMenu(CustomString *collectText);

private:
    void sampleSimulation1();
};

#endif // PAGEMODULAR_H
