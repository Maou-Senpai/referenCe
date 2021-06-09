// PURPOSE:
// This cpp file is for the Quiz Page which tests the user based on the
// the dictionaries
//

//Header Files
#include "quizpage.h"
#include "ui_quizpage.h"
#include "pagelibstdio.h"
#include "pagelibstdlib.h"
#include "pagelibstring.h"
#include "pagelibtime.h"
#include "pagelibmath.h"

QuizPage::QuizPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizPage)
{
    ui->setupUi(this);

    // Random Question Generator
    ReferencePage *tempPage;
    allDictionaries = new std::vector<std::vector<dictionary *> *>;
    tempPage = new PageLibStdio;
    tempPage->getDictionaries(allDictionaries);
    tempPage = new PageLibStdlib;
    tempPage->getDictionaries(allDictionaries);
    tempPage = new PageLibString;
    tempPage->getDictionaries(allDictionaries);
    tempPage = new PageLibTime;
    tempPage->getDictionaries(allDictionaries);
    tempPage = new PageLibMath;
    tempPage->getDictionaries(allDictionaries);

    connect(ui->button1, &QPushButton::pressed, this, &QuizPage::pressedButton1);
    connect(ui->button2, &QPushButton::pressed, this, &QuizPage::pressedButton2);
    connect(ui->button3, &QPushButton::pressed, this, &QuizPage::pressedButton3);
    connect(ui->button4, &QPushButton::pressed, this, &QuizPage::pressedButton4);

    streak = 0;
    srand(time(NULL));
    generateQuiz();
}

QuizPage::~QuizPage()
{
    delete ui;
}

void QuizPage::show()
{
    this->showMaximized();
    loop.exec();
}

void QuizPage::generateQuiz()
{
    int correctI = rand() % allDictionaries->size();
    int correctJ = (rand() % (allDictionaries->at(correctI)->size() - 1)) + 1;
    ui->label->setText(allDictionaries->at(correctI)->at(correctJ)->info);

    correctButton = rand() % 4;
    if (correctButton == 0) ui->button1->setText(allDictionaries->at(correctI)->at(correctJ)->item);
    else if (correctButton == 1) ui->button2->setText(allDictionaries->at(correctI)->at(correctJ)->item);
    else if (correctButton == 2) ui->button3->setText(allDictionaries->at(correctI)->at(correctJ)->item);
    else if (correctButton == 3) ui->button4->setText(allDictionaries->at(correctI)->at(correctJ)->item);

    chosenAnswers = new std::vector<int>;
    chosenAnswers->push_back(correctJ);
    if (correctButton != 0) {
        generateWrongAnswers(correctI, ui->button1);
    }
    if (correctButton != 1) {
        generateWrongAnswers(correctI, ui->button2);
    }
    if (correctButton != 2) {
        generateWrongAnswers(correctI, ui->button3);
    }
    if (correctButton != 3) {
        generateWrongAnswers(correctI, ui->button4);
    }
}

void QuizPage::generateWrongAnswers(int correctI, QPushButton *button)
{
    int randomJ;
    do {
        randomJ = (rand() % (allDictionaries->at(correctI)->size() - 1)) + 1;
    } while (std::find(chosenAnswers->begin(), chosenAnswers->end(), randomJ) != chosenAnswers->end());
    button->setText(allDictionaries->at(correctI)->at(randomJ)->item);
}

void QuizPage::closeEvent(QCloseEvent *) {
    loop.quit();
}

void QuizPage::proceed(int pressedButton)
{
    QMessageBox msg;
    std::string streakText = "Streak: ";

    if (correctButton != pressedButton) {
        std::string correctAnswer = "Incorrect\nCorrect Answer: ";
        if (correctButton == 0) correctAnswer += ui->button1->text().toUtf8().data();
        else if (correctButton == 1) correctAnswer += ui->button2->text().toUtf8().data();
        else if (correctButton == 2) correctAnswer += ui->button3->text().toUtf8().data();
        else if (correctButton == 3) correctAnswer += ui->button4->text().toUtf8().data();
        msg.setText(correctAnswer.c_str());
        streak = 0;
    } else {
        msg.setText("Correct");
        streak++;
    }

    streakText += std::to_string(streak);
    ui->streak->setText(streakText.c_str());

    msg.exec();
    generateQuiz();
}

void QuizPage::pressedButton1()
{
    proceed(0);
}

void QuizPage::pressedButton2()
{
    proceed(1);
}

void QuizPage::pressedButton3()
{
    proceed(2);
}

void QuizPage::pressedButton4()
{
    proceed(3);
}
