/*
* ��������ʾdynamic_cast
*/

class Entity {
public:
    virtual void PrintName() {}
};

class Player : public Entity {};

class Enemy : public Entity {};

//dynamic_cast�����ڸ���������ת��
int main() {
    //playerӵ����������:Entity��Player
    Player* player = new Player();
    Entity* enemy = new Enemy();
    Entity* entity1 = player; //��ʽת��

    //dynamic_castֻ�����ڶ�̬������(��Ҫ�麯����)
    Player* p0 = dynamic_cast<Player *>(enemy); //NULL(ת�����ɹ�)
    if (p0) {}
    Player* p1 = dynamic_cast<Player*>(entity1); //ת���ɹ�

    //dynamic_cast�洢������ʱ������Ϣ(runtime information��RTTI)
    return 0;
}