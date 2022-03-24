#ifndef CHARACTER_H
#define CHARACTER_H
#include "dlist.h"
#include "deepptr.h"
#include "item.h"
#include "armor.h"
#include "lightarmor.h"
#include "mediumarmor.h"
#include "heavyarmor.h"
#include "weapon.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "mediumweapon.h"
#include "shield.h"

class Character
{
public:
    Character();

    int getMoney() const;
    void addMoney(int value);

    int getStatPoints() const;
    int getStrength() const;
    int getDexterity() const;
    int getHealth() const;

    void setStatPoints(int value);
    void setStrength(int value);
    void setDexterity(int value);
    void setHealth(int value);

    int getHit(int dmg);

    int calcDamage() const;
    int calcDefence() const;

    int addEquip(Item& item);
    bool removeEquip(Item& item);

    template <class T>
    int countTypeOf() const;

    DList<DeepPtr<Item>> *getEquip() const;

private:
    DList<DeepPtr<Item>> *equip;
    int money;
    int statPoints;
    int strength;
    int dexterity;
    int health;
};

#endif // CHARACTER_H
