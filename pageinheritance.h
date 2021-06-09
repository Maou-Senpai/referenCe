#ifndef PAGEINHERITANCE_H
#define PAGEINHERITANCE_H

#include "referencepage.h"

class PageInheritance : public ReferencePage
{
    Q_OBJECT

public:
    PageInheritance();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *accessLevels;

    void sample1Simulation();
};

#endif // PAGEINHERITANCE_H
