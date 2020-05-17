#include <gtest/gtest.h>
#include <iostream>
#include "hello.h"

class TestFunc : public ::testing::Test {

public:

};

TEST_F(TestFunc, test1)
{
    func();
    int a = 100;
    ASSERT_EQ(100, a);
    std::cout << "chenchuanying\n";
}