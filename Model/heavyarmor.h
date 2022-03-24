#ifndef HEAVYARMOR_H
#define HEAVYARMOR_H
#include "armor.h"

class HeavyArmor : public Armor
{
public:
    HeavyArmor(std::string n, int v, int def, int reqStr);
    int calcDefence(int str) const;
    HeavyArmor* clone() const;
    int getRequiredStrength() const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;
private:
    int requiredStrength;
};

#endif // HEAVYARMOR_H
