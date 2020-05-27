#include "control.h"

void Control::UpdateStInfo(std::string name, int score) {
    stu.SetName(name);
    stu.SetScore(score);
}

void Control::UpdateView() {
    vi.PrintStudentInfo(stu.GetName(), stu.GetScore());
}