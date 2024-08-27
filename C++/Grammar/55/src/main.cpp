/*
* 本程序演示dynamic_cast
*/

class Entity {
public:
    virtual void PrintName() {}
};

class Player : public Entity {};

class Enemy : public Entity {};

//dynamic_cast可用于父类和子类间转换
int main() {
    //player拥有两种类型:Entity和Player
    Player* player = new Player();
    Entity* enemy = new Enemy();
    Entity* entity1 = player; //隐式转换

    //dynamic_cast只适用于多态类类型(需要虚函数表)
    Player* p0 = dynamic_cast<Player *>(enemy); //NULL(转换不成功)
    if (p0) {}
    Player* p1 = dynamic_cast<Player *>(entity1); //转换成功
 
    //dynamic_cast存储了运行时类型信息(runtime information即RTTI)
    return 0;
}