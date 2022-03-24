#ifndef MODEL_H
#define MODEL_H

#include "dlist.h"
#include "character.h"
#include "enemy.h"

class Model
{
public:
    Model();
    ~Model();
    std::string fight();

    Character* getCharacter() const;

    Enemy* getEnemy() const;
    void setEnemy(Enemy* value);

private:
    Character* character;
    Enemy* enemy;
};

#endif // MODEL_H
