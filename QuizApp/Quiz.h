#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <vector>
using namespace std;

class Quiz {
private:
    vector<Question> questions;

public:
    void addQuestion(const Question& q);
    void removeQuestion(int index);
    void displayQuestions() const;
    void startQuiz();
};

#endif
