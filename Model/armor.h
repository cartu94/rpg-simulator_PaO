#ifndef ARMOR_H
#define ARMOR_H
#include "item.h"

class Armor : public Item
{
public:
    Armor(std::string n, int v, int def);
    virtual int calcDefence(int) const = 0;
    Armor* clone() const = 0;
    std::string getInfo() const;
    bool operator==(const Item& i) const override;
    int getDefence() const;

private:
    int defence;
};

#endif // ARMOR_H
