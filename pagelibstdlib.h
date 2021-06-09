#ifndef PAGELIBSTDLIB_H
#define PAGELIBSTDLIB_H

#include "referencepage.h"

class PageLibStdlib : public ReferencePage
{
    Q_OBJECT

public:
    PageLibStdlib();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    std::vector<dictionary *> *libFunctions;
};

#endif // PAGELIBSTDLIB_H
