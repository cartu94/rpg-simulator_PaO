#include "weapon.h"

Weapon::Weapon(std::string n, int v, int dmg): Item(n, v), damage(dmg) {}

std::string Weapon::getInfo() const {
    return Item::getInfo().append("\nDamage: " + std::to_string(getDamage()));
}

bool Weapon::operator==(const Item &i) const {
    if(!(dynamic_cast<const Weapon*>((&i)))) return false;
    return Item::operator==(i) && damage==dynamic_cast<const Weapon*>(&i)->getDamage();
}

int Weapon::getDamage() const {
    return damage;
}
