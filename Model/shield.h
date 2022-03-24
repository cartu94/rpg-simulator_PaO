#ifndef SHIELD_H
#define SHIELD_H
#include "armor.h"

class Shield : public Armor
{
public:
    Shield(std::string n, int v, int def);

    int calcDefence(int dex = 0) const;
    Shield* clone() const;
    std::string getInfo() const;
    virtual bool operator==(const Item& i) const override;
};

#endif // SHIELD_H
