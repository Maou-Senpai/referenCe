#ifndef PAGEDATATYPES_H
#define PAGEDATATYPES_H

#include "referencepage.h"

class PageDataTypes : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *typeAndFormat;

    PageDataTypes();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;
    void executeSample1();
};

#endif // PAGEDATATYPES_H
