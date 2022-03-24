#include "enemylistitem.h"

EnemyListItem::EnemyListItem(Enemy *e, QWidget *p): item(e), parent(p) {
    setText(QString::fromStdString(item->getInfo()));
}

EnemyListItem::~EnemyListItem() {
    delete item;
}

Enemy* EnemyListItem::getItem() {
    return item;
}
