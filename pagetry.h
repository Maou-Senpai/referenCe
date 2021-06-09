#ifndef PAGETRY_H
#define PAGETRY_H

#include "referencepage.h"

class PageTry : public ReferencePage
{
    Q_OBJECT

public:
    PageTry();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *exceptionTerms;

    void sample1Simulation();
};

#endif // PAGETRY_H
