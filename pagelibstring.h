#ifndef PAGELIBSTRING_H
#define PAGELIBSTRING_H

#include "referencepage.h"

class PageLibString : public ReferencePage
{
    Q_OBJECT

public:
    PageLibString();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *libFunctions;
};

#endif // PAGELIBSTRING_H
