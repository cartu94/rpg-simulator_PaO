#ifndef MEDIUMWEAPON_H
#define MEDIUMWEAPON_H
#include "weapon.h"

class MediumWeapon: public Weapon
{
public:
    MediumWeapon(std::string n, int v, int dmg);
    MediumWeapon* clone() const;
    int calcDamage(int str) const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;
};

#endif // MEDIUMWEAPON_H
