#ifndef FLYWEIGHTPXY_H_
#define FLYWEIGHTPXY_H_
#include <unordered_map>
#include "charclass.h"
#include "theme.h"

class CharTypeFactory {
    using charTypeMaps = std::unordered_map<int, CharType::CharTypePtr>;
public:
    static CharTypeFactory* GetInstance();
    CharType::CharTypePtr GetCharType(int type);
private:
    CharTypeFactory() {};
    charTypeMaps typeMaps;
    static CharTypeFactory* instance;

};

#endif