#include "listitem.h"

ListItem::ListItem(Item *i, QWidget *p): item(i), parent(p) {
    setText(QString::fromStdString(item->getInfo()));
}

ListItem::~ListItem() {
    delete item;
}

Item* ListItem::getItem() {
    return item;
}
