#include "armor.h"

Armor::Armor(std::string n, int v, int def): Item(n, v), defence(def){}

std::string Armor::getInfo() const {
    return Item::getInfo().append("\nDefence: " + std::to_string(getDefence()));
}

bool Armor::operator==(const Item &i) const {
    if(!(dynamic_cast<const Armor*>((&i)))) return false;
    return Item::operator==(i) && defence==dynamic_cast<const Armor*>(&i)->getDefence();
}

int Armor::getDefence() const {
    return defence;
}
