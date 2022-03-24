#include "lightweapon.h"

LightWeapon::LightWeapon(std::string n, int v, int dmg, int reqDex):
    Weapon(n, v, dmg), requiredDexterity(reqDex) {}

LightWeapon *LightWeapon::clone() const {
    return new LightWeapon(getName(), getValue(), getDamage(), getRequiredDexterity());
}

int LightWeapon::calcDamage(int dex) const {
    if(dex >= requiredDexterity) return getDamage() + 0.75*dex;
    else return (getDamage() >= requiredDexterity - dex) ? getDamage() - (requiredDexterity - dex) : 0;
}

int LightWeapon::getRequiredDexterity() const {
    return requiredDexterity;
}

std::string LightWeapon::getInfo() const {
    std::string s = "(LightWeapon)\n";
    return s.append(Weapon::getInfo().append("\nRequired Dexterity: " + std::to_string(getRequiredDexterity())));
}

bool LightWeapon::operator==(const Item &i) const {
    if(!(dynamic_cast<const LightWeapon*>((&i)))) return false;
    return Weapon::operator==(i) && requiredDexterity==dynamic_cast<const LightWeapon*>(&i)->getRequiredDexterity();
}
