#ifndef LIGHTWEAPON_H
#define LIGHTWEAPON_H
#include "weapon.h"

class LightWeapon : public Weapon
{
public:
    LightWeapon(std::string n, int v, int dmg, int reqDex);
    LightWeapon* clone() const;
    int calcDamage(int dex) const;
    int getRequiredDexterity() const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;

private:
    int requiredDexterity;
};

#endif // LIGHTWEAPON_H
