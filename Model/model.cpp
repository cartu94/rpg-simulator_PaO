#include "model.h"

Model::Model(): character(new Character()), enemy(new Enemy("none", 0, 0, 0, 0, 0)) {}

Model::~Model() {
    delete character;
    delete enemy;
}

std::string Model::fight() {
    std::string s = "";
    int charDamage, enemyDamage;
    if(enemy->getName() == "none") return s.append("Enemy not set");

    if(character->getDexterity() >= enemy->getSpeed()){
        charDamage = enemy->getHit(character->calcDamage());
        s.append("\nYou deal " + std::to_string(charDamage) + " damage.");
        if(enemy->getHealth() > 0){
            enemyDamage = character->getHit(enemy->calcDamage());
            s.append("\n" + enemy->getName() + " deals you " + std::to_string(enemyDamage));
            if(character->getHealth() <= 0) {
                s.append("\nYou died.");
            }
        } else {
            s.append("\n" + enemy->getName() + " died.");
        }
    } else {
        enemyDamage = character->getHit(enemy->calcDamage());
        s.append("\n" + enemy->getName() + " deals you " + std::to_string(enemyDamage));
        if(character->getHealth() > 0){
            charDamage = enemy->getHit(character->calcDamage());
            s.append("\nYou deal " + std::to_string(charDamage) + " damage.");
            if(enemy->getHealth() <= 0) {
                s.append("\n" + enemy->getName() + " died.");
            }
        } else {
            s.append("\nYou died.");
        }
    }
    s.append("\n\nYour HP: " + std::to_string(character->getHealth()) + "\nEnemy HP: " + std::to_string(enemy->getHealth()));
    return s;
}

Character* Model::getCharacter() const
{
    return character;
}

Enemy* Model::getEnemy() const
{
    return enemy;
}

void Model::setEnemy(Enemy* value)
{
    enemy = value;
}
