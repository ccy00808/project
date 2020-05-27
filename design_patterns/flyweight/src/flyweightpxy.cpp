#include "flyweightpxy.h"
#include <memory>

CharTypeFactory* CharTypeFactory::instance = nullptr;

CharTypeFactory* CharTypeFactory::GetInstance()
{
    if (instance == nullptr) {
        instance = new CharTypeFactory();
    }

    return instance;
}

CharType::CharTypePtr CharTypeFactory::GetCharType(int type)
{
    if (typeMaps.find(type) != typeMaps.end()) {
        return typeMaps[type];
    }

    switch (type) {
    case TYPE_BOLK:
        typeMaps[type] = std::make_shared<BolkType>();
        break;

    case TYPE_ITALIC:
        typeMaps[type] = std::make_shared<ItalicType>();
        break;

    case TYPE_SIMPLE_FORM:
        typeMaps[type] = std::make_shared<SimpleType>();
        break;
    }

    return typeMaps[type];
}



