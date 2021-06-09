#ifndef QUIZPAGE_H
#define QUIZPAGE_H

#include <QDialog>
#include <QEventLoop>
#include <QMessageBox>

#include "referencepage.h"

namespace Ui { class QuizPage; }

class QuizPage : public QDialog
{
    Q_OBJECT

public:
    std::vector<std::vector<dictionary *> *> *allDictionaries;

    explicit QuizPage(QWidget *parent = nullptr);
    ~QuizPage();
    void show();

private:
    QEventLoop loop;
    Ui::QuizPage *ui;
    int correctButton;
    std::vector<int> *chosenAnswers;
    int streak;

    void generateQuiz();
    void generateWrongAnswers(int correctI, QPushButton *button);
    void closeEvent(QCloseEvent *event);
    void proceed(int pressedButton);

private slots:
    void pressedButton1();
    void pressedButton2();
    void pressedButton3();
    void pressedButton4();
};

#endif // QUIZPAGE_H
