#ifndef PAGELIBMATH_H
#define PAGELIBMATH_H

#include "referencepage.h"

class PageLibMath : public ReferencePage
{
    Q_OBJECT

public:
    PageLibMath();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *libFunctions;
};

#endif // PAGELIBMATH_H
