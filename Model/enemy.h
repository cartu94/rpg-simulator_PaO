#ifndef ENEMY_H
#define ENEMY_H
#include <string>

class Enemy
{
public:
    Enemy(std::string n, int hp, int dmg, int def, int spd, int val);

    int getHit(int dmg);

    std::string getName() const;
    int getValue() const;
    int getHealth() const;
    int calcDamage() const;
    int calcDefence() const;
    int getSpeed() const;

    std::string getInfo() const;

private:
    std::string name;
    int health, damage, defence, speed, value;
};

#endif // ENEMY_H
