#ifndef MEDIUMARMOR_H
#define MEDIUMARMOR_H
#include "armor.h"

class MediumArmor : public Armor
{
public:
    MediumArmor(std::string n, int v, int def, int maxDex);
    int calcDefence(int dex) const;
    int getMaxDexterity() const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;

    MediumArmor* clone() const;
private:
    int maxDexterity;
};

#endif // MEDIUMARMOR_H
