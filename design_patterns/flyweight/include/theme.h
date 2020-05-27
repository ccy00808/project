#ifndef THEME_H_
#define THEME_H_
#include <memory>

typedef enum {
    TYPE_BOLK,
    TYPE_ITALIC,
    TYPE_SIMPLE_FORM
} EnCharType;

class CharType {
public:
    using CharTypePtr = std::shared_ptr<CharType>;
public:
    virtual void DisplayView() = 0;
};

class SimpleType final : public CharType {
public:
    virtual void DisplayView() override;
};

class BolkType final : public CharType {
public:
    virtual void DisplayView() override final;
};

class ItalicType : public CharType {
public:
    void DisplayView() final;
};


#endif