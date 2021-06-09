#ifndef PAGEHOME_H
#define PAGEHOME_H

#include "referencepage.h"

class PageHome : public ReferencePage
{
    Q_OBJECT

public:
    PageHome();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;
};

#endif // PAGEHOME_H
