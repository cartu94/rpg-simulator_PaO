#include "shield.h"

Shield::Shield(std::string n, int v, int def):
    Armor(n, v, def) {}

int Shield::calcDefence(int dex) const {
    return getDefence();
}

Shield* Shield::clone() const {
    return new Shield(getName(), getValue(), getDefence());
}

std::string Shield::getInfo() const {
    std::string s = "(Shield)\n";
    return s.append(Armor::getInfo());
}

bool Shield::operator==(const Item &i) const {
    if(!(dynamic_cast<const Shield*>((&i)))) return false;
    return Armor::operator==(i);
}
