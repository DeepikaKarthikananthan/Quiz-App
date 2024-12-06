#include <iostream>
#include "Quiz.h"
#include "Admin.h"
#include "Question.h"
using namespace std;

int main() {
    Quiz quiz;
    Admin admin(quiz);

    int choice;
    cout << "=== Quiz Application ===\n";
    cout << "1. Admin Login\n";
    cout << "2. Start Quiz\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n=== Admin Panel ===\n";
        int adminChoice;
        do {
            cout << "1. Add Question\n";
            cout << "2. Remove Question\n";
            cout << "3. Display Questions\n";
            cout << "4. Exit Admin Panel\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
                case 1:
                    admin.addQuestion();
                    break;
                case 2:
                    admin.removeQuestion();
                    break;
                case 3:
                    quiz.displayQuestions();
                    break;
                case 4:
                    cout << "Exiting Admin Panel.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (adminChoice != 4);
    } else if (choice == 2) {
        quiz.startQuiz();
    } else {
        cout << "Invalid choice. Exiting application.\n";
    }

    return 0;
}
