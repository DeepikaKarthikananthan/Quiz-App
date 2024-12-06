
#include "Quiz.h"

#include <iostream>
#include <thread>
#include <chrono>
#include "Question.h"
using namespace std;

void Quiz::addQuestion(const Question& q) {
    questions.push_back(q);
    cout << "Question added successfully.\n";
}

void Quiz::removeQuestion(int index) {
    if (index < 0 || index >= questions.size()) {
        cout << "Invalid question number.\n";
        return;
    }
    questions.erase(questions.begin() + index);
    cout << "Question removed successfully.\n";
}

void Quiz::displayQuestions() const {
    if (questions.empty()) {
        cout << "No questions available.\n";
        return;
    }
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << i + 1 << ". " << questions[i].questionText << "\n";
        cout << "   A. " << questions[i].options[0] << "\n";
        cout << "   B. " << questions[i].options[1] << "\n";
        cout << "   C. " << questions[i].options[2] << "\n";
        cout << "   D. " << questions[i].options[3] << "\n";
    }
}

void Quiz::startQuiz() {
    if (questions.empty()) {
        cout << "No questions available to start the quiz.\n";
        return;
    }

    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "\nQuestion " << i + 1 << ": " << questions[i].questionText << "\n";
        cout << "   A. " << questions[i].options[0] << "\n";
        cout << "   B. " << questions[i].options[1] << "\n";
        cout << "   C. " << questions[i].options[2] << "\n";
        cout << "   D. " << questions[i].options[3] << "\n";

        // Timer (10 seconds per question)
        cout << "You have 10 seconds to answer...\n";
        char answer;
        auto start = chrono::steady_clock::now();
        cin >> answer;
        auto end = chrono::steady_clock::now();

        if (chrono::duration_cast<chrono::seconds>(end - start).count() > 10) {
            cout << "Time's up! Moving to the next question.\n";
            continue;
        }

        if (toupper(answer) == questions[i].correctAnswer) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong! Correct answer: " << questions[i].correctAnswer << "\n";
        }
    }
    cout << "\nQuiz Over! Your Score: " << score << "/" << questions.size() << "\n";
}
