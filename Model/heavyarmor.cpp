#include "heavyarmor.h"

HeavyArmor::HeavyArmor(std::string n, int v, int def, int reqStr):
    Armor(n, v, def), requiredStrength(reqStr) {}

int HeavyArmor::calcDefence(int str) const {
    if(str >= requiredStrength) return getDefence();
    else return (getDefence() >= requiredStrength - str) ? getDefence() - (requiredStrength - str) : 0;
}

HeavyArmor *HeavyArmor::clone() const {
    return new HeavyArmor(getName(), getValue(), getDefence(), getRequiredStrength());
}

int HeavyArmor::getRequiredStrength() const {
    return requiredStrength;
}

std::string HeavyArmor::getInfo() const {
    std::string s = "(Heavy Armor)\n";
    return s.append(Armor::getInfo().append("\nRequired Strength: " + std::to_string(getRequiredStrength())));
}

bool HeavyArmor::operator==(const Item &i) const {
    if(!(dynamic_cast<const HeavyArmor*>((&i)))) return false;
    return Armor::operator==(i) && requiredStrength==dynamic_cast<const HeavyArmor*>(&i)->getRequiredStrength();
}
