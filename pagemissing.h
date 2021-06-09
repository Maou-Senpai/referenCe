#ifndef PAGEMISSING_H
#define PAGEMISSING_H

#include <referencepage.h>

class PageMissing : public ReferencePage
{
    Q_OBJECT

public:
    PageMissing();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;
};

#endif // PAGEMISSING_H
