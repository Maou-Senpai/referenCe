#ifndef PAGEOPERATORS_H
#define PAGEOPERATORS_H

#include "referencepage.h"

#include <QLineEdit>
#include <QComboBox>

class PageOperators : public ReferencePage
{
    Q_OBJECT

public:
    std::vector<dictionary *> *arithmeticOperators;
    std::vector<dictionary *> *equalityOperators;
    std::vector<dictionary *> *relationalOperators;

    PageOperators();
    void showPage() override;
    void getDictionaries(std::vector<std::vector<dictionary *> *> *collectiveDict) override;

private:
    QLineEdit *oneLine1;
    QLineEdit *oneLine2;
    QComboBox *oneComboBox;
    QLabel *oneLabel;
    QLineEdit *twoLine1;
    QLineEdit *twoLine2;
    QComboBox *twoComboBox;
    QLabel *twoLabel;
    QLineEdit *threeLine1;
    QLineEdit *threeLine2;
    QComboBox *threeComboBox;
    QLabel *threeLabel;
    void activeSample1();
    void activeSample2();
    void activeSample3();

public slots:
    void changeOneLabel();
    void changeTwoLabel();
    void changeThreeLabel();
};

#endif // PAGEOPERATORS_H
