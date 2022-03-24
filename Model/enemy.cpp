#include "enemy.h"


Enemy::Enemy(std::string n, int hp, int dmg, int def, int spd, int val):
    name(n), health(hp), damage(dmg), defence(def), speed(spd), value(val) {}

int Enemy::getHit(int dmg) {
    int damage = dmg - calcDefence() > 0 ? dmg - calcDefence() : 0;
    health -= damage;
    return damage;
}

std::string Enemy::getName() const { return name; }

int Enemy::getValue() const { return value; }
int Enemy::getHealth() const { return health; }
int Enemy::calcDamage() const { return damage; }
int Enemy::calcDefence() const { return defence; }
int Enemy::getSpeed() const { return speed; }

std::string Enemy::getInfo() const {
    std::string s = "";
    return s.append("-" + getName() + "-").append("\nHealth: " + std::to_string(getHealth())).append("\nDamage: " + std::to_string(calcDamage())).append("\nDefence: " + std::to_string(calcDefence())).append("\nSpeed: " + std::to_string(getSpeed()));
}
