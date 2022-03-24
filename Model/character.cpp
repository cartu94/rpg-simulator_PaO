#include "character.h"

Character::Character(): equip(new DList<DeepPtr<Item>>), money(50), statPoints(25), strength(0), dexterity(0), health(50) {}

int Character::getMoney() const { return money; }
void Character::addMoney(int value) {
    money = money + value >= 0 ? money + value : 0;
}

int Character::getStatPoints() const { return statPoints; }
int Character::getStrength() const { return strength; }
int Character::getDexterity() const { return dexterity; }
int Character::getHealth() const { return health; }

void Character::setStatPoints(int value) { statPoints = value; }
void Character::setStrength(int value) { strength = value; }
void Character::setDexterity(int value) { dexterity = value; }
void Character::setHealth(int value) { health = value; }

int Character::getHit(int dmg) {
    int damage = dmg - calcDefence() > 0 ? dmg - calcDefence() : 0;
    health -= damage;
    return damage;
}

int Character::calcDamage() const {
    int damage = 0;
    for(DList<DeepPtr<Item>>::Iterator it = equip->begin(); it != equip->end(); ++it){
        if(dynamic_cast<LightWeapon*>(it->get())){
            damage += dynamic_cast<Weapon*>(it->get())->calcDamage(dexterity);
        } else if(dynamic_cast<MediumWeapon*>(it->get()) || dynamic_cast<HeavyWeapon*>(it->get())){
            damage += dynamic_cast<Weapon*>(it->get())->calcDamage(strength);
        }
    }
    return damage;
}

int Character::calcDefence() const {
    int defence = 0;
    for(DList<DeepPtr<Item>>::Iterator it = equip->begin(); it != equip->end(); ++it){
        if(dynamic_cast<LightArmor*>(it->get()) || dynamic_cast<MediumArmor*>(it->get()) || dynamic_cast<Shield*>(it->get())){
            defence += dynamic_cast<Armor*>(it->get())->calcDefence(dexterity);
        } else if(dynamic_cast<HeavyArmor*>(it->get())){
            defence += dynamic_cast<Armor*>(it->get())->calcDefence(strength);
        }
    }
    return defence;
}

int Character::addEquip(Item &item) {
    if(item.getValue() <= getMoney()) {
        if(dynamic_cast<Shield*>(&item)) {
            if(countTypeOf<Weapon>() > 1 || countTypeOf<HeavyWeapon>() > 0 || countTypeOf<Shield>() > 0) {
                return -1;
            }
        } else if(dynamic_cast<Armor*>(&item)) {
            if(countTypeOf<LightArmor>() > 0 || countTypeOf<MediumArmor>() > 0 || countTypeOf<HeavyArmor>()) {
                return -2;
            }
        }
        else if(dynamic_cast<HeavyWeapon*>(&item)) {
            if(countTypeOf<Weapon>() > 0 || countTypeOf<Shield>() > 0){
                return -3;
            }
        } else if(dynamic_cast<MediumWeapon*>(&item)) {
            if(countTypeOf<Weapon>() > 0){
                return -4;
            }
        } else if(dynamic_cast<LightWeapon*>(&item)) {
            if(countTypeOf<LightWeapon>() > 1 || countTypeOf<MediumWeapon>() > 0 || countTypeOf<HeavyWeapon>() > 0
                    || (countTypeOf<Weapon>() > 0 && countTypeOf<Shield>() > 0)) {
                return -5;
            }
        }
        equip->pushBack(&item);
        addMoney(-item.getValue());
        return 1;
    }
    return 0;
}

bool Character::removeEquip(Item &item) {
    bool found = false;
    for(DList<DeepPtr<Item>>::Iterator it = equip->begin(); it != equip->end() && !found; ++it) {
        if(*(it->get()) == item) {
            int i = equip->findIndex(it->get());
            if(i >= 0) {
                addMoney(item.getValue());
                equip->popIndex(i);
                found = true;
            }
        }
    }
    return found;
}

DList<DeepPtr<Item>> *Character::getEquip() const {
    return equip;
}

template<class T>
int Character::countTypeOf() const {
    int count = 0;
    for(DList<DeepPtr<Item>>::Iterator it = equip->begin(); it != equip->end(); ++it) {
        if(dynamic_cast<T*>(it->get())) count++;
    }
    return count;
}
