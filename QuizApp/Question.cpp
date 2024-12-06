#include "Question.h"
#include <iostream>
using namespace std;

Question::Question(string text, vector<string> opts, int answer)
    : questionText(text), options(opts), correctAnswer(answer) {}

void Question::display() const {
    cout << questionText << endl;
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

bool Question::checkAnswer(int answer) const {
    return (answer - 1) == correctAnswer;
}

