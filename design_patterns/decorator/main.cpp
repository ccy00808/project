#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::cout;

class Food {
public:
    Food() {}
    Food(std::string na) : name(na) {}
    virtual ~Food() {};
    virtual void Eating() = 0;
    virtual int Operato(Food *) {}
private:
    std::string name;
};

class Rice : public Food {
public:
    Rice(string name) : Food(name) {}
    virtual ~Rice() {cout << "rice is delete\n";}
    virtual void Eating() {
        cout << "is Rice\n";
    }
};

class Wheat : public Food {
public:
    Wheat(string name) : Food(name) {}
    virtual ~Wheat() {cout << "wheat is delete\n";}
    virtual void Eating() {
        cout << "is Wheat\n";
    }

};

class Decorator : public Food {
public:
    Decorator(Food* f) : food(f) {}
    virtual ~Decorator() {delete food;}
    virtual void Eating();
    virtual int Operato(Food *f);
private:
    Food* food;
};

void Decorator::Eating() {
    food->Eating();
}

int Decorator::Operato(Food *f) {
    delete food;
    food = f;
    return 0;
}

class EggDecorator : public Decorator {
public:
    EggDecorator(Food* f, double nums) : Decorator(f), eggNums(nums) {}
    virtual ~EggDecorator() {cout << "eggDecorater is delete\n";}
    virtual void Eating() {
        cout << "include egg nums " << eggNums << " ";
        Decorator::Eating();
    }

private:
    double eggNums;
};

class Vegetables : public Decorator {
public:
    Vegetables( Food *f, string veg) : Decorator(f), name(veg) {}
    virtual ~Vegetables() {cout << name << "delete\n";}
    virtual void Eating() {
        cout << "vegetables is " << name << " ";
        Decorator::Eating();
    }

private:
    string name;

};


int main()
{

    Rice *ri = new Rice("rice");

    EggDecorator *egg = new EggDecorator(ri, 5);

    egg->Eating();

}