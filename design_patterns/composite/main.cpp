#include <iostream>
#include <memory>
#include <list>
#include <string>

class Composite {
public:
    Composite(std::string name) {}
    virtual ~Composite() {}
    virtual double GetPower() = 0;
    virtual double GetPrice() = 0;
    virtual void Add(Composite *c) {std::cout << "deny current add operator\n";}
    virtual void Rmv(std::string name) {std::cout << "deny current rmv operator\n";}
    virtual Composite* GetComposite(std::string name) = 0;
    std::string GetName() {
        return name;
    }
private:
    std::string name;
};

class ComposeElements : public Composite {
public:
    virtual double GetPower() {
        double total = 0;
        for (auto iter = composites.begin(); iter != composites.end(); ++iter) {
            total += (*iter)->GetPower();
        }

        return total;
    }

    virtual double GetPrice();
    virtual void Add(Composite *c);
    virtual void Rmv(Composite *c);
    virtual Composite* GetComposite(std::string name);

    virtual ~ComposeElements() {
        for (auto iter : composites) {
            delete iter;
        }
    }
private:
    std::list<Composite*> composites;
};

double ComposeElements::GetPrice() {
    double price = 0;
    for (auto iter = composites.begin(); iter != composites.end(); ++iter) {
        price += (*iter)->GetPrice();
    }

    return price;
}


void ComposeElements::Add(Composite * c) {
    composites.push_back(c);
}

void ComposeElements::Rmv(Composite * c) {
    composites.remove(c);
}


Composite* ComposeElements::GetComposite(std::string name) {
    for(auto iter = composites.begin(); iter != composites.end(); ++iter) {
        if ((*iter)->GetName() == name) {
            return *iter;
        }
    }

    return nullptr;
}

class LeafCompose : public Composite {
public:
    virtual Composite* GetComposite(std::string name) {
        return this;
    }

    virtual double GetPower();
    virtual double GetPrice();


private:
    double power;
    double price;

};

double LeafCompose::GetPower() {
    return power;
}

double LeafCompose::GetPrice() {
    return price;
}

int main()
{
     
}