#ifndef PAGELIBTIME_H
#define PAGELIBTIME_H

#include "referencepage.h"

class PageLibTime : public ReferencePage
{
    Q_OBJECT

public:
    PageLibTime();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *libFunctions;
};

#endif // PAGELIBTIME_H
