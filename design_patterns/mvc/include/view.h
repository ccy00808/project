#ifndef VIEW_H_
#define VIEW_H_
#include <string>

class View {
public:
    View() {}
    ~View() {}
    void PrintStudentInfo(std::string name, int score);
};

#endif