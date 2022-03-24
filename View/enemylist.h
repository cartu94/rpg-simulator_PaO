#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include <QWidget>
#include <QListWidget>
#include "enemylistitem.h"

class EnemyList : public QListWidget
{
private:
    Q_OBJECT
    QWidget* parent;

public:
    EnemyList(QWidget* p = nullptr);
    EnemyListItem* currentItem() const;

public slots:
    void removeItem(QListWidgetItem* i);
};

#endif // ENEMYLIST_H
