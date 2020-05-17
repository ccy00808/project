#include <iostream>

#define CHINA_AC_220 220
#define JAPAN_AC_110 110

class AC5 {
public:
    virtual int OutputVal() = 0;
};

class ChinaAC : public AC5 {
public:
    virtual int OutputVal() {
        return output;
    }

private:
    int output = 220;

};

class Japan : public AC5 {
public:
    virtual int OutputVal() {
        return output;
    }

private:
    int output = 110;
};

class AdapterDC5 {
public:
    virtual bool IsSupport(AC5* ac) = 0;
    virtual int OutputVal(AC5* ac) = 0;
};

class ChinaAdapter : public AdapterDC5 {
public:
    virtual bool IsSupport(AC5 *ac) {
        return CHINA_AC_220 == ac->OutputVal();
    }

    virtual int OutputVal(AC5 *ac) {
        if (IsSupport(ac)) {
            return CHINA_AC_220 / 44;
        }
        return 0;
    }

};

class JapanAdapter : public AdapterDC5 {
public:
    virtual bool IsSupport(AC5 *ac) {
        return JAPAN_AC_110 == ac->OutputVal();
    }

    virtual int OutputVal(AC5 *ac) {
        if (IsSupport(ac)) {
            return JAPAN_AC_110 / 22;
        }

        return 0;
    }
};

int main() {
    ChinaAC ac;
    AdapterDC5 *adapter = new ChinaAdapter();
    std::cout << adapter->OutputVal(&ac) << std::endl;
}