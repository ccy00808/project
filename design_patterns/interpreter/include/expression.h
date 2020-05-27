#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include "context.h"

class Expression {
public:
    Expression() = default;
    virtual ~Expression() {}
    virtual bool Evaluate(Context *context) = 0;
};

class TerminalExpression : public Expression {
public:
    TerminalExpression(std::string ex) : exp(ex) {}
    virtual ~TerminalExpression() {}
    virtual bool Evaluate(Context *context) override;

private:
    std::string exp;
};

class AndExp : public Expression {
public:
    AndExp(Expression *e1, Expression *e2) : exp1(e1), exp2(e2) {}
    virtual ~AndExp() {delete exp1; delete exp2;}
    virtual bool Evaluate(Context *context) override;

private:
    Expression *exp1;
    Expression *exp2;
};

class OrExp : public Expression {
public:
    OrExp(Expression *e1, Expression *e2) : exp1(e1), exp2(e2) {}
    virtual ~OrExp() {delete exp1; delete exp2;}
    virtual bool Evaluate(Context *context) override;

private:
    Expression *exp1;
    Expression *exp2;
};

class ContactExp : public Expression {
public:
    ContactExp(bool fl) : flag(fl) {}
    virtual ~ContactExp() {}
    virtual bool Evaluate(Context *context) override;
private:
    bool flag;
};

#endif