#include "charclass.h"
#include "flyweightpxy.h"
#include "theme.h"
#include <string>

int main()
{
    CharVal *val = new CharValPerson("chenchuanying");
    CharTypeFactory* factory = CharTypeFactory::GetInstance();

    val->SetDisplayType(factory->GetCharType(TYPE_BOLK));
    val->DisplayScreen();
    delete val;
    delete factory;
}