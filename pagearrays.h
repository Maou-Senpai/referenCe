#ifndef PAGEARRAYS_H
#define PAGEARRAYS_H

#include "referencepage.h"

class PageArrays : public ReferencePage
{
    Q_OBJECT

public:
    PageArrays();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    void sample1Simulation();
    void sample2Simulation();
    void sample3Simulation();
    void sample4Simulation();
    void sample5Simulation();
    void sample6Simulation();
};

#endif // PAGEARRAYS_H
