#ifndef PAGEPOINTERS_H
#define PAGEPOINTERS_H

#include "referencepage.h"

class PagePointers : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *pointerRules;

    PagePointers();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    void sampleSimulation1();
    void withoutPointer(int tempNumber, CustomString *collectText);
    void withPointer(int *tempNumber, CustomString *collectText);
};

#endif // PAGEPOINTERS_H
