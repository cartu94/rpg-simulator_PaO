#ifndef HEAVYWEAPON_H
#define HEAVYWEAPON_H
#include "weapon.h"

class HeavyWeapon : public Weapon
{
public:
    HeavyWeapon(std::string n, int v, int dmg, int reqStr);
    HeavyWeapon* clone() const;
    int calcDamage(int str) const;
    int getRequiredStrength() const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;
private:
    int requiredStrength;
};

#endif // HEAVYWEAPON_H
