#include <vector>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;         //向map中添加元素

        std::cout << m.size() << nums.size() << std::endl;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)     //如果m中存在对应的键值，并且不为i
                return {i , m[target-nums[i]]};
        }
        return {};
    }
    
};

using func_t = int (*)(int a, int b);
typedef int (*func_c)(int a, int b);
//定义别名模板

int TestFunc(int a, int b)
{
    std::cout << a << '\t' << b << std::endl;
    return 1;
}

void TestTypedef(func_t fun)
{
    int a = 100;
    int b = 1000;
    fun(a, b);
}

template<typename T>
struct Ts {
    typedef std::map<std::string, T> maps;
};

template<typename T>
using mapss = std::map<std::string, T>;

mapss<int> names;

int TestName(int, int) {
    return 0;
}

func_c func = TestName;
func_t funt = TestName;

class ClassFunc {
public:
    static void FuncSta(int b) {
        std::cout << b << std::endl;
    }
    void Func(int a) {
        std::cout << "out val is " << a << std::endl;
    }
};

int CompareV(int a, int b)
{
    return a < b ? b : a;
}

int TestFun(std::function<int(int, int)> ftr, int a, int b)
{
    return ftr(a, b);
}

class TestClass {
    public:
    static void TestFunc(int a, int b) {
        std::cout << a << b << " static\n";
    }
};

void TestFunction()
{
    std::function<void(int, int)> ftr = TestFunc;
    ftr(11,12);

    ftr = TestClass::TestFunc;
    ftr(13, 14);

    int resu = TestFun(CompareV, 100, 101);
    std::cout << resu << " result\n";
    int res1= TestFun([](int a, int b) {return a < b ? a : b;}, 100, 101);

    std::cout << res1 << " res1\n";
}

int PrintTwoNums(int a, int b)
{
    std::cout << a << "   " << b << std::endl;
    return -1;
}

void TestBind()
{
    auto ftr = std::bind(PrintTwoNums, std::placeholders::_2, std::placeholders::_1);
    auto ftr2 = std::bind(PrintTwoNums, 2, std::placeholders::_1);
    std::function<int(int, int)> ftr_f = ftr;
    std::function<int(int)> ftr_f1 = ftr2;
    std::function<int(int)> ftr_l = [](int a) {return a;};
    std::cout << ftr(1, 2) << std::endl;
}

int main()
{
    std::vector<int> nums{3,3};
    Solution s;
    vector<int> result = s.twoSum(nums, 6);
    std::cout << result.size() << std::endl;

    int lam1 = 100;
    auto b = [&](){return ++lam1;};

    lam1 = b();
    std::cout << lam1 << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6};
    for (auto &iter : vec) {
        iter++;
    }

    for (auto iter : vec) {
        std::cout << iter << '\t';
    }

    std::cout << std::endl;

    //普通方法引用类成员函数
    void (ClassFunc::*func_ptr)(int) = &ClassFunc::Func;
    ClassFunc fun;
    (fun.*func_ptr)(100);



    TestTypedef(TestFunc);

    TestFunction();

    TestBind();
    return 0;
}