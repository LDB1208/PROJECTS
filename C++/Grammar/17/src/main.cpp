#include <string>

/*
 * 本程序演示可见性
 */

struct Entity {
    int x, y; //默认公开

    Entity() {
        x = y = 0;
        name = "name";
    }

private:
    std::string name; //仅有友元(friend)和Entity能访问

protected:
    int a; //可被子类调用
};

class Player : public Entity {
public:
    Player() {
        a = 3;
    }
};
int main() {
    Player p;
    p.x = 0;
    //p.name = "0";
    return 0;
}