#ifndef PAGELOOPING_H
#define PAGELOOPING_H

#include "referencepage.h"

class PageLooping : public ReferencePage
{
    Q_OBJECT

public:
    PageLooping();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *loopingTypes;

    void sample1Simulation();
    void sample2Simulation();
};

#endif // PAGELOOPING_H
