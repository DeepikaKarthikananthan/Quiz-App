#ifndef ADMIN_H
#define ADMIN_H

#include "Quiz.h"

class Admin {
private:
    Quiz& quiz; // Reference to the Quiz object

public:
    Admin(Quiz& quiz);
    void addQuestion();
    void removeQuestion();
};

#endif
