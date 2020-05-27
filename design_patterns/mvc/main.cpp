#include "view.h"
#include "control.h"
#include "student.h"

int main()
{
    View vi;
    Student st("chenchuanying", 1000);
    Control con(st, vi);
    con.UpdateStInfo("123");
    con.UpdateView();
}