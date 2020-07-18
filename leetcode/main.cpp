#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <list>
#include <algorithm>

class Solution {
public:
    int calculate(std::string s) {
        InitTables();
        GetValues(s);
        return CaculateResult();
    }

    void InitTables()
    {
        iTables.insert(std::pair<char, int>('-', 0));
        iTables.insert(std::pair<char, int>('+', 0));
        iTables.insert(std::pair<char, int>('*', 1));
        iTables.insert(std::pair<char, int>('/', 1));
    }

    void GetValues(std::string s)
    {
        std::string tmpS(s);
        for (auto iter = tmpS.begin(); iter != tmpS.end(); ++iter) {
            if (*iter == ' ') {
                continue;
            }
            if (isdigit(*iter)) {
                values.push_back(*iter);
                std::cout << "values push " << values.back() << std::endl;
            } else if (isalpha(*iter)) {
                while (tables.size() > 0) {
                    if (tables.top() <= *iter) {
                        values.push_back(tables.top());
                        tables.pop();
                        std::cout << "values push " << values.back() << std::endl;
                    } else {
                        tables.push(*iter);
                        break;
                    }
                }
            }
        }
        while (tables.size() > 0) {
            values.push_back(tables.top());
            tables.pop();
        }
        
    }

    int CaculateResult()
    {
        int result = 0;
        for (auto iter = values.begin(); iter != values.end(); ++iter) {
            if (isdigit(*iter)) {
                tables.push(*iter);
            } else {
                int a = atoi(&(tables.top()));
                tables.pop();
                int b = atoi(&(tables.top()));
                tables.pop();
                result += GetTmpValue(a, b, *iter);
            }
        }
        return result;
    }

    int GetTmpValue(int a, int b, char c)
    {
        if (c == '-') {
            return b - a;
        } else if (c == '+') {
            return a + b;
        } else if (c == '*') {
            return a * b;
        } else {
            return b / a;
        }
     }

private:
    std::map<char, int> iTables;
    std::list<char> values;
    std::stack<char> tables;
};



#include <iostream>

using std::cin;
using std::cout;

void SwapValue(int& a, int& b)
{
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

bool CaculateResult(int n)
{
    int min = 0;
    int max = 0;
    cin >> min;
    while(n-- > 1) {
        cin >> max;
        SwapValue(min, max);

        while(min != 0) {
            int ret = max % min;
            max = min;
            min = ret;
        }

        if (max == 1) {
            return true;
        }

        min = max;
    }
    return false;
}

int main()
{
    int n = 0;
    bool resultFlag = false;
    while(std::cin >> n) {
        if (n <1 || n > 10000) {
            return 0;
        }

        if (CaculateResult(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}

#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::string;

bool CaculateSort(string &s, string &t, int *marks, int markslen)
{
    if (s.size() > t.size()) {
        return false;
    }

    if (s.size() == t.size() && s == t) {
        return true;
    }

    auto startS = s.begin();
    auto startT = t.begin();

    while(startS != s.end()) {
        while (startT != t.end() && *startT != *startS) {
            ++startT;
        }

        if (startT == t.end()) {
            return false;
        }

        marks[startT - s.begin()] = 1;
        startT++;
        startS++;
    }

    return true;
}

bool CheckCharInfo(string& t, string& p, int* marks)
{
    std::map<char, int> tmaps;
    std::map<char, int> pmaps;
    for (int i = 0; i < t.size(); ++i) {
        if (marks[i] != 0) continue;
        tmaps[t[i]]++;
    }

    for (int i = 0; i < p.size(); ++i) {
        pmaps[p[i]]++;
    }

    for (auto iter = tmaps.begin(); iter != tmaps.end(); ++iter) {
        if (!(pmaps.find(iter->first) != pmaps.end() && pmaps[iter->first] == iter->second)) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 0;
    string s, t, p;
    cin >> n;
    int marks[101] = {0};
    if (n < 1 || n > 100) {
        return 0;
    }

    while (n-- > 0) {
        cin >> s >> t >>p;
        if(!CaculateSort(s, t, marks, 101)) {
            std::cout << "NO\n";
            continue;
        }

        if (!CheckCharInfo(t, p, marks)) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
    }
}

int memcpy(void* dest, unsigned int dlen, void* src, unsigned int slen)
{
    if (dest == nullptr || src == nullptr || dlen <= slen) {
        return -1;
    }

    if ((dest > src && src + slen >= dest) || (dest < src && dest + dlen > src) {
        return -1;
    }

    char* destT = static_cast<char*>dest;
    char* srcT = static_cast<char*>src;
    int tmpS = 0;
    while(slen--) {
        *destT++ = *srcT++;
    }
    return 0;
}