#ifndef PAGEDYNAMICMEMORY_H
#define PAGEDYNAMICMEMORY_H

#include "referencepage.h"

class PageDynamicMemory : public ReferencePage
{
    Q_OBJECT

public:
    PageDynamicMemory();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *mallocSyntax;
    std::vector<dictionary *> *callocSyntax;
    std::vector<dictionary *> *reallocSyntax;
    std::vector<dictionary *> *newSyntax;

    void sample1Simulation();
    void sample2Simulation();
    void sample3Simulation();
    void sample4Simulation();
};

#endif // PAGEDYNAMICMEMORY_H
