#ifndef PAGESTRUCTURES_H
#define PAGESTRUCTURES_H

#include "referencepage.h"

class PageStructures : public ReferencePage
{
    Q_OBJECT

public:
    PageStructures();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *structuresKeywords;

    void sample1Simulation();
    void sample2Simulation();
};

#endif // PAGESTRUCTURES_H
