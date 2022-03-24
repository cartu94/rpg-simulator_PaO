#ifndef ENEMYLISTITEM_H
#define ENEMYLISTITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include "Model/enemy.h"

class EnemyListItem : public QListWidgetItem
{
private:
    Enemy* item;
    QWidget* parent;

public:
    EnemyListItem(Enemy* e, QWidget* p = nullptr);
    ~EnemyListItem();
    Enemy* getItem();
};

#endif // ENEMYLISTITEM_H
