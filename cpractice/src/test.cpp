#include "test.h"
#include <iostream>

/******************************************************
 * Author     :ccy88
 * Date       :2020.05.29
 * Description:指针的引用避免传递二维指针，比如封装释放指针的
 *             函数入参
 * ****************************************************/
void TestPoint(int *&p1, int *&p2)
{
    p1 = p2;
}
//高边指针的值能否被带出
void TestPointQuote()
{
    int *p1 = new int(99);
    int *p2 = new int(11);
    std::cout << p1 << " " << p2 << std::endl;
    TestPoint(p1, p2);
    std::cout << p1 << " " << p2 << std::endl;
}


/******************************************************
 * Author     :ccy88
 * Date       :2020.05.29
 * Description:指针的引用避免传递二维指针，比如封装释放指针的
 *             函数入参
 * ****************************************************/