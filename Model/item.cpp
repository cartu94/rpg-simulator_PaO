#include "item.h"

Item::Item(std::string n, int v): name(n), value(v) {}

std::string Item::getName() const { return name; }

int Item::getValue() const { return value; }

std::string Item::getInfo() const {
    std::string  s = "";
    return s.append("-" + getName() + "-").append("\nValue: " + std::to_string(getValue()));
}

bool Item::operator==(const Item &i) const {
    return name==i.getName() && value==i.getValue();
}
