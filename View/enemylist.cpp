#include "enemylist.h"

EnemyList::EnemyList(QWidget *p): parent(p) {
    setSpacing(10);
}

EnemyListItem *EnemyList::currentItem() const {
    return static_cast<EnemyListItem*>(QListWidget::currentItem());
}

void EnemyList::removeItem(QListWidgetItem *i) {
    removeItemWidget(i);
    delete i;
}
