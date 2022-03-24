#include "lightarmor.h"

LightArmor::LightArmor(std::string n, int v, int def):
    Armor(n, v, def) {}

int LightArmor::calcDefence(int dex) const {
    return getDefence() + dex;
}

std::string LightArmor::getInfo() const {
    std::string s = "(Light Armor)\n";
    return s.append(Armor::getInfo());
}

bool LightArmor::operator==(const Item &i) const {
    if(!(dynamic_cast<const LightArmor*>((&i)))) return false;
    return Armor::operator==(i);
}


LightArmor *LightArmor::clone() const {
    return new LightArmor(getName(), getValue(), getDefence());
}
