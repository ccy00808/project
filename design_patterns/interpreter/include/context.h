#ifndef CONTEXT_H_
#define CONTEXT_H_
#include <string>
#include <unordered_map>

class Context {
public:
    virtual bool LookUp(std::string name) = 0;
    virtual void Assign(std::string key, bool flag) = 0;
};

class BoolContext : public Context {
public:
    virtual bool LookUp(std::string name) override;
    virtual void Assign(std::string key, bool flag) override;

private:
    std::unordered_map<std::string, bool> cons;

};

#endif