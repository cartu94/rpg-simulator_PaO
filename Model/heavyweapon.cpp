#include "heavyweapon.h"



HeavyWeapon::HeavyWeapon(std::string n, int v, int dmg, int reqStr):
    Weapon(n, v, dmg), requiredStrength(reqStr) {}

HeavyWeapon *HeavyWeapon::clone() const {
    return new HeavyWeapon(getName(), getValue(), getDamage(), getRequiredStrength());
}

int HeavyWeapon::calcDamage(int str) const {
    if(str >= requiredStrength) return getDamage() + str*1.5;
    else return (getDamage() >= requiredStrength - str) ? getDamage() - (requiredStrength - str) : 0;
}

int HeavyWeapon::getRequiredStrength() const {
    return requiredStrength;
}

std::string HeavyWeapon::getInfo() const {
    std::string s = "(Heavy Weapon)\n";
    return s.append(Weapon::getInfo().append("\nRequired Strength: " + std::to_string(getRequiredStrength())));
}

bool HeavyWeapon::operator==(const Item &i) const {
    if(!(dynamic_cast<const HeavyWeapon*>((&i)))) return false;
    return Weapon::operator==(i) && requiredStrength==dynamic_cast<const HeavyWeapon*>(&i)->getRequiredStrength();
}
