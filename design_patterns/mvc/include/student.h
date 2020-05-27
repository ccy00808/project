#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

class Student {
public:
    Student(){}
    Student(std::string n, int s);
    ~Student() {}

    void SetName(std::string n);
    std::string GetName();
    void SetScore(int sc);
    int GetScore();

private:
    std::string name;
    int score;
};

#endif