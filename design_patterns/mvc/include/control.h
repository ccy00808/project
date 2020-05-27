#ifndef CONTROL_H_
#define CONTROL_H_
#include "student.h"
#include "view.h"

class Control {
public:
    Control(Student st, View v) : stu(st), vi(v) {}
    Control() {}
    ~Control() {}
    void UpdateStInfo(std::string name, int score = 100);
    void UpdateView();

private:
    Student stu;
    View vi;
};

#endif