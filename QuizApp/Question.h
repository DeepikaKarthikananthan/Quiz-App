
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    int correctAnswer; // Index of the correct option (0-based)

public:
    Question(string text, vector<string> opts, int answer);

    void display() const;
    bool checkAnswer(int answer) const;
};

#endif
