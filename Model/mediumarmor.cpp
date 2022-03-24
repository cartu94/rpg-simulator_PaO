#include "mediumarmor.h"

MediumArmor::MediumArmor(std::string n, int v, int def, int maxDex):
    Armor(n, v, def), maxDexterity(maxDex) {}

int MediumArmor::calcDefence(int dex) const {
    if(dex >= maxDexterity) return getDefence() + maxDexterity;
    else return getDefence() + dex;
}

int MediumArmor::getMaxDexterity() const {
    return maxDexterity;
}

std::string MediumArmor::getInfo() const {
    std::string s = "(Medium Armor)\n";
    return s.append(Armor::getInfo().append("\nMax Dexterity: " + std::to_string(getMaxDexterity())));
}

bool MediumArmor::operator==(const Item &i) const {
    if(!(dynamic_cast<const MediumArmor*>((&i)))) return false;
    return Armor::operator==(i) && maxDexterity==dynamic_cast<const MediumArmor*>(&i)->getMaxDexterity();
}

MediumArmor* MediumArmor::clone() const {
    return new MediumArmor(getName(), getValue(), getDefence(), getMaxDexterity());
}
