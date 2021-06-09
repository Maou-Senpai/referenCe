#ifndef PAGELIBSTDIO_H
#define PAGELIBSTDIO_H

#include "referencepage.h"

class PageLibStdio : public ReferencePage
{
    Q_OBJECT

public:
    PageLibStdio();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *libFunctions;
};

#endif // PAGELIBSTDIO_H
