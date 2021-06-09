#ifndef PAGECLASS_H
#define PAGECLASS_H

#include "referencepage.h"

class PageClass : public ReferencePage
{
    Q_OBJECT

public:
    PageClass();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *objectOriented;
    std::vector<dictionary *> *accessLevels;

    void sample1Simulation();
};

#endif // PAGECLASS_H
