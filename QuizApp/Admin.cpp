#include "Admin.h"
#include <iostream>
using namespace std;
#include "Question.h"
Admin::Admin(Quiz& quiz) : quiz(quiz) {}

void Admin::addQuestion() {
    Question q;
    cout << "Enter the question text: ";
    cin.ignore();
    getline(cin, q.questionText);

    cout << "Enter option A: ";
    getline(cin, q.options[0]);
    cout << "Enter option B: ";
    getline(cin, q.options[1]);
    cout << "Enter option C: ";
    getline(cin, q.options[2]);
    cout << "Enter option D: ";
    getline(cin, q.options[3]);

    cout << "Enter the correct answer (A, B, C, D): ";
    cin >> q.correctAnswer;
    q.correctAnswer = toupper(q.correctAnswer);

    quiz.addQuestion(q);
}

void Admin::removeQuestion() {
    quiz.displayQuestions();
    cout << "Enter the question number to remove: ";
    int index;
    cin >> index;
    quiz.removeQuestion(index - 1); // Convert to zero-based index
}
