#ifndef LIGHTARMOR_H
#define LIGHTARMOR_H
#include "armor.h"

class LightArmor : public Armor
{
public:
    LightArmor(std::string n, int v, int def);
    int calcDefence(int dex) const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;

    LightArmor* clone() const;
};

#endif // LIGHTARMOR_H
