#include "student.h"

Student::Student(std::string n, int s) : name(n), score(s) {}

void Student::SetName(std::string n) {
    name = n;
}

std::string Student::GetName() {
    return name;
}

void Student::SetScore(int sc) {
    score = sc;
}

int Student::GetScore() {
    return score;
}