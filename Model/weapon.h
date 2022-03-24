#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
public:
    Weapon(std::string n, int v, int dmg);
    virtual int calcDamage(int) const = 0;
    Weapon* clone() const = 0;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;
    int getDamage() const;

private:
    int damage;
};

#endif // WEAPON_H
