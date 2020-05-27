#ifndef CHAR_CLASS_H_
#define CHAR_CLASS_H_
#include "theme.h"
#include <string>

class CharVal {
public:
    CharVal() = default;
    virtual ~CharVal() = default;
    virtual void DisplayScreen() = 0;
    void SetDisplayType(CharType::CharTypePtr type)
    {
        charType = type;
    }

protected:
   CharType::CharTypePtr charType;
};

class CharValPerson final : public CharVal {
public:
    CharValPerson(std::string na) : name(na) {}
    virtual void DisplayScreen();
    virtual ~CharValPerson() {}

private:
    std::string name;
};

class CharValTeacher : public CharVal {
public:
    CharValTeacher(std::string na) : name(na) {}
    virtual void DisplayScreen() override final;
    virtual ~CharValTeacher() {}

private:
    std::string name;
};

#endif