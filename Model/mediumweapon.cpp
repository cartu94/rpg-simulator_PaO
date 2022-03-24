#include "mediumweapon.h"

MediumWeapon::MediumWeapon(std::string n, int v, int dmg):
    Weapon(n, v, dmg){}

MediumWeapon *MediumWeapon::clone() const {
    return new MediumWeapon(getName(), getValue(), getDamage());
}

int MediumWeapon::calcDamage(int str) const {
    return getDamage() + str;
}

std::string MediumWeapon::getInfo() const {
    std::string s = "(Medium Weapon)\n";
    return s.append(Weapon::getInfo());
}

bool MediumWeapon::operator==(const Item &i) const {
    if(!(dynamic_cast<const MediumWeapon*>((&i)))) return false;
    return Weapon::operator==(i);
}
