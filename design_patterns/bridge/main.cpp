#include <iostream>
#include <memory>

class Game {
public:
    Game() {}
    virtual ~Game() {}
    virtual void RunGame() = 0;
};

class Telephone {
public:
    Telephone(Game *g) : game(g) {}
    virtual void RunGame() = 0;
    virtual ~Telephone() {std::cout << "delete T\n"; delete game;};

protected:
    Game *game;

};

class HWTelephone : public Telephone {
public:
    HWTelephone(Game *g, int b) : Telephone(g), a(b){}
    virtual void RunGame() {
        std::cout << "HW telephone\n";
        game->RunGame();
    }

    virtual ~HWTelephone() {}

private:
    int a;
};


class XMTelephone : public Telephone {
public:
    XMTelephone(Game *g, int b) : Telephone(g), a(b) {}
    virtual void RunGame() {
        std::cout << "x m telephone\n";
        game->RunGame();
    }

    virtual ~XMTelephone() {}

private:
    int a;
};

class WZRYGame : public Game {
public:
    WZRYGame(){}
    virtual ~WZRYGame() {std::cout << "wzry\n";}
    virtual void RunGame() {
        std::cout << "w z r y run\n";
    }
};

class DDZGame : public Game {
public:
    DDZGame() {};
    virtual ~DDZGame() {std::cout << "ddz\n";}
    virtual void RunGame() {
        std::cout << "d d z run\n";
    }
};

int main()
{
    std::shared_ptr<Telephone> tele = std::make_shared<HWTelephone>(new WZRYGame(), 1);
    tele->RunGame();
}
