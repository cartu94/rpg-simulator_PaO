#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include "Model/item.h"

class ListItem : public QListWidgetItem
{
private:
    Item* item;
    QWidget* parent;

public:
    ListItem(Item* i, QWidget* p = nullptr);
    ~ListItem();
    Item* getItem();
};

#endif // LISTITEM_H
