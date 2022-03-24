#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
private:
    std::string name;
    int value;

public:
    Item(std::string n, int v = 0);
    virtual ~Item() = default;

    virtual Item* clone() const = 0;
    std::string getName() const;
    int getValue() const;
    virtual std::string getInfo() const;
    virtual bool operator==(const Item& i) const;
};

#endif // ITEM_H
