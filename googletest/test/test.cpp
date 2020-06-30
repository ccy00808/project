#include <iostream>
#include <gtest/gtest.h>
#include <mockcpp/mockcpp.h>
#include <mockcpp/mokc.h>
#include <mockcpp/MockObject.h>
#include <mockcpp/MockObjectHelper.h>

class MyTest : public ::testing::Test {
public:
    virtual void SetUp() {
        std::cout << "setUp\n";
    }

    virtual void TearDown()
    {
        std::cout << "tear down\n";
    }

};

class MyClass {
public:
    virtual ~MyClass() {}
    virtual int TestA()
    {
        std::cout << "my class \n";
        return 100;
    }
};

int TestA()
{
    std::cout << "test A\n";
    return 1;
}

int TestB()
{
    std::cout << "test B\n";
    return 2;
}

int TestC()
{
    return 1000;
}

TEST_F(MyTest, func1)
{
    std::cout << "test case 1\n";
    MOCKER(TestA)
    .stubs()
    .will(invoke(TestB));
    TestA();

    std::cout << "*****************\n";

    MockObject<MyClass> mock;
    MOCK_METHOD(mock, TestA)
        .stubs()
        .will(invoke(TestC));
    
    std::cout << mock->TestA() << std::endl;
}