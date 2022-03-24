#include "list.h"

List::List(QWidget *p): parent(p) {
    setSpacing(10);
}

ListItem *List::currentItem() const {
    return static_cast<ListItem*>(QListWidget::currentItem());
}

void List::removeItem(QListWidgetItem *i) {
    removeItemWidget(i);
    delete i;
}
